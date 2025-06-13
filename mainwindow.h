#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVariantAnimation>
#include "qcustomplot.h"
#include <QSerialPort>
#include <windows.h>
#include <dbt.h>
#include "modbusworker.h"
#include <QWindow>
#include <windowsx.h>
#include <dwmapi.h>
#include <QVector>
#include <QSettings>
#include "stylemenu.h"
#include <QMqttClient>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    struct ModbusData {
        int slaveAddress;         // 从站地址
        int startAddress;         // 起始地址
        int quantity;             // 读取/写入的寄存器数量
        QString functionCode;     // 功能码
        QVector<uint16_t> values; // 16-bit 数据存储 (适用于 Modbus)
    };
    QMap<QString, QString> styleSheets = {
        {"blue", ":/myqss/style/stylesheetBlue.qss"},
        {"dark", ":/myqss/style/stylesheetDark.qss"}
    };

    void applySavedQSS();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void qBtnGroup();
    void timeShow();
    void qSplitterConfig();
    void comConfig();
    void animateStackWidgetChange(int newIndex);

private slots:
    void on_CloseBtn_clicked();

    void on_MaxBtn_clicked();

    void on_MinBtn_clicked();

    void on_toolBtn_clicked();

    void on_idBtn_clicked();

    void on_comConnect_clicked();
    void on_comDisconnect_clicked();

    void on_addTaskBtn_clicked();



    void on_functionCode_currentIndexChanged(int index);

    void on_deleteTaskBtn_clicked();

    void on_cycleCheck_stateChanged(int arg1);


    void on_cleanBtn_clicked();

    void on_singleBtn_clicked();

    void on_QssBtn_clicked();

    void changeStyle(QString style);

    void on_mqttConnectBtn_clicked();

    void onMqttConnected();
    void onMqttDisconnected();
    void onSubscriptionSuccess(const QMqttTopicFilter &topic);
    void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void on_mqttSubBtn_clicked();

    void on_deleteSubButton_clicked();

    void on_mqttPubBtn_clicked();

signals:
void     modbusConnect( QMap<QString,QVariant> settings);
void     modbusDisconnect();
void     modbusSend(int slaveAddress, int startAddress, int quantity, QString functionCode, QVector<uint16_t> values);
protected:
    bool eventFilter(QObject *watched, QEvent *event)override;
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override; // 双击事件
    void leaveEvent(QEvent *event)override;
    bool event(QEvent *event)override;
    void closeEvent(QCloseEvent *event) override;

private:
    void updateSerialPorts();
    QVector<uint16_t> parseRegisterValues(const QString &hexString);
    Ui::MainWindow *ui;
    QVariantAnimation *m_rightMenuAnimation;
    QList<QCustomPlot *> m_plots;
    QSerialPort * m_serial;
    QThread *modbusThread;
    ModbusWorker *modbusWork;
    int m_nBorderWidth = 5;
    QList< ModbusData>modbuslist;
    QStringListModel *taskListModel;
    QTimer *modbusTimer;
    stylemenu *m_stylemenu;
    QMqttClient * m_mqttclient=nullptr;
    QMap<QString, QMqttSubscription*> m_subscriptions;


};
#endif // MAINWINDOW_H
