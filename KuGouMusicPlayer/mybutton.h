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
    MyButton(const QString& img = "");
    MyButton(const QString& nmlImg, const QString& hovImg, const QString& prsImg);

    //重写鼠标按下 和 释放 事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void updateBtnImg(const QString& nmlImg, const QString& hovImg, const QString& prsImg);

signals:

public slots:
};

#endif // MYBUTTON_H
