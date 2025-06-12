#ifndef STYLEMENU_H
#define STYLEMENU_H

#include <QWidget>

namespace Ui {
class stylemenu;
}

class stylemenu : public QWidget
{
    Q_OBJECT

public:
    explicit stylemenu(QWidget *parent = nullptr, const QList<QString> &styles={});
    ~stylemenu();
signals:
    changeStyle(QString style);
private slots:
    void on_pushButton_clicked();

private:
    Ui::stylemenu *ui;
    QList<QString> stylelist ;
};

#endif // STYLEMENU_H
