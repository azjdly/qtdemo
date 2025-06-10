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
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    enum ResizeDirection {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        TOPLEFT,
        TOPRIGHT,
        BOTTOMLEFT,
        BOTTOMRIGHT
    };



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

    void on_deleteBtn_clicked();

signals:
    modbusConnect( QMap<QString,QVariant> settings);
    modbusDisconnect();

protected:
    bool eventFilter(QObject *watched, QEvent *event)override;
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override; // 双击事件
    void leaveEvent(QEvent *event)override;
    bool event(QEvent *event)override;
private:
    void updateSerialPorts();

    Ui::MainWindow *ui;
    QVariantAnimation *m_rightMenuAnimation;
    QList<QCustomPlot *> m_plots;
    QSerialPort * m_serial;
    QThread *modbusThread;
    ModbusWorker *modbusWork;
    int m_nBorderWidth = 5;

};
#endif // MAINWINDOW_H
