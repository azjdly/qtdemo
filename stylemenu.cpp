#include "stylemenu.h"
#include "ui_stylemenu.h"

stylemenu::stylemenu(QWidget *parent, const QList<QString> &styles)
    : QWidget(parent), stylelist(styles), ui(new Ui::stylemenu)
{
    ui->setupUi(this);
    QIcon icon(":/icon/icon/panel.png");
    setWindowTitle("皮肤选择");
    this->setWindowIcon(icon);
    // ✅ 正确的遍历方式
    for (const QString &styleName : stylelist) {
        ui->comboBox->addItem(styleName);  // ✅ 添加选项
    }

}


stylemenu::~stylemenu()
{
    delete ui;
}

void stylemenu::on_pushButton_clicked()
{
    emit changeStyle(ui->comboBox->currentText());
}

