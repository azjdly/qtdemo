#include "carouselwidget.h"

CarouselWidget::CarouselWidget(QWidget *parent)
    : QWidget{parent}
{
    // 创建 3 个 QLabel

    QLabel *label1 = new QLabel(this);
    label1->setPixmap(loadAndScaleImage(":/picture/picture/chilun.jpg", QSize(800, 600))); // 设置图片
    label1->setFixedSize(200, 150);  // 设置固定大小
    label1->setScaledContents(true); // 让图片适应 QLabel
    labelLists.append(label1);  // 添加到列表

    QLabel *label2 = new QLabel(this);
    label2->setPixmap(loadAndScaleImage(":/picture/picture/welcome.jpg", QSize(800, 600))); // 设置图片
    label2->setFixedSize(200, 150);  // 设置固定大小
    label2->setScaledContents(true); // 让图片适应 QLabel
    labelLists.append(label2);  // 添加到列表

    QLabel *label3 = new QLabel(this);
    label3->setPixmap(loadAndScaleImage(":/picture/picture/shiboqi.jpg", QSize(800, 600))); // 设置图片
    label3->setFixedSize(200, 150);  // 设置固定大小
    label3->setScaledContents(true); // 让图片适应 QLabel
    labelLists.append(label3);  // 添加到列表

    setPosition();

    animation = new QVariantAnimation(this);
    animation->setStartValue(0);
    animation->setEndValue(60);
    animation->setDuration(1000); // 平滑过渡 1秒
    animation->setEasingCurve(QEasingCurve::Linear);

    connect(animation, &QVariantAnimation::valueChanged, this, &CarouselWidget::onValueChanged);

    // 创建定时器
    timer = new QTimer(this);
    timer->setInterval(3000); // 每 3 秒触发一次
    connect(timer, &QTimer::timeout, this, &CarouselWidget::onTimeout);

    timer->start();
}

CarouselWidget::~CarouselWidget()
{

}

void CarouselWidget::setPosition()
{
    int parentWidth = this->width();
    int parentHeight = this->height();

    int midIndex = labelLists.size() / 2; // 获取中心索引
    double baseWidth = parentWidth * (2.0 / 3);
    double baseHeight = parentHeight * (3.0 / 4);

    for (int i = 0; i < labelLists.size(); ++i) {
        QLabel *label = labelLists[i];

        int distance = abs(i - midIndex);
        double scaleFactor = pow(0.8, distance); // 每向外一层缩小 0.8 倍

        int labelWidth = static_cast<int>(baseWidth * scaleFactor);
        int labelHeight = static_cast<int>(baseHeight * scaleFactor);
        label->setFixedSize(labelWidth, labelHeight);

        // **计算位置**：只使用固定偏移，不受缩放影响
        int offset = (i - midIndex) * (parentWidth * (1.0 / 6));
        int labelX = parentWidth / 2 + offset - labelWidth / 2;
        int labelY = parentHeight / 2 - labelHeight / 2;

        label->move(labelX, labelY);

        // **按距离调整 Z 轴层级**
        if (i <= midIndex) {
            label->raise();  // 如果 `i` 小于等于 `midIndex`，提升层级
        } else {
            label->lower();  // 如果 `i` 大于 `midIndex`，降低层级
        }
    }
}

void CarouselWidget::resizeEvent(QResizeEvent *event)
{
    if(animation->state() == QVariantAnimation::Running)
        moveLeft(animation->currentValue().toInt());
    else
        CarouselWidget::setPosition();
}

void CarouselWidget::onValueChanged(const QVariant &newValue)
{
    moveLeft(newValue.toInt());
}

void CarouselWidget::onTimeout()
{
    animation->start();
}


void CarouselWidget::moveLeft(int progress)
{
    int parentWidth = this->width();
    int parentHeight = this->height();
    int midIndex = labelLists.size() / 2;

    // 获取 list[last] 的位置和大小
    QLabel *lastLabel = labelLists.last();
    int lastDistance = abs(labelLists.size() - 1 - midIndex);
    double lastScaleFactor = pow(0.8, lastDistance);

    int baseWidth = parentWidth * (2.0 / 3);
    int baseHeight = parentHeight * (3.0 / 4);

    int lastWidth = static_cast<int>(baseWidth * lastScaleFactor);
    int lastHeight = static_cast<int>(baseHeight * lastScaleFactor);

    int lastOffset = (labelLists.size() - 1 - midIndex) * (parentWidth * (1.0 / 6));
    int lastX = parentWidth / 2 + lastOffset - lastWidth / 2;
    int lastY = parentHeight / 2 - lastHeight / 2;

    for (int i = 0; i < labelLists.size(); ++i)
    {
        QLabel *label = labelLists[i];

        // 当前大小和位置
        int distance = abs(i - midIndex);
        double scaleFactor = pow(0.8, distance);

        int currentWidth = static_cast<int>(baseWidth * scaleFactor);
        int currentHeight = static_cast<int>(baseHeight * scaleFactor);

        int offset = (i - midIndex) * (parentWidth * (1.0 / 6));
        int currentX = parentWidth / 2 + offset - currentWidth / 2;
        int currentY = parentHeight / 2 - currentHeight / 2;

        // 目标位置和大小
        int targetWidth, targetHeight, targetX, targetY;
        if (i == 0)
        {
            targetWidth = lastWidth;
            targetHeight = lastHeight;
            targetX = lastX;
            targetY = lastY;
        }
        else
        {
            QLabel *targetLabel = labelLists[i - 1];

            int targetDistance = abs(i - 1 - midIndex);
            double targetScaleFactor = pow(0.8, targetDistance);

            targetWidth = static_cast<int>(baseWidth * targetScaleFactor);
            targetHeight = static_cast<int>(baseHeight * targetScaleFactor);

            int targetOffset = (i - 1 - midIndex) * (parentWidth * (1.0 / 6));
            targetX = parentWidth / 2 + targetOffset - targetWidth / 2;
            targetY = parentHeight / 2 - targetHeight / 2;
        }

        // 计算新的位置和大小
        int newWidth = currentWidth + (targetWidth - currentWidth) * progress / 60;
        int newHeight = currentHeight + (targetHeight - currentHeight) * progress / 60;
        int newX = currentX + (targetX - currentX) * progress / 60;
        int newY = currentY + (targetY - currentY) * progress / 60;

        label->setFixedSize(newWidth, newHeight);
        label->move(newX, newY);
        // **调整层级**
        if (progress > 25)
        {
            if (i > 0 && i <= midIndex + 1)
            {
                label->raise();
            }
        }
    }
    if (progress > 25)
    {
        labelLists[0]->lower();
    }
    // 调整列表顺序
    if (progress == 60)
    {
        QLabel *firstLabel = labelLists.takeFirst();
        labelLists.append(firstLabel);
        setPosition();
    }
}

QPixmap CarouselWidget::loadAndScaleImage(const QString &path, const QSize &size)
{
    QPixmap pixmap(path);
    return pixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

