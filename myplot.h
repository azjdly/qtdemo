#ifndef MYPLOT_H
#define MYPLOT_H

#include "qcustomplot.h"
#include <QWidget>

class MyPlot : public QCustomPlot
{
    Q_OBJECT
public:
    explicit MyPlot(QWidget *parent = nullptr);
private:

};

#endif // MYPLOT_H
