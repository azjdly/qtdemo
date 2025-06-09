#ifndef CAROUSELWIDGET_H
#define CAROUSELWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPixmap>
#include <QVariantAnimation>
class CarouselWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CarouselWidget(QWidget *parent = nullptr);
    ~CarouselWidget();
private:
    void setPosition();
    void resizeEvent(QResizeEvent *event)override;
    void moveLeft(int progress);
    QPixmap loadAndScaleImage(const QString &path, const QSize &size);
signals:
private:
    QList<QLabel *> labelLists;
    QVariantAnimation *animation;
    QTimer *timer;

private slots:
    void onValueChanged(const QVariant &newValue);
    void onTimeout(); // 定时器触发
};

#endif // CAROUSELWIDGET_H
