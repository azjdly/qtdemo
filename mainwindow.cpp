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
#include <QCheckBox>




void MainWindow::applySavedQSS()
{
    QSettings settings("MyApp", "StyleConfig");

    // 先检查是否已有 `qssConfig`
    if (!settings.contains("qssConfig")) {
        settings.setValue("qssConfig", "blue"); // 如果没有，就初始化为 `blue`
    }

    // 获取当前配置的 QSS 样式名
    QString qssConfig = settings.value("qssConfig").toString();

    // 确保 `styleSheets` 中存在该样式
    if (!styleSheets.contains(qssConfig)) {
        qDebug() << "错误: QMap 中没有找到样式：" << qssConfig;
        return;
    }

    // 从 QMap 获取 QSS 文件路径
    QString qssPath = styleSheets[qssConfig];

    // 读取 QSS 文件并应用样式
    QFile file(qssPath);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        qApp->setStyleSheet(styleSheet);
        file.close();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    applySavedQSS();
    QList<QString> styleList = styleSheets.keys();
    m_stylemenu=new stylemenu(nullptr,styleList);
    connect(m_stylemenu,&stylemenu::changeStyle,this,&MainWindow::changeStyle);


    ui->comDisconnect->setDisabled(true);
    modbusThread=new QThread;
    modbusWork=new ModbusWorker;
    modbusWork->moveToThread(modbusThread);
    QObject::connect(this, &MainWindow::modbusConnect, modbusWork, &ModbusWorker::connectToDevice);
    QObject::connect(this, &MainWindow::modbusDisconnect, modbusWork, &ModbusWorker::disconnectToDevice);
    QObject::connect(modbusWork, &ModbusWorker::workFinished, modbusThread, &QThread::quit);
    QObject::connect(modbusWork, &ModbusWorker::workFinished, modbusWork, &ModbusWorker::deleteLater);
    QObject::connect(modbusThread, &QThread::finished, modbusThread, &QThread::deleteLater);
    QObject::connect(this, &MainWindow::modbusSend, modbusWork, &ModbusWorker::modbusSend);
    QObject::connect(modbusWork,&ModbusWorker::modbusConnected,this,[=](QString portName){
        ui->comConnect->setDisabled(true);
        ui->comDisconnect->setDisabled(false);
        ui->cycleCheck->setDisabled(false);
        ui->singleBtn->setDisabled(false);
        ui->comStateLabel->setText(portName+"已连接");


    });
    QObject::connect(modbusWork,&ModbusWorker::modbusDisconnected,this,[=](){

        ui->comConnect->setDisabled(false);
        ui->comDisconnect->setDisabled(true);
        ui->cycleCheck->setCheckState(Qt::Unchecked);
        ui->cycleCheck->setDisabled(true);
        ui->singleBtn->setDisabled(true);
        ui->comStateLabel->setText("未连接");
    });
    QObject::connect(modbusWork,&ModbusWorker::receiveCorrect,this,[=](QString data){
        QString currentTimeStr = QDateTime::currentDateTime().toString("hh:mm::ss");
        ui->modbusText->append(currentTimeStr + ":" +data);

    });
    QObject::connect(modbusWork,&ModbusWorker::receiverError,this,[=](QString data){
        QString currentTimeStr = QDateTime::currentDateTime().toString("hh:mm::ss");
        ui->modbusText->append(currentTimeStr + ":" +data);
    });
    modbusThread->start();
    modbusTimer = new QTimer(this);
    connect(modbusTimer, &QTimer::timeout, this, [=](){
        for (const ModbusData &task : modbuslist) {
            emit modbusSend(task.slaveAddress, task.startAddress, task.quantity, task.functionCode, task.values);
        }
    });








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




    taskListModel = new QStringListModel(this);
    ui->taskList->setModel(taskListModel);


    qBtnGroup();
    timeShow();
    qSplitterConfig();
    comConfig();
    setMouseTracking(true); // 让窗口在鼠标移动时触发 mouseMoveEvent()

    this->setMinimumSize(300, 200);

#ifdef Q_OS_WIN
    qDebug() << "当前系统是 Windows!";
#else
    qDebug() << "当前系统不是 Windows!";
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_rightMenuAnimation;
    delete m_stylemenu;
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
            RECT frame = { 0, 0, 0, 0};
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    if ( m_stylemenu->isVisible()) {
        m_stylemenu->close(); // 关闭子窗口
    }
    event->accept(); // 继续主窗口关闭流程
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

QVector<uint16_t> MainWindow::parseRegisterValues(const QString &hexString)
{
    QVector<uint16_t> values;
    QStringList hexList = hexString.split(" "); // 以空格分隔多个值

    for (const QString &hex : hexList) {
        bool ok;
        uint16_t value = static_cast<uint16_t>(hex.toUShort(&ok, 16)); // 转换为 16-bit 十六进制数
        if (ok) {
            values.append(value);
        }
    }
    return values;
}


void MainWindow::on_comDisconnect_clicked()
{
    emit modbusDisconnect();
}


void MainWindow::on_addTaskBtn_clicked() {
    int slaveAddress = ui->slaveAddress->value();
    int startAddress = ui->startAddress->value();
    int quantity = ui->coils->value();
    QString functionCode = ui->functionCode->currentText();
    QString registerValue = ui->regInput->text();

    // 校验输入数据范围
    if (slaveAddress < 1 || slaveAddress > 247 ||
        startAddress < 0 || startAddress > 65535 ||
        quantity < 1 || quantity > 125) {
        QMessageBox::warning(this, "错误", "输入参数超出合法范围");
        return;
    }

    // 仅当功能码为写入类型时才解析寄存器值
    QVector<uint16_t> parsedValues;
    if (functionCode == "0x05" || functionCode == "0x06" || functionCode == "0x0f" || functionCode == "0x10") {
        parsedValues = parseRegisterValues(registerValue);
        if (parsedValues.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入正确的十六进制值");
            return;
        }
    }

    // 存入任务列表
    ModbusData newTask = {slaveAddress, startAddress, quantity, functionCode, parsedValues};
    modbuslist.append(newTask);

    // 更新 QListView
    QStringList taskList = taskListModel->stringList();
    taskList.append(QString("设备: %1 | 地址: %2 | 数量: %3 | 功能码: %4")
                        .arg(slaveAddress)
                        .arg(startAddress)
                        .arg(quantity)
                        .arg(functionCode));

    taskListModel->setStringList(taskList); // 更新模型

    QMessageBox::information(this, "成功", "任务已添加");

}






void MainWindow::on_functionCode_currentIndexChanged(int index) {
    // 获取当前选中的功能码
    QString functionCode = ui->functionCode->itemText(index);

    // 需要输入寄存器值的功能码（写操作）
    QStringList writeFunctionCodes = {"0x05", "0x06", "0x0f", "0x10"};

    if (writeFunctionCodes.contains(functionCode)) {
        ui->regInput->clear();
        ui->regInput->setEnabled(true);  // 启用输入框
    } else {
        ui->regInput->setEnabled(false);  // 仍然允许输入，但清空内容
        ui->regInput->clear();           // 清空旧数据
    }
}


void MainWindow::on_deleteTaskBtn_clicked() {
    QModelIndex index = ui->taskList->currentIndex(); // 获取选中项索引
    if (!index.isValid()) {
        QMessageBox::warning(this, "错误", "请先选择要删除的任务");
        return;
    }

    // 删除 QListView 里的项
    QStringList taskList = taskListModel->stringList();
    taskList.removeAt(index.row());
    taskListModel->setStringList(taskList);

    // 删除 QList<ModbusData> 里的对应项
    if (index.row() < modbuslist.size()) {
        modbuslist.removeAt(index.row());
    }

    QMessageBox::information(this, "成功", "任务已删除");
}



void MainWindow::on_cycleCheck_stateChanged(int arg1)
{
    if (ui->cycleCheck->checkState() == Qt::Checked)
    {
        // 选中了 checkbox，启动定时器
        modbusTimer->setInterval(ui->spinBox->value()); // 例如每秒触发一次
        modbusTimer->start();
        qDebug() << "定时器已启动";
    }
    else
    {
        // 未选中 checkbox，关闭定时器
        modbusTimer->stop();
        qDebug() << "定时器已关闭";
    }
}




void MainWindow::on_cleanBtn_clicked()
{
    ui->modbusText->clear();
}


void MainWindow::on_singleBtn_clicked()
{
    int slaveAddress = ui->slaveAddress->value();
    int startAddress = ui->startAddress->value();
    int quantity = ui->coils->value();
    QString functionCode = ui->functionCode->currentText();
    QString registerValue = ui->regInput->text();

    // 校验输入数据范围
    if (slaveAddress < 1 || slaveAddress > 247 ||
        startAddress < 0 || startAddress > 65535 ||
        quantity < 1 || quantity > 125) {
        QMessageBox::warning(this, "错误", "输入参数超出合法范围");
        return;
    }

    // 仅当功能码为写入类型时才解析寄存器值
    QVector<uint16_t> parsedValues;
    if (functionCode == "0x05" || functionCode == "0x06" || functionCode == "0x0f" || functionCode == "0x10") {
        parsedValues = parseRegisterValues(registerValue);
        if (parsedValues.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入正确的十六进制值");
            return;
        }
    }
    emit modbusSend(slaveAddress,startAddress,quantity,functionCode,parsedValues);
}

void MainWindow::on_QssBtn_clicked()
{
    if (m_stylemenu->isVisible()) {
        m_stylemenu->hide();
    } else {
        // 1. 设置菜单大小（按主窗口比例）

        int menuWidth = this->width()/3;
        int menuHeight = this->height()/6;
        m_stylemenu->resize(menuWidth, menuHeight);

        // 2. 获取主窗口的全局中心点
        QRect mainWindowRect = this->frameGeometry(); // 包含窗口装饰（标题栏等）
        QPoint mainWindowCenter = mainWindowRect.center();

        // 3. 计算菜单的左上角坐标（使菜单中心对齐主窗口中心）
        int menuX = mainWindowCenter.x() - menuWidth / 2;
        int menuY = mainWindowCenter.y() - menuHeight / 2;

        // 4. 移动到全局坐标
        m_stylemenu->move(menuX, menuY);
        m_stylemenu->show();
    }
}
void MainWindow::changeStyle(QString style)
{

    // 确保 `styleSheets` 里存在该样式
    if (!styleSheets.contains(style)) {
        return;
    }

    // 获取对应的 QSS 路径
    QString qssPath = styleSheets[style];

    // 读取 QSS 文件并应用样式
    QFile file(qssPath);
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        qApp->setStyleSheet(styleSheet);
        file.close();

        // **存储用户选择到 `QSettings`**
        QSettings settings("MyApp", "StyleConfig");
        settings.setValue("qssConfig", style);
    }
}

