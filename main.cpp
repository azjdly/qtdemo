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

    // 读取 QSS 文件
    QFile file(":/myqss/style/stylesheetDark.qss"); // 如果是资源文件，使用 `:/` 作为路径
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet); // 应用样式
        file.close();
    }

    MainWindow w;
    QIcon icon(":/icon/icon/ufoW.png");
    w.setWindowIcon(icon);
    w.show();
    return a.exec();
}
