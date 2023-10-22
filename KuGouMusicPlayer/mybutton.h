#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include "configfile.h"

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    //MyButton() = default;
    MyButton(QString img = "");
    MyButton(QString nmlImg, QString prsImg = "");

    //默认显示的图片路径
    QString normalImg;

    //按下后显示的图片路径
    QString pressImg;
    QPixmap* pix;
    QImage* img;

    //重写鼠标按下 和 释放 事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:
};

#endif // MYBUTTON_H
