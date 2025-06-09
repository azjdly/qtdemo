QT       += core gui printsupport serialport serialbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# Windows API 需要的库
LIBS += -luser32 -lsetupapi
QMAKE_CXXFLAGS += -Wa,-mbig-obj
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    carouselwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    modbusworker.cpp \
    mygrid.cpp \
    myplot.cpp \
    qcustomplot.cpp

HEADERS += \
    carouselwidget.h \
    mainwindow.h \
    modbusworker.h \
    mygrid.h \
    myplot.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    PictureRes.qrc \
    style.qrc
