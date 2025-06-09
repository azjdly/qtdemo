#include "myplot.h"
#include <QVector>
MyPlot::MyPlot(QWidget *parent ): QCustomPlot(parent){
    this->addGraph();
    this->graph(0)->setPen(QPen(Qt::blue));
    QVector<double> x(100), y(100);
    for (int i = 0; i < 100; ++i) {
        x[i] = i;
        y[i] = qSin(i * 0.1); // 示例数据
    }
    this->graph(0)->setData(x, y);

    this->xAxis->setLabel("X 轴");
    this->yAxis->setLabel("Y 轴");
    this->xAxis->setRange(0, 100);
    this->yAxis->setRange(-1, 1);
    this->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
