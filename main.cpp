#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include "qcustomplot.h"
#include <QSerialPort>
#include <QMetaType>
#include <QVariant>
#include <QMap>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    QIcon icon(":/icon/icon/ufoW.png");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
