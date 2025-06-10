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
        modbusMaster=new QModbusRtuSerialMaster;
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
        emit modbusDisconnected();
        qDebug()<<"设备关闭成功";

    }
}


