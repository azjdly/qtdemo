/********************************************************************************
** Form generated from reading UI file 'stylemenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEMENU_H
#define UI_STYLEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stylemenu
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QWidget *stylemenu)
    {
        if (stylemenu->objectName().isEmpty())
            stylemenu->setObjectName("stylemenu");
        stylemenu->resize(400, 300);
        verticalLayout = new QVBoxLayout(stylemenu);
        verticalLayout->setObjectName("verticalLayout");
        comboBox = new QComboBox(stylemenu);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        pushButton = new QPushButton(stylemenu);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(stylemenu);

        QMetaObject::connectSlotsByName(stylemenu);
    } // setupUi

    void retranslateUi(QWidget *stylemenu)
    {
        stylemenu->setWindowTitle(QCoreApplication::translate("stylemenu", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("stylemenu", "\351\200\211\346\213\251\344\270\273\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stylemenu: public Ui_stylemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEMENU_H
