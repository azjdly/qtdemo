#ifndef MYGRID_H
#define MYGRID_H

#include <QWidget>
#include <QMenu>
#include "myplot.h"
#include <QList>
class MyGrid : public QWidget
{
    Q_OBJECT
public:
    explicit MyGrid(QWidget *parent = nullptr);
private:
    void contextMenuEvent(QContextMenuEvent *event)override;
    void resizeEvent(QResizeEvent *event)override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void addPlot();
    void delPlot(QPoint pos);
    void setPosition();
signals:
private:
    QMenu *contextMenu;
    QList<MyPlot *> m_PlotLists;
    QCustomPlot* draggedPlot = nullptr; // 被拖拽的 Widget
    QPoint menuPos; // 记录拖拽前的位置
    QCustomPlot* enlargePlot=nullptr;
    bool isGrid=true;
};

#endif // MYGRID_H
