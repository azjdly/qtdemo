/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "carouselwidget.h"
#include "mygrid.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *TitleWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *IconWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *IconBtn;
    QLabel *IconLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *SearchWidget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *BtnWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *QssBtn;
    QPushButton *MinBtn;
    QPushButton *MaxBtn;
    QPushButton *CloseBtn;
    QWidget *MainWidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *leftMenu;
    QVBoxLayout *verticalLayout_4;
    QFrame *menuFrame;
    QGridLayout *gridLayout;
    QToolButton *modbusBtn;
    QToolButton *plotBtn;
    QToolButton *startBtn;
    QToolButton *networkBtn;
    QSpacerItem *verticalSpacer;
    QFrame *toolFrame;
    QGridLayout *gridLayout_2;
    QToolButton *toolBtn;
    QToolButton *idBtn;
    QSplitter *splitter;
    QWidget *mainPage;
    QGridLayout *gridLayout_3;
    QStackedWidget *mainStack;
    CarouselWidget *startPage;
    QWidget *plotPage;
    QVBoxLayout *verticalLayout_2;
    MyGrid *gridtest;
    QWidget *networkPage;
    QGridLayout *gridLayout_5;
    QWidget *widget_10;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QSpinBox *spinBox_2;
    QLabel *label_14;
    QLineEdit *lineEdit_2;
    QLabel *label_15;
    QLineEdit *lineEdit_4;
    QWidget *widget_11;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QTextEdit *textEdit;
    QWidget *comPage;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_7;
    QGridLayout *gridLayout_12;
    QLabel *comStateLabel;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *comportLabel;
    QComboBox *comportBox;
    QLabel *baudrateLabel;
    QComboBox *baudrateBox;
    QLabel *databitLabel;
    QComboBox *databitBox;
    QLabel *parityLabel;
    QComboBox *parityBox;
    QLabel *stopbitsLabel;
    QComboBox *stopbitsBox;
    QLabel *flowcontrolLabel;
    QComboBox *flowcontrolBox;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *comConnect;
    QPushButton *comDisconnect;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_8;
    QGridLayout *gridLayout_7;
    QLabel *label;
    QTextEdit *modbusText;
    QLabel *label_10;
    QListView *taskList;
    QPushButton *cleanBtn;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    QSpinBox *slaveAddress;
    QSpinBox *startAddress;
    QLabel *label_7;
    QComboBox *functionCode;
    QLabel *label_9;
    QSpinBox *coils;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *regInput;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addTaskBtn;
    QPushButton *deleteTaskBtn;
    QPushButton *singleBtn;
    QLabel *label_11;
    QSpinBox *spinBox;
    QCheckBox *cycleCheck;
    QWidget *rightMenu;
    QGridLayout *gridLayout_4;
    QStackedWidget *rightStack;
    QWidget *toolPage;
    QGridLayout *gridLayout_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QWidget *idPage;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_13;
    QWidget *StatusWidget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *timeLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TitleWidget = new QWidget(centralwidget);
        TitleWidget->setObjectName("TitleWidget");
        horizontalLayout = new QHBoxLayout(TitleWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        IconWidget = new QWidget(TitleWidget);
        IconWidget->setObjectName("IconWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IconWidget->sizePolicy().hasHeightForWidth());
        IconWidget->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(IconWidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        IconBtn = new QPushButton(IconWidget);
        IconBtn->setObjectName("IconBtn");
        IconBtn->setEnabled(false);
        IconBtn->setMinimumSize(QSize(45, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/ufoW.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        IconBtn->setIcon(icon);

        horizontalLayout_4->addWidget(IconBtn);

        IconLabel = new QLabel(IconWidget);
        IconLabel->setObjectName("IconLabel");

        horizontalLayout_4->addWidget(IconLabel);


        horizontalLayout->addWidget(IconWidget);

        horizontalSpacer = new QSpacerItem(157, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        SearchWidget = new QWidget(TitleWidget);
        SearchWidget->setObjectName("SearchWidget");
        horizontalLayout_2 = new QHBoxLayout(SearchWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 3, 0, 3);

        horizontalLayout->addWidget(SearchWidget);

        BtnWidget = new QWidget(TitleWidget);
        BtnWidget->setObjectName("BtnWidget");
        horizontalLayout_3 = new QHBoxLayout(BtnWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        QssBtn = new QPushButton(BtnWidget);
        QssBtn->setObjectName("QssBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(QssBtn->sizePolicy().hasHeightForWidth());
        QssBtn->setSizePolicy(sizePolicy1);
        QssBtn->setMinimumSize(QSize(40, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/penW.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        QssBtn->setIcon(icon1);

        horizontalLayout_3->addWidget(QssBtn);

        MinBtn = new QPushButton(BtnWidget);
        MinBtn->setObjectName("MinBtn");
        sizePolicy1.setHeightForWidth(MinBtn->sizePolicy().hasHeightForWidth());
        MinBtn->setSizePolicy(sizePolicy1);
        MinBtn->setMinimumSize(QSize(40, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/minW.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MinBtn->setIcon(icon2);

        horizontalLayout_3->addWidget(MinBtn);

        MaxBtn = new QPushButton(BtnWidget);
        MaxBtn->setObjectName("MaxBtn");
        sizePolicy1.setHeightForWidth(MaxBtn->sizePolicy().hasHeightForWidth());
        MaxBtn->setSizePolicy(sizePolicy1);
        MaxBtn->setMinimumSize(QSize(40, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/maxW.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MaxBtn->setIcon(icon3);

        horizontalLayout_3->addWidget(MaxBtn);

        CloseBtn = new QPushButton(BtnWidget);
        CloseBtn->setObjectName("CloseBtn");
        sizePolicy1.setHeightForWidth(CloseBtn->sizePolicy().hasHeightForWidth());
        CloseBtn->setSizePolicy(sizePolicy1);
        CloseBtn->setMinimumSize(QSize(40, 0));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        CloseBtn->setIcon(icon4);

        horizontalLayout_3->addWidget(CloseBtn);


        horizontalLayout->addWidget(BtnWidget);


        verticalLayout->addWidget(TitleWidget);

        MainWidget = new QWidget(centralwidget);
        MainWidget->setObjectName("MainWidget");
        horizontalLayout_5 = new QHBoxLayout(MainWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        leftMenu = new QWidget(MainWidget);
        leftMenu->setObjectName("leftMenu");
        verticalLayout_4 = new QVBoxLayout(leftMenu);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        menuFrame = new QFrame(leftMenu);
        menuFrame->setObjectName("menuFrame");
        sizePolicy.setHeightForWidth(menuFrame->sizePolicy().hasHeightForWidth());
        menuFrame->setSizePolicy(sizePolicy);
        menuFrame->setFrameShape(QFrame::Shape::StyledPanel);
        menuFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(menuFrame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        modbusBtn = new QToolButton(menuFrame);
        modbusBtn->setObjectName("modbusBtn");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(modbusBtn->sizePolicy().hasHeightForWidth());
        modbusBtn->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon/com.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        modbusBtn->setIcon(icon5);
        modbusBtn->setCheckable(true);
        modbusBtn->setAutoExclusive(true);
        modbusBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout->addWidget(modbusBtn, 4, 0, 1, 1);

        plotBtn = new QToolButton(menuFrame);
        plotBtn->setObjectName("plotBtn");
        sizePolicy2.setHeightForWidth(plotBtn->sizePolicy().hasHeightForWidth());
        plotBtn->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/icon/Curves.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        plotBtn->setIcon(icon6);
        plotBtn->setCheckable(true);
        plotBtn->setChecked(false);
        plotBtn->setAutoExclusive(true);
        plotBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout->addWidget(plotBtn, 2, 0, 1, 1);

        startBtn = new QToolButton(menuFrame);
        startBtn->setObjectName("startBtn");
        sizePolicy2.setHeightForWidth(startBtn->sizePolicy().hasHeightForWidth());
        startBtn->setSizePolicy(sizePolicy2);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/icon/Hi.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        startBtn->setIcon(icon7);
        startBtn->setCheckable(true);
        startBtn->setChecked(true);
        startBtn->setAutoExclusive(true);
        startBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout->addWidget(startBtn, 0, 0, 1, 1);

        networkBtn = new QToolButton(menuFrame);
        networkBtn->setObjectName("networkBtn");
        sizePolicy2.setHeightForWidth(networkBtn->sizePolicy().hasHeightForWidth());
        networkBtn->setSizePolicy(sizePolicy2);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/icon/network.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        networkBtn->setIcon(icon8);
        networkBtn->setCheckable(true);
        networkBtn->setChecked(false);
        networkBtn->setAutoExclusive(true);
        networkBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout->addWidget(networkBtn, 3, 0, 1, 1);


        verticalLayout_4->addWidget(menuFrame);

        verticalSpacer = new QSpacerItem(20, 201, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        toolFrame = new QFrame(leftMenu);
        toolFrame->setObjectName("toolFrame");
        sizePolicy.setHeightForWidth(toolFrame->sizePolicy().hasHeightForWidth());
        toolFrame->setSizePolicy(sizePolicy);
        toolFrame->setFrameShape(QFrame::Shape::StyledPanel);
        toolFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(toolFrame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toolBtn = new QToolButton(toolFrame);
        toolBtn->setObjectName("toolBtn");
        sizePolicy2.setHeightForWidth(toolBtn->sizePolicy().hasHeightForWidth());
        toolBtn->setSizePolicy(sizePolicy2);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/icon/tool.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolBtn->setIcon(icon9);
        toolBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(toolBtn, 0, 0, 1, 1);

        idBtn = new QToolButton(toolFrame);
        idBtn->setObjectName("idBtn");
        sizePolicy2.setHeightForWidth(idBtn->sizePolicy().hasHeightForWidth());
        idBtn->setSizePolicy(sizePolicy2);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/icon/ID.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        idBtn->setIcon(icon10);
        idBtn->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(idBtn, 1, 0, 1, 1);


        verticalLayout_4->addWidget(toolFrame);

        verticalLayout_4->setStretch(0, 4);
        verticalLayout_4->setStretch(1, 3);
        verticalLayout_4->setStretch(2, 2);

        horizontalLayout_5->addWidget(leftMenu);

        splitter = new QSplitter(MainWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        splitter->setChildrenCollapsible(false);
        mainPage = new QWidget(splitter);
        mainPage->setObjectName("mainPage");
        sizePolicy.setHeightForWidth(mainPage->sizePolicy().hasHeightForWidth());
        mainPage->setSizePolicy(sizePolicy);
        mainPage->setMinimumSize(QSize(50, 0));
        gridLayout_3 = new QGridLayout(mainPage);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        mainStack = new QStackedWidget(mainPage);
        mainStack->setObjectName("mainStack");
        startPage = new CarouselWidget();
        startPage->setObjectName("startPage");
        mainStack->addWidget(startPage);
        plotPage = new QWidget();
        plotPage->setObjectName("plotPage");
        verticalLayout_2 = new QVBoxLayout(plotPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridtest = new MyGrid(plotPage);
        gridtest->setObjectName("gridtest");

        verticalLayout_2->addWidget(gridtest);

        verticalLayout_2->setStretch(0, 8);
        mainStack->addWidget(plotPage);
        networkPage = new QWidget();
        networkPage->setObjectName("networkPage");
        gridLayout_5 = new QGridLayout(networkPage);
        gridLayout_5->setObjectName("gridLayout_5");
        widget_10 = new QWidget(networkPage);
        widget_10->setObjectName("widget_10");
        formLayout_2 = new QFormLayout(widget_10);
        formLayout_2->setObjectName("formLayout_2");
        label_3 = new QLabel(widget_10);
        label_3->setObjectName("label_3");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, label_3);

        lineEdit = new QLineEdit(widget_10);
        lineEdit->setObjectName("lineEdit");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_13 = new QLabel(widget_10);
        label_13->setObjectName("label_13");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, label_13);

        spinBox_2 = new QSpinBox(widget_10);
        spinBox_2->setObjectName("spinBox_2");

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, spinBox_2);

        label_14 = new QLabel(widget_10);
        label_14->setObjectName("label_14");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::LabelRole, label_14);

        lineEdit_2 = new QLineEdit(widget_10);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        label_15 = new QLabel(widget_10);
        label_15->setObjectName("label_15");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::LabelRole, label_15);

        lineEdit_4 = new QLineEdit(widget_10);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_4);


        gridLayout_5->addWidget(widget_10, 0, 0, 1, 1);

        widget_11 = new QWidget(networkPage);
        widget_11->setObjectName("widget_11");
        verticalLayout_7 = new QVBoxLayout(widget_11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        pushButton = new QPushButton(widget_11);
        pushButton->setObjectName("pushButton");

        verticalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_11);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_7->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_11);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_7->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_11);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_7->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget_11);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout_7->addWidget(pushButton_5);


        gridLayout_5->addWidget(widget_11, 0, 1, 1, 1);

        widget_12 = new QWidget(networkPage);
        widget_12->setObjectName("widget_12");
        verticalLayout_9 = new QVBoxLayout(widget_12);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_16 = new QLabel(widget_12);
        label_16->setObjectName("label_16");

        verticalLayout_9->addWidget(label_16);

        textEdit = new QTextEdit(widget_12);
        textEdit->setObjectName("textEdit");

        verticalLayout_9->addWidget(textEdit);


        gridLayout_5->addWidget(widget_12, 1, 0, 1, 2);

        mainStack->addWidget(networkPage);
        comPage = new QWidget();
        comPage->setObjectName("comPage");
        horizontalLayout_8 = new QHBoxLayout(comPage);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(comPage);
        widget_4->setObjectName("widget_4");
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widget_4);
        widget_7->setObjectName("widget_7");
        gridLayout_12 = new QGridLayout(widget_7);
        gridLayout_12->setObjectName("gridLayout_12");
        comStateLabel = new QLabel(widget_7);
        comStateLabel->setObjectName("comStateLabel");
        comStateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_12->addWidget(comStateLabel, 0, 0, 1, 1);


        verticalLayout_5->addWidget(widget_7);

        widget = new QWidget(widget_4);
        widget->setObjectName("widget");
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        comportLabel = new QLabel(widget);
        comportLabel->setObjectName("comportLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, comportLabel);

        comportBox = new QComboBox(widget);
        comportBox->setObjectName("comportBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comportBox);

        baudrateLabel = new QLabel(widget);
        baudrateLabel->setObjectName("baudrateLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, baudrateLabel);

        baudrateBox = new QComboBox(widget);
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->addItem(QString());
        baudrateBox->setObjectName("baudrateBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, baudrateBox);

        databitLabel = new QLabel(widget);
        databitLabel->setObjectName("databitLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, databitLabel);

        databitBox = new QComboBox(widget);
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->setObjectName("databitBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, databitBox);

        parityLabel = new QLabel(widget);
        parityLabel->setObjectName("parityLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, parityLabel);

        parityBox = new QComboBox(widget);
        parityBox->addItem(QString());
        parityBox->addItem(QString());
        parityBox->addItem(QString());
        parityBox->setObjectName("parityBox");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, parityBox);

        stopbitsLabel = new QLabel(widget);
        stopbitsLabel->setObjectName("stopbitsLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, stopbitsLabel);

        stopbitsBox = new QComboBox(widget);
        stopbitsBox->addItem(QString());
        stopbitsBox->addItem(QString());
        stopbitsBox->addItem(QString());
        stopbitsBox->setObjectName("stopbitsBox");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, stopbitsBox);

        flowcontrolLabel = new QLabel(widget);
        flowcontrolLabel->setObjectName("flowcontrolLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, flowcontrolLabel);

        flowcontrolBox = new QComboBox(widget);
        flowcontrolBox->addItem(QString());
        flowcontrolBox->addItem(QString());
        flowcontrolBox->addItem(QString());
        flowcontrolBox->setObjectName("flowcontrolBox");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, flowcontrolBox);


        verticalLayout_5->addWidget(widget);

        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        verticalLayout_3 = new QVBoxLayout(widget_6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        comConnect = new QPushButton(widget_6);
        comConnect->setObjectName("comConnect");

        verticalLayout_3->addWidget(comConnect);

        comDisconnect = new QPushButton(widget_6);
        comDisconnect->setObjectName("comDisconnect");

        verticalLayout_3->addWidget(comDisconnect);


        verticalLayout_5->addWidget(widget_6);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 6);
        verticalLayout_5->setStretch(2, 3);

        horizontalLayout_8->addWidget(widget_4);

        widget_5 = new QWidget(comPage);
        widget_5->setObjectName("widget_5");
        verticalLayout_6 = new QVBoxLayout(widget_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName("widget_8");
        gridLayout_7 = new QGridLayout(widget_8);
        gridLayout_7->setObjectName("gridLayout_7");
        label = new QLabel(widget_8);
        label->setObjectName("label");

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        modbusText = new QTextEdit(widget_8);
        modbusText->setObjectName("modbusText");

        gridLayout_7->addWidget(modbusText, 1, 0, 1, 1);

        label_10 = new QLabel(widget_8);
        label_10->setObjectName("label_10");

        gridLayout_7->addWidget(label_10, 0, 1, 1, 1);

        taskList = new QListView(widget_8);
        taskList->setObjectName("taskList");
        taskList->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        gridLayout_7->addWidget(taskList, 1, 1, 1, 1);

        cleanBtn = new QPushButton(widget_8);
        cleanBtn->setObjectName("cleanBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cleanBtn->sizePolicy().hasHeightForWidth());
        cleanBtn->setSizePolicy(sizePolicy3);

        gridLayout_7->addWidget(cleanBtn, 2, 0, 1, 1);

        gridLayout_7->setColumnStretch(0, 5);
        gridLayout_7->setColumnStretch(1, 3);

        verticalLayout_6->addWidget(widget_8);

        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName("widget_9");
        verticalLayout_8 = new QVBoxLayout(widget_9);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_2 = new QLabel(widget_9);
        label_2->setObjectName("label_2");

        verticalLayout_8->addWidget(label_2);

        widget_2 = new QWidget(widget_9);
        widget_2->setObjectName("widget_2");
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setObjectName("gridLayout_6");
        label_12 = new QLabel(widget_2);
        label_12->setObjectName("label_12");

        gridLayout_6->addWidget(label_12, 2, 0, 1, 1);

        slaveAddress = new QSpinBox(widget_2);
        slaveAddress->setObjectName("slaveAddress");
        slaveAddress->setMinimum(1);

        gridLayout_6->addWidget(slaveAddress, 1, 0, 1, 1);

        startAddress = new QSpinBox(widget_2);
        startAddress->setObjectName("startAddress");

        gridLayout_6->addWidget(startAddress, 1, 3, 1, 1);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");

        gridLayout_6->addWidget(label_7, 0, 2, 1, 1);

        functionCode = new QComboBox(widget_2);
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->addItem(QString());
        functionCode->setObjectName("functionCode");

        gridLayout_6->addWidget(functionCode, 1, 2, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");

        gridLayout_6->addWidget(label_9, 0, 4, 1, 1);

        coils = new QSpinBox(widget_2);
        coils->setObjectName("coils");
        coils->setMinimum(1);

        gridLayout_6->addWidget(coils, 1, 4, 1, 1);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");

        gridLayout_6->addWidget(label_8, 0, 3, 1, 1);

        regInput = new QLineEdit(widget_2);
        regInput->setObjectName("regInput");
        regInput->setEnabled(false);

        gridLayout_6->addWidget(regInput, 2, 2, 1, 1);


        verticalLayout_8->addWidget(widget_2);

        widget_3 = new QWidget(widget_9);
        widget_3->setObjectName("widget_3");
        horizontalLayout_7 = new QHBoxLayout(widget_3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        addTaskBtn = new QPushButton(widget_3);
        addTaskBtn->setObjectName("addTaskBtn");

        horizontalLayout_7->addWidget(addTaskBtn);

        deleteTaskBtn = new QPushButton(widget_3);
        deleteTaskBtn->setObjectName("deleteTaskBtn");

        horizontalLayout_7->addWidget(deleteTaskBtn);

        singleBtn = new QPushButton(widget_3);
        singleBtn->setObjectName("singleBtn");
        singleBtn->setEnabled(false);

        horizontalLayout_7->addWidget(singleBtn);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(label_11);

        spinBox = new QSpinBox(widget_3);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1000);
        spinBox->setMaximum(9999999);

        horizontalLayout_7->addWidget(spinBox);

        cycleCheck = new QCheckBox(widget_3);
        cycleCheck->setObjectName("cycleCheck");
        cycleCheck->setEnabled(false);

        horizontalLayout_7->addWidget(cycleCheck);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(3, 1);
        horizontalLayout_7->setStretch(4, 1);
        horizontalLayout_7->setStretch(5, 1);

        verticalLayout_8->addWidget(widget_3);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 2);
        verticalLayout_8->setStretch(2, 8);

        verticalLayout_6->addWidget(widget_9);

        verticalLayout_6->setStretch(0, 5);
        verticalLayout_6->setStretch(1, 2);

        horizontalLayout_8->addWidget(widget_5);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 4);
        mainStack->addWidget(comPage);

        gridLayout_3->addWidget(mainStack, 0, 0, 1, 1);

        splitter->addWidget(mainPage);
        rightMenu = new QWidget(splitter);
        rightMenu->setObjectName("rightMenu");
        rightMenu->setMinimumSize(QSize(1, 0));
        gridLayout_4 = new QGridLayout(rightMenu);
        gridLayout_4->setObjectName("gridLayout_4");
        rightStack = new QStackedWidget(rightMenu);
        rightStack->setObjectName("rightStack");
        toolPage = new QWidget();
        toolPage->setObjectName("toolPage");
        gridLayout_8 = new QGridLayout(toolPage);
        gridLayout_8->setObjectName("gridLayout_8");
        label_4 = new QLabel(toolPage);
        label_4->setObjectName("label_4");

        gridLayout_8->addWidget(label_4, 0, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(47, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_11, 0, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_10, 0, 0, 1, 1);

        rightStack->addWidget(toolPage);
        idPage = new QWidget();
        idPage->setObjectName("idPage");
        gridLayout_9 = new QGridLayout(idPage);
        gridLayout_9->setObjectName("gridLayout_9");
        horizontalSpacer_12 = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_12, 0, 0, 1, 1);

        label_5 = new QLabel(idPage);
        label_5->setObjectName("label_5");

        gridLayout_9->addWidget(label_5, 0, 1, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(47, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_13, 0, 2, 1, 1);

        rightStack->addWidget(idPage);

        gridLayout_4->addWidget(rightStack, 0, 0, 1, 1);

        splitter->addWidget(rightMenu);

        horizontalLayout_5->addWidget(splitter);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 10);

        verticalLayout->addWidget(MainWidget);

        StatusWidget = new QWidget(centralwidget);
        StatusWidget->setObjectName("StatusWidget");
        horizontalLayout_6 = new QHBoxLayout(StatusWidget);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 10, 0);
        horizontalSpacer_9 = new QSpacerItem(718, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        timeLabel = new QLabel(StatusWidget);
        timeLabel->setObjectName("timeLabel");

        horizontalLayout_6->addWidget(timeLabel);


        verticalLayout->addWidget(StatusWidget);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 32);
        verticalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        mainStack->setCurrentIndex(2);
        databitBox->setCurrentIndex(3);
        rightStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        IconBtn->setText(QString());
        IconLabel->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\250\213\345\272\217", nullptr));
        QssBtn->setText(QString());
        MinBtn->setText(QString());
        MaxBtn->setText(QString());
        CloseBtn->setText(QString());
        modbusBtn->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        plotBtn->setText(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\345\233\276", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216", nullptr));
        networkBtn->setText(QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234", nullptr));
        toolBtn->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        idBtn->setText(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Host:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Topic:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Message:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\217\221\345\270\203", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "bugbtn", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\344\277\241\346\201\257", nullptr));
        comStateLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\252\350\277\236\346\216\245", nullptr));
        comportLabel->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        baudrateLabel->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        baudrateBox->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        baudrateBox->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        baudrateBox->setItemText(2, QCoreApplication::translate("MainWindow", "38400", nullptr));
        baudrateBox->setItemText(3, QCoreApplication::translate("MainWindow", "57600", nullptr));
        baudrateBox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));

        databitLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        databitBox->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        databitBox->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        databitBox->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        databitBox->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        parityLabel->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        parityBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        parityBox->setItemText(1, QCoreApplication::translate("MainWindow", "Even", nullptr));
        parityBox->setItemText(2, QCoreApplication::translate("MainWindow", "Odd", nullptr));

        stopbitsLabel->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        stopbitsBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        stopbitsBox->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        stopbitsBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        flowcontrolLabel->setText(QCoreApplication::translate("MainWindow", "\346\265\201\346\216\247", nullptr));
        flowcontrolBox->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        flowcontrolBox->setItemText(1, QCoreApplication::translate("MainWindow", "Hardware", nullptr));
        flowcontrolBox->setItemText(2, QCoreApplication::translate("MainWindow", "Software", nullptr));

        comConnect->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\277\236\346\216\245", nullptr));
        comDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\344\277\241\346\201\257", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        cleanBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\252\227\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "modbus RTU\351\205\215\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\345\257\204\345\255\230\345\231\250\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\212\237\350\203\275\347\240\201", nullptr));
        functionCode->setItemText(0, QCoreApplication::translate("MainWindow", "0x01", nullptr));
        functionCode->setItemText(1, QCoreApplication::translate("MainWindow", "0x02", nullptr));
        functionCode->setItemText(2, QCoreApplication::translate("MainWindow", "0x03", nullptr));
        functionCode->setItemText(3, QCoreApplication::translate("MainWindow", "0x04", nullptr));
        functionCode->setItemText(4, QCoreApplication::translate("MainWindow", "0x05", nullptr));
        functionCode->setItemText(5, QCoreApplication::translate("MainWindow", "0x06", nullptr));
        functionCode->setItemText(6, QCoreApplication::translate("MainWindow", "0x0f", nullptr));
        functionCode->setItemText(7, QCoreApplication::translate("MainWindow", "0x10", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\234\272\345\234\260\345\235\200", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\234\260\345\235\200", nullptr));
        addTaskBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        deleteTaskBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
        singleBtn->setText(QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\350\257\267\346\261\202", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\221\250\346\234\237", nullptr));
        cycleCheck->setText(QCoreApplication::translate("MainWindow", "\345\256\232\346\227\266\350\257\273\345\217\226", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267\351\241\265", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267\351\241\265", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
