#include "modbusworker.h"
#include <QDebug>
#include <QMap>      // 确保包含QMap头文件
#include <QString>   // 确保包含QString头文件
#include <QVariant>

#include <QMetaType>
ModbusWorker::ModbusWorker(QObject *parent)
    : QObject{parent}
{
    qRegisterMetaType<QMap<QString,QVariant>>("QMap<QString,QVariant>");

}

ModbusWorker::~ModbusWorker()
{
    delete modbusMaster;
}

void ModbusWorker::connectToDevice( QMap<QString,QVariant> settings)
{
    if(modbusMaster == nullptr)
    {
        modbusMaster=new QModbusRtuSerialMaster;
        modbusMaster->setNumberOfRetries(0);
        modbusMaster->setTimeout(100);
        connect(modbusMaster, &QModbusRtuSerialMaster::stateChanged, this, &ModbusWorker::onModbusStateChanged);
        connect(modbusMaster, &QModbusRtuSerialMaster::errorOccurred, this,&ModbusWorker::onModbusErrorOccurred );
    }
    modbusMaster->setConnectionParameter(QModbusDevice::SerialPortNameParameter, settings["portName"].toString());
    modbusMaster->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, settings["baudRate"].toInt());
    modbusMaster->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, settings["dataBits"].value<QSerialPort::DataBits>());
    modbusMaster->setConnectionParameter(QModbusDevice::SerialParityParameter, settings["parity"].value<QSerialPort::Parity>());
    modbusMaster->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, settings["stopBits"].value<QSerialPort::StopBits>());

    if (!modbusMaster->connectDevice()) {
        qDebug() << "Modbus 设备连接失败!";

    } else if(modbusMaster->state() == QModbusDevice::ConnectedState) {
        qDebug() << "Modbus 设备连接成功!";
        emit modbusConnected(settings["portName"].toString());
    }

}

void ModbusWorker::disconnectToDevice()
{
    if(modbusMaster != nullptr)
    {
        modbusMaster->disconnectDevice();

        qDebug()<<"设备关闭成功";

    }
}

void ModbusWorker::onModbusStateChanged(QModbusDevice::State state) {
    switch (state) {
    case QModbusDevice::ConnectingState:
        qDebug() << "Modbus 正在连接...";
        break;
    case QModbusDevice::ConnectedState:

        break;
    case QModbusDevice::ClosingState:
        qDebug() << "Modbus 设备正在关闭...";
        break;
    case QModbusDevice::UnconnectedState:

        emit modbusDisconnected();
        qDebug() << "Modbus 设备已断开连接!";
        break;
    default:
        qDebug() << "未知状态";
    }
}

void ModbusWorker::onModbusErrorOccurred(QModbusDevice::Error error)
{
    qDebug() << "Modbus 发生错误：" << error;
    qDebug() <<modbusMaster->errorString() ;
    if (error == QModbusDevice::ConnectionError) {

        if (modbusMaster->errorString() == "Cannot open serial device due to permissions.")
        {
            qDebug() << modbusMaster->errorString() ;
            qDebug() << "可能是串口拔出了，尝试断开设备";
            modbusMaster->disconnectDevice();
        }
    }
}

void ModbusWorker::modbusSend(int slaveAddress, int startAddress, int quantity, QString functionCode, QVector<uint16_t> values)
{
    // 确保 Modbus 设备已连接
    if (!modbusMaster || modbusMaster->state() != QModbusDevice::ConnectedState) {
        qDebug() << "错误: Modbus 设备未连接!";
        return;
    }

    // 解析功能码
    QString codeStr = functionCode;
    bool ok;
    uint8_t funcCode = codeStr.remove("0x").toUInt(&ok, 16);
    if (!ok) {
        qDebug() << "错误: 无效的功能码 -> " << functionCode;
        return;
    }

    // 确定数据单元类型
    QModbusDataUnit::RegisterType regType;
    switch (funcCode) {
    case 0x01: regType = QModbusDataUnit::Coils; break;
    case 0x02: regType = QModbusDataUnit::DiscreteInputs; break;
    case 0x03: regType = QModbusDataUnit::HoldingRegisters; break;
    case 0x04: regType = QModbusDataUnit::InputRegisters; break;
    case 0x05: regType = QModbusDataUnit::Coils; break; // 写单个线圈
    case 0x06: regType = QModbusDataUnit::HoldingRegisters; break; // 写单个寄存器
    case 0x0F: regType = QModbusDataUnit::Coils; break; // 写多个线圈
    case 0x10: regType = QModbusDataUnit::HoldingRegisters; break; // 写多个寄存器
    default:
        qDebug() << "错误: 不支持的功能码 -> " << QString("0x%1").arg(funcCode, 2, 16, QLatin1Char('0'));
        return;
    }

    // 创建 Modbus 数据单元
    QModbusDataUnit unit(regType, startAddress, quantity);

    // 处理写操作
    if (funcCode == 0x05 || funcCode == 0x06) { // 写单个线圈或寄存器
        if (values.size() < 1) {
            qDebug() << "错误: 写入数据不足! 需要 1 个，但提供了" << values.size() << "个";
            return;
        }
        unit.setValue(0, values.at(0));
    }
    else if (funcCode == 0x0F || funcCode == 0x10) { // 写多个线圈或寄存器
        if (values.size() < quantity) {
            qDebug() << "错误: 写入数据不足! 需要" << quantity << "个，但提供了" << values.size() << "个";
            return;
        }
        for (int i = 0; i < quantity; ++i) {
            unit.setValue(i, values.at(i));
        }
    }

    // 发送请求
    QModbusReply *reply = nullptr;
    if (funcCode == 0x01 || funcCode == 0x02 || funcCode == 0x03 || funcCode == 0x04) {
        reply = modbusMaster->sendReadRequest(unit, slaveAddress);
    }
    else if (funcCode == 0x05 || funcCode == 0x06) {
        reply = modbusMaster->sendWriteRequest(unit, slaveAddress);
    }
    else if (funcCode == 0x0F || funcCode == 0x10) {
        reply = modbusMaster->sendWriteRequest(unit, slaveAddress);
    }

    // 失败处理
    if (!reply) {
        qDebug() << "错误: Modbus 请求发送失败!";
        return;
    }

    // 监听请求结果
    connect(reply, &QModbusReply::finished, this, [reply, funcCode, slaveAddress, this]() {
        if (reply->error() == QModbusDevice::NoError) {
            const QModbusDataUnit unit = reply->result();

            // 优化数据显示格式
            QString dataStr;
            const auto &values = unit.values();
            if (!values.isEmpty()) {
                dataStr = "[";
                for (int i = 0; i < values.size(); ++i) {
                    if (i > 0) dataStr += ",";
                    dataStr += QString("%1").arg(values.at(i), 0, 16); // 16进制显示
                }
                dataStr += "]";
            }

            QString logMessage = QString("成功***功能码:%1***设备地址:%2***数据:%3")
                                     .arg(funcCode, 2, 16, QLatin1Char('0'))  // 功能码16进制显示
                                     .arg(slaveAddress)                        // 从站地址
                                     .arg(dataStr);                             // 优化后的数据格式

            emit receiveCorrect(logMessage);
        } else {
            QString errorType;
            switch (reply->error()) {
            case QModbusDevice::TimeoutError: errorType = "超时"; break;
            case QModbusDevice::ProtocolError: errorType = "协议错误"; break;
            case QModbusDevice::ConnectionError: errorType = "连接错误"; break;
            default: errorType = QString::number(reply->error());
            }

            QString logMessage = QString("失败***功能码:%1***设备地址:%2***错误类型:%3:%4")
                                     .arg(funcCode, 2, 16, QLatin1Char('0'))
                                     .arg(slaveAddress)
                                     .arg(errorType)
                                     .arg(reply->errorString());

            emit receiverError(logMessage);

            // 特殊错误处理建议
            if (reply->error() == QModbusDevice::TimeoutError) {
                qDebug() << "超时建议: 检查从站地址/波特率/线路连接";
            }
        }
        reply->deleteLater();
    });
}


