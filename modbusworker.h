#ifndef MODBUSWORKER_H
#define MODBUSWORKER_H

#include <QObject>
#include <QModbusRtuSerialMaster>
#include <QSerialPort>
#include <QVariant>  // 必须添加
#include <QMap>

class ModbusWorker : public QObject
{
    Q_OBJECT
public:
    explicit ModbusWorker(QObject *parent = nullptr);
    ~ModbusWorker();


public slots:
    void connectToDevice( QMap<QString,QVariant> settings); // 连接设备
    void disconnectDevice(); // 断开连接

signals:
    workFinished();
private:
    QModbusRtuSerialMaster *modbusMaster = nullptr;
};

#endif // MODBUSWORKER_H
