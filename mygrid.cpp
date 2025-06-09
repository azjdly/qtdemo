#include "mygrid.h"

#include <QMenu>
#include <QContextMenuEvent>
#include "myplot.h"
MyGrid::MyGrid(QWidget *parent)
    : QWidget{parent}
{
    contextMenu = new QMenu(this);  // 只创建一次
    QAction *addAction = contextMenu->addAction("增加图表");
    QAction *deleteAction = contextMenu->addAction("删除图表");
    QAction *enlargeAction = contextMenu->addAction("视图切换");

    connect(contextMenu, &QMenu::triggered, this, [this](QAction *action){

        if (action->text() == "增加图表") {
            addPlot();

        } else if (action->text() == "删除图表") {
            delPlot(menuPos);
        }
        else if(action->text() == "视图切换"){
            if(enlargePlot == nullptr)
            {
                QWidget *widgetUnderMouse = QApplication::widgetAt(menuPos);
                MyPlot *plot = qobject_cast<MyPlot*>(widgetUnderMouse); // 安全转换
                if (plot && m_PlotLists.contains(plot))
                {
                    int index =m_PlotLists.indexOf(plot);
                    enlargePlot=plot;
                    isGrid=!isGrid;
                    for (int i = 0; i < m_PlotLists.size(); ++i) {
                        if (i != index) { // 让其他图表隐藏
                            m_PlotLists[i]->setVisible(false);
                        }
                    }
                    setPosition();
                    update();
                }
            }
            else
            {
                isGrid=!isGrid;
                for (int i = 0; i < m_PlotLists.size(); ++i) {

                        m_PlotLists[i]->setVisible(true);
                    }

                setPosition();
                update();
                enlargePlot=nullptr;
            }
        }
    });


    setAcceptDrops(true);
}

void MyGrid::contextMenuEvent(QContextMenuEvent *event)
{
    menuPos=event->globalPos();
    contextMenu->popup(mapToGlobal(event->pos()));  // 复用菜单
}

void MyGrid::resizeEvent(QResizeEvent *event)
{
    setPosition();
    update();
}

void MyGrid::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        menuPos=event->globalPos();
        contextMenu->popup(event->globalPos()); // 右键点击弹出菜单
        return;
    }

    if (event->button() != Qt::LeftButton) {
        return; // 不是左键或右键，直接返回
    }

    qDebug() << "鼠标左键按下";
    QCustomPlot *Plot = qobject_cast<QCustomPlot*>(QApplication::widgetAt(event->globalPos()));

    if (m_PlotLists.contains(Plot))
    {
        draggedPlot = Plot;
        return;
    }
}


void MyGrid::mouseMoveEvent(QMouseEvent *event)
{
    if (!draggedPlot) return;
    qDebug() << "鼠标移动";
    // 创建拖拽对象
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    // **存储拖拽的 widget 指针**
    mimeData->setText(QString::number(reinterpret_cast<quintptr>(draggedPlot)));
    drag->setMimeData(mimeData);

    // 设置拖拽视觉效果
    QPixmap pixmap = draggedPlot->grab();
    if (pixmap.isNull()) {
        pixmap = QPixmap(100, 100);
        pixmap.fill(Qt::lightGray);
    }
    drag->setPixmap(pixmap);

    drag->exec(Qt::MoveAction);
}

void MyGrid::mouseReleaseEvent(QMouseEvent *event)
{
    draggedPlot=nullptr;
}

void MyGrid::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "进入拖拽";
    event->acceptProposedAction();
}

void MyGrid::dropEvent(QDropEvent *event)
{
    QWidget *targetPlot = QApplication::widgetAt(mapToGlobal(event->pos()));

    qDebug() << "拖拽处理";

    if (m_PlotLists.contains(draggedPlot) && m_PlotLists.contains(targetPlot))
    {
        int index1 = m_PlotLists.indexOf(draggedPlot);
        int index2 = m_PlotLists.indexOf(targetPlot);
        qDebug() << "位置：" << index1 << "and" << index2;
        if (index1 != -1 && index2 != -1)
        {
            std::swap(m_PlotLists[index1],m_PlotLists[index2]); // 交换数据结构中的位置
            qDebug() << "交换位置：" << index1 << "<->" << index2;
        }

        setPosition(); // **调用显示更新**
        update(); // **强制刷新 UI**

    }
    draggedPlot=nullptr;
}

bool MyGrid::eventFilter(QObject *obj, QEvent *event)
{
    if(isGrid && (event->type() == QEvent::MouseButtonPress ||
                   event->type() == QEvent::MouseMove ||
                   event->type() == QEvent::MouseButtonRelease ||
                   event->type() == QEvent::DragEnter ||
                   event->type() == QEvent::Drop))
    {
        QCoreApplication::sendEvent(this, event);
        return true; // 拦截鼠标点击
    }
    if (!isGrid && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event); // 强制转换
        if (mouseEvent && mouseEvent->button() == Qt::RightButton) {
            contextMenu->popup(mouseEvent->globalPos()); // 右键点击弹出菜单
            return true;
        }
    }

    return QObject::eventFilter(obj, event); // 让Qt继续处理其他事件
}


void MyGrid::addPlot()
{
    if(m_PlotLists.count() == 12)
        return;
    MyPlot *plot=new MyPlot(this);
    m_PlotLists.append(plot);
    plot->installEventFilter(this);
    setPosition();
    plot->show();
    update();
}

void MyGrid::delPlot(QPoint pos)
{
    if (!m_PlotLists.isEmpty()) // 确保列表不为空
    {
        QWidget *widgetUnderMouse = QApplication::widgetAt(pos);
        MyPlot *plot = qobject_cast<MyPlot*>(widgetUnderMouse); // 安全转换

        if (plot && m_PlotLists.contains(plot)) {
            int index = m_PlotLists.indexOf(plot);

            if (index != -1) {
                qDebug() << "删除 plot：" << index;
                delete m_PlotLists.takeAt(index); // 移除列表项并释放内存
                if(enlargePlot != nullptr)
                {
                    isGrid=!isGrid;
                    for (int i = 0; i < m_PlotLists.size(); ++i) {

                        m_PlotLists[i]->setVisible(true);
                    }
                    enlargePlot=nullptr;
                }
                setPosition();
                update(); // 刷新 UI
            }
        }
    }
}


void MyGrid::setPosition()
{
    int plotWidth=width()/5;
    int plotHeight=height()/4;
    int gapWidth=width()/25;
    int gapHeight=height()/16;
    if(isGrid)
    {
        for(int i=0;i<m_PlotLists.size();i++)
        {
            int row=i/4;
            int column=i%4;
            int x=gapWidth + column*(gapWidth + plotWidth);
            int y=gapHeight + row*(gapHeight + plotHeight);
            m_PlotLists[i]->setGeometry(x, y, plotWidth, plotHeight);

        }
    }
    else
    {
        enlargePlot->setGeometry(0.1*width(),0.1*height(),0.8*width(),0.8*height());
    }
}
