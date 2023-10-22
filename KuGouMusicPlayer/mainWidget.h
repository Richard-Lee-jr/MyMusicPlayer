#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QImage>
#include "topframe.h"
#include "bottomframe.h"
#include "configfile.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

protected:
    //重新绘图事件
    void paintEvent(QPaintEvent *event);

private:
    TopFrame* topFrame;
    BottomFrame* btmFrame;
    //主框架
    //QFrame* mainFrame;
    //还需要一个垂直布局
    QVBoxLayout* mainVLayout;


};

#endif // WIDGET_H
