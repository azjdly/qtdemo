#ifndef MODBUSWORKER_H
#define MODBUSWORKER_H

#include <QObject>
#include <QModbusRtuSerialMaster>
#include <QSerialPort>
#include <QVariant>  // 必须添加
#include <QMap>
#include <QString>
class ModbusWorker : public QObject
{
    Q_OBJECT
public:
    explicit ModbusWorker(QObject *parent = nullptr);
    ~ModbusWorker();


public slots:
    void connectToDevice( QMap<QString,QVariant> settings); // 连接设备
    void disconnectToDevice(); // 断开连接
    void onModbusStateChanged(QModbusDevice::State state);
    void onModbusErrorOccurred(QModbusDevice::Error error);
    void modbusSend(int slaveAddress, int startAddress, int quantity, QString functionCode, QVector<uint16_t> values);
signals:
    void    workFinished();
    void    modbusConnected(QString portName);
    void    modbusDisconnected();
    void    receiveCorrect(QString data);
    void   receiverError(QString data);

private:

    QModbusRtuSerialMaster *modbusMaster = nullptr;
};

#endif // MODBUSWORKER_H
