#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QTimer>
#include <QTime>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QList>
#include "myplot.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QRegularExpression>  // 确保包含头文件
#include <QScreen>
#include <QHoverEvent>
#include "modbusworker.h"
#include <QThread>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comDisconnect->setDisabled(true);
    modbusThread=new QThread;
    modbusWork=new ModbusWorker;
    modbusWork->moveToThread(modbusThread);
    QObject::connect(this, &MainWindow::modbusConnect, modbusWork, &ModbusWorker::connectToDevice);
    QObject::connect(this, &MainWindow::modbusDisconnect, modbusWork, &ModbusWorker::disconnectToDevice);
    QObject::connect(modbusWork, &ModbusWorker::workFinished, modbusThread, &QThread::quit);
    QObject::connect(modbusWork, &ModbusWorker::workFinished, modbusWork, &ModbusWorker::deleteLater);
    QObject::connect(modbusThread, &QThread::finished, modbusWork, &QThread::deleteLater);
    QObject::connect(modbusWork,&ModbusWorker::modbusConnected,this,[=](QString portName){
        ui->comConnect->setDisabled(true);
        ui->comDisconnect->setDisabled(false);
        ui->comStateLabel->setText(portName+"已连接");
    });
    QObject::connect(modbusWork,&ModbusWorker::modbusDisconnected,this,[=](){

        ui->comConnect->setDisabled(false);
        ui->comDisconnect->setDisabled(true);
        ui->comStateLabel->setText("未连接");
    });
    modbusThread->start();

    m_rightMenuAnimation=new QVariantAnimation;
    m_rightMenuAnimation->setEasingCurve(QEasingCurve::InOutQuad);

    QGridLayout *layout = new QGridLayout(ui->gridtest);
     //| Qt::FramelessWindowHint
     this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    DwmEnableComposition(DWM_EC_ENABLECOMPOSITION); // windows7 need disable.
    HWND hwnd = reinterpret_cast<HWND>(winId());
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
    // add window shadow.
    const MARGINS shadow = { 1, 1, 1, 1 };
    DwmExtendFrameIntoClientArea(HWND(winId()), &shadow);




    QIntValidator *validator = new QIntValidator(0, 99999, this); // 只允许 0-99999
    ui->sendCycle->setValidator(validator);

    qBtnGroup();
    timeShow();
    qSplitterConfig();
    comConfig();
    setMouseTracking(true); // 让窗口在鼠标移动时触发 mouseMoveEvent()

    this->setMinimumSize(300, 200);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_rightMenuAnimation;
}

void MainWindow::qBtnGroup()
{
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->setExclusive(true);  // 设置互斥模式


    buttonGroup->addButton(ui->startBtn, 0); // 关联 ID
    buttonGroup->addButton(ui->plotBtn, 1);
    buttonGroup->addButton(ui->networkBtn, 2);
    buttonGroup->addButton(ui->modbusBtn,3);
    connect(buttonGroup, &QButtonGroup::idClicked, this,[=](int id){
        animateStackWidgetChange(id);
    });


}

void MainWindow::timeShow()
{

    QTimer *timer = new QTimer(this);
     ui->timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
    connect(timer, &QTimer::timeout, [=]() {
        ui->timeLabel->setText(QTime::currentTime().toString("hh:mm:ss"));
    });

    timer->start(1000); // 每秒更新一次

}

void MainWindow::qSplitterConfig()
{
    ui->splitter->setSizes({ui->splitter->width(), 0});
    ui->rightMenu->hide();
    connect(ui->splitter, &QSplitter::splitterMoved, this, [=](int pos, int index) {
        int rightSize = ui->splitter->sizes()[1]; // 获取右侧控件的大小
        if (rightSize == 1) {
            ui->rightMenu->hide(); // 当大小变为 1 时隐藏
        }
    });

}

void MainWindow::comConfig()
{
    m_serial=new QSerialPort(this);
    updateSerialPorts();

}

void MainWindow::animateStackWidgetChange(int newIndex)
{
    QWidget *currentWidget = ui->mainStack->currentWidget(); // 当前页面
    QWidget *nextWidget = ui->mainStack->widget(newIndex);  // 新页面

    if (!currentWidget || !nextWidget || currentWidget == nextWidget)
        return;

    int widgetHeight = ui->mainStack->height();  // 获取 StackWidget 的高度
    nextWidget->resize(currentWidget->size());
    currentWidget->move(0,0);
    // 让新页面从屏幕底部准备进入
    nextWidget->move(0, widgetHeight);
    nextWidget->show();

    // **动画1：当前页面上滑消失**
    QPropertyAnimation *exitAnimation = new QPropertyAnimation(currentWidget, "pos");
    exitAnimation->setDuration(100);
    exitAnimation->setStartValue(QPoint(0, 0));
    exitAnimation->setEndValue(QPoint(0, -widgetHeight));  // 滑出屏幕顶部
    exitAnimation->setEasingCurve(QEasingCurve::OutQuad);

    // **动画2：新页面从下滑入**
    QPropertyAnimation *enterAnimation = new QPropertyAnimation(nextWidget, "pos");
    enterAnimation->setDuration(100);
    enterAnimation->setStartValue(QPoint(0, widgetHeight)); // 开始位置（屏幕下方）
    enterAnimation->setEndValue(QPoint(0, 0));  // 终点位置（正常显示）
    enterAnimation->setEasingCurve(QEasingCurve::OutQuad);

    // **动画完成后切换页面**
    connect(enterAnimation, &QPropertyAnimation::finished, this, [=]() {
        ui->mainStack->setCurrentIndex(newIndex);
    });

    // **同时启动两个动画**
    exitAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    enterAnimation->start(QAbstractAnimation::DeleteWhenStopped);


}

void MainWindow::on_CloseBtn_clicked()
{
    this->close();
}


void MainWindow::on_MaxBtn_clicked()
{
    if (this->isMaximized()) {
        this->showNormal(); // 如果窗口已最大化，则恢复正常大小
    } else {
        this->showMaximized(); // 如果窗口未最大化，则最大化窗口
    }
}


void MainWindow::on_MinBtn_clicked()
{
    this->showMinimized();

}


void MainWindow::on_toolBtn_clicked()
{
    if(ui->rightMenu->isVisible())
    {

        if(m_rightMenuAnimation->state() == QAbstractAnimation::Running)
        {
            int start=m_rightMenuAnimation->startValue().toInt();
            int end=m_rightMenuAnimation->endValue().toInt();
            int totalWidth=ui->splitter->width();
            if(start > end)
            {
                m_rightMenuAnimation->stop();
                int currentValue=m_rightMenuAnimation->currentValue().toInt();
                m_rightMenuAnimation->setStartValue(currentValue);
                m_rightMenuAnimation->setEndValue(totalWidth/4);
                disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
                connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                    int rightsize=value.toInt();
                    ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                });
                m_rightMenuAnimation->start();
            }
            else
            {
                m_rightMenuAnimation->stop();
                int currentValue=m_rightMenuAnimation->currentValue().toInt();
                m_rightMenuAnimation->setStartValue(currentValue);
                m_rightMenuAnimation->setEndValue(0);
                disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
                connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                    int rightsize=value.toInt();
                    ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                    if(rightsize == 0)
                    {
                        ui->rightMenu->hide();
                    }

                });
                 m_rightMenuAnimation->start();
            }
        }
        else
        {
            int leftsize=ui->splitter->sizes()[0];
            int totalWidth=ui->splitter->width();
            m_rightMenuAnimation->setDuration(300);
            m_rightMenuAnimation->setStartValue(totalWidth - leftsize);
            m_rightMenuAnimation->setEndValue(0);

            disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
            connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                int rightsize=value.toInt();
                ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                if(rightsize == 0)
                {
                    ui->rightMenu->hide();
                }
            });
            m_rightMenuAnimation->start();
        }
    }
    else
    {

        int totalWidth = ui->splitter->width();
        m_rightMenuAnimation->setDuration(300);
        m_rightMenuAnimation->setStartValue(0);
        m_rightMenuAnimation->setEndValue(totalWidth/4);
        ui->rightMenu->show();
        ui->rightStack->setCurrentIndex(0);

        disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
        connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
            int rightsize=value.toInt();
            ui->splitter->setSizes({totalWidth-rightsize,rightsize});
        });
        m_rightMenuAnimation->start();
    }
}


void MainWindow::on_idBtn_clicked()
{
    if(ui->rightMenu->isVisible())
    {

        if(m_rightMenuAnimation->state() == QAbstractAnimation::Running)
        {
            int start=m_rightMenuAnimation->startValue().toInt();
            int end=m_rightMenuAnimation->endValue().toInt();
            int totalWidth=ui->splitter->width();
            if(start > end)
            {
                m_rightMenuAnimation->stop();
                int currentValue=m_rightMenuAnimation->currentValue().toInt();
                m_rightMenuAnimation->setStartValue(currentValue);
                m_rightMenuAnimation->setEndValue(totalWidth/4);
                disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
                connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                    int rightsize=value.toInt();
                    ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                });
                m_rightMenuAnimation->start();
            }
            else
            {
                m_rightMenuAnimation->stop();
                int currentValue=m_rightMenuAnimation->currentValue().toInt();
                m_rightMenuAnimation->setStartValue(currentValue);
                m_rightMenuAnimation->setEndValue(0);
                disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
                connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                    int rightsize=value.toInt();
                    ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                    if(rightsize == 0)
                    {
                        ui->rightMenu->hide();
                    }

                });
                m_rightMenuAnimation->start();
            }
        }
        else
        {
            int leftsize=ui->splitter->sizes()[0];
            int totalWidth=ui->splitter->width();
            m_rightMenuAnimation->setDuration(300);
            m_rightMenuAnimation->setStartValue(totalWidth - leftsize);
            m_rightMenuAnimation->setEndValue(0);

            disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
            connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
                int rightsize=value.toInt();
                ui->splitter->setSizes({totalWidth-rightsize,rightsize});
                if(rightsize == 0)
                {
                    ui->rightMenu->hide();
                }
            });
            m_rightMenuAnimation->start();
        }
    }
    else
    {

        int totalWidth = ui->splitter->width();
        m_rightMenuAnimation->setDuration(300);
        m_rightMenuAnimation->setStartValue(0);
        m_rightMenuAnimation->setEndValue(totalWidth/4);
        ui->rightMenu->show();
        ui->rightStack->setCurrentIndex(1);

        disconnect(m_rightMenuAnimation, nullptr, nullptr, nullptr);
        connect(m_rightMenuAnimation,&QVariantAnimation::valueChanged,this,[=](const QVariant &value){
            int rightsize=value.toInt();
            ui->splitter->setSizes({totalWidth-rightsize,rightsize});
        });
        m_rightMenuAnimation->start();
    }
}





void MainWindow::on_comConnect_clicked()
{
    QMap<QString,QVariant> settings;
    settings["portName"] = ui->comportBox->currentText();
    settings["baudRate"] = ui->baudrateBox->currentText().toInt();
    settings["dataBits"] = QVariant::fromValue(static_cast<QSerialPort::DataBits>(ui->databitBox->currentText().toInt()));

    QString parityText = ui->parityBox->currentText();
    if (parityText == "None") settings["parity"] = QVariant::fromValue(QSerialPort::NoParity);
    else if (parityText == "Even") settings["parity"] = QVariant::fromValue(QSerialPort::EvenParity);
    else if (parityText == "Odd") settings["parity"] = QVariant::fromValue(QSerialPort::OddParity);

    settings["stopBits"] = QVariant::fromValue(static_cast<QSerialPort::StopBits>(ui->stopbitsBox->currentText().toInt()));

    QString flowControlText = ui->flowcontrolBox->currentText();
    if (flowControlText == "None") settings["flowControl"] = QVariant::fromValue(QSerialPort::NoFlowControl);
    else if (flowControlText == "Hardware") settings["flowControl"] = QVariant::fromValue(QSerialPort::HardwareControl);
    else if (flowControlText == "Software") settings["flowControl"] = QVariant::fromValue(QSerialPort::SoftwareControl);

    emit modbusConnect(settings); // 发送信号
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    return QWidget::eventFilter(watched, event); // 继续传递事件
}









bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG *msg = static_cast<MSG *>(message);
     if(msg->message == WM_NCCALCSIZE)
     {
        if (msg->wParam == TRUE) {
             *result = 0;
             return true;
        }
     }
    if (msg->message == WM_DEVICECHANGE) {
        if (msg->wParam == DBT_DEVICEARRIVAL || msg->wParam == DBT_DEVICEREMOVECOMPLETE) {
            qDebug() << "Device change detected, updating COM ports...";
            updateSerialPorts();  // 设备插拔时更新串口列表
        }
    }
    if (msg->message == WM_NCHITTEST) {
        QScreen* screen = QGuiApplication::primaryScreen();
        qreal dpiScale = screen->devicePixelRatio();
        POINT pt = { GET_X_LPARAM(msg->lParam), GET_Y_LPARAM(msg->lParam) };
        QRect windowRect = this->geometry();
        int left = windowRect.x() * dpiScale;
        int top = windowRect.y() * dpiScale;
        int right = left + windowRect.width() * dpiScale;
        int bottom = top + windowRect.height() * dpiScale;
        int scaledBorderWidth = static_cast<int>(m_nBorderWidth * dpiScale);
        bool inLeft = (pt.x >= left && pt.x < left + scaledBorderWidth);
        bool inRight = (pt.x <= right && pt.x > right - scaledBorderWidth);
        bool inTop = (pt.y >= top && pt.y < top + scaledBorderWidth);
        bool inBottom = (pt.y <= bottom && pt.y > bottom - scaledBorderWidth);
        if (inLeft && inTop) {
            *result = HTTOPLEFT;
        }
        else if (inRight && inTop) {
            *result = HTTOPRIGHT;
        }
        else if (inLeft && inBottom) {
            *result = HTBOTTOMLEFT;
        }
        else if (inRight && inBottom) {
            *result = HTBOTTOMRIGHT;
        }
        else if (inLeft) {
            *result = HTLEFT;
        }
        else if (inRight) {
            *result = HTRIGHT;
        }
        else if (inTop) {
            *result = HTTOP;
        }
        else if (inBottom) {
            *result = HTBOTTOM;
        }
        else {
            QPoint globalPos=QCursor::pos();;
            QPoint localPos = ui->TitleWidget->mapFromGlobal(globalPos);

            // 检查鼠标是否在 TitleWidget 内（改为 rect().contains）
            if (ui->TitleWidget->rect().contains(localPos)) {

                QWidget* child = ui->TitleWidget->childAt(localPos);
                if (child && child->inherits("QPushButton")) {

                    *result = HTCLIENT;  // 不拖动，让按钮可点击
                    return true;
                }

                *result = HTCAPTION;  // 允许拖动窗口
                return true;
            }

            // 默认返回 HTCLIENT（客户区）
            *result = HTCLIENT;
            return true;

        }
        return true;
    }
    if(msg->message == WM_GETMINMAXINFO)
    {
        QScreen *screen = windowHandle()->screen();

        qreal m_dpiScale = screen->devicePixelRatio();
        if (::IsZoomed(msg->hwnd)) {
            RECT frame = { 0, 0, 0, 0 };
            AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
            frame.left = abs(frame.left);
            frame.top = abs(frame.bottom);
            this->setContentsMargins(int(frame.left / m_dpiScale), int(frame.top / m_dpiScale), int(frame.right / m_dpiScale), int(frame.bottom / m_dpiScale));
        }
        else {
            this->setContentsMargins(0, 0, 0, 0);
        }

        *result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
        return true;
    }
    return QWidget::nativeEvent(eventType, message, result);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // 检查鼠标是否在标题栏（TitleWidget）内
        if (ui->TitleWidget->rect().contains(ui->TitleWidget->mapFromGlobal(event->globalPos()))) {
            // if (ReleaseCapture()) {
            //     QWidget* pWindow = this->window();
            //     if (pWindow->isWindow()) {
            //         SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);
            //         return; // 已处理，不再传递事件
            //     }
            // }
             // if(windowHandle())
             // {
             //     windowHandle()->startSystemMove();
             // }
        }
    }
    QWidget::mousePressEvent(event); // 其他情况正常处理
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
}



void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // 检查双击是否在标题栏内
        if (ui->TitleWidget->rect().contains(ui->TitleWidget->mapFromGlobal(event->globalPos()))) {
            // 切换全屏/还原
            if (isMaximized()) {
                showNormal(); // 还原窗口
            } else {
                showMaximized(); // 最大化窗口（或使用 showFullScreen() 真正全屏）
            }
            return; // 阻止事件继续传递
        }
    }
    QMainWindow::mouseDoubleClickEvent(event); // 其他区域双击正常处理
}


void MainWindow::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
}

bool MainWindow::event(QEvent *event)
{
    return QWidget::event(event);
}






void MainWindow::updateSerialPorts()
{
    QStringList newPorts;

    // 获取所有可用串口，并存入列表
    for (const QSerialPortInfo &port : QSerialPortInfo::availablePorts()) {
        newPorts.append(port.portName());
    }

    // 按名称排序（保证 COM1, COM2, COM10 排序正确）
    std::sort(newPorts.begin(), newPorts.end(), [](const QString &a, const QString &b) {
        QRegularExpression reg("\\d+");  // 使用 QRegularExpression 代替 QRegExp
        QRegularExpressionMatch matchA = reg.match(a);
        QRegularExpressionMatch matchB = reg.match(b);

        if (matchA.hasMatch() && matchB.hasMatch()) {
            return matchA.captured(0).toInt() < matchB.captured(0).toInt();  // 比较数值大小
        }
        return a < b; // 默认字母排序
    });

    qDebug() << "已排序的串口：" << newPorts;

    // 记录当前选中的项
    QString currentSelection = ui->comportBox->currentText();

    // 更新 comboBox 的列表
    ui->comportBox->clear();
    ui->comportBox->addItems(newPorts);

    // 如果当前选项仍在列表中，保持不变，否则选择最大项
    if (newPorts.contains(currentSelection)) {
        ui->comportBox->setCurrentText(currentSelection);
    } else if (!newPorts.isEmpty()) {
        ui->comportBox->setCurrentText(newPorts.first()); // 选择最大项
    }
}


void MainWindow::on_comDisconnect_clicked()
{
    emit modbusDisconnect();
}


void MainWindow::on_addTaskBtn_clicked()
{
    // 获取各个参数
    int slaveAddress = ui->slaveAddress->value();
    int startAddress = ui->startAddress->value();
    int coils = ui->coils->value();
    QString functionCode = ui->functionCode->currentText();

}




void MainWindow::on_deleteBtn_clicked()
{

}

