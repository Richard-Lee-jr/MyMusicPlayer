#include "mybutton.h"
#include <QPixmap>

MyButton::MyButton(const QString& img)
{
    if (img == "")
    {
        //固定按钮的大小
        setFixedSize(80, 24);
        //设置鼠标放在按钮上时的图标
        this->setCursor(Qt::PointingHandCursor);

        //设置按钮风格
        this->setStyleSheet("QPushButton{"
                            "text-align:left;"              //center
                            "border-style:solid;"
                            "border-width: 1px;"
                            "border-radius: 6px;"
                            "font: bold 12px;"
                            "}"

                            //鼠标放在按钮上时的样式配置
                            "QPushButton:hover{"
                            "}"

                            //鼠标按下的样式配置
                            "QPushButton:pressed{"
                            "}");

    }
}

MyButton::MyButton(const QString& nmlImg, const QString& hovImg, const QString& prsImg)
{
    QPixmap pix;

    bool ret = pix.load(nmlImg);
    //判断是否打开成功
    if (!ret)
    {
        qDebug() << nmlImg << "加载图片失败";
        return;
    }

    //固定按钮的大小
    this->setFixedSize(pix.width(), pix.height());

    //设置按钮图标
    //this->setIcon(QIcon(pix));

    //设置按钮中图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));
    //设置默认提示
    //this->setToolTip("上一曲");

    //设置鼠标放在按钮上时的图标
    this->setCursor(Qt::PointingHandCursor);

    //设置按钮风格
    updateBtnImg(nmlImg, hovImg, prsImg);
}

//重写鼠标按下 和 释放 事件
void MyButton::mousePressEvent(QMouseEvent *e)
{
    //拦截后再交由父类处理
    return QPushButton::mousePressEvent(e);
}
void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    //拦截后再交由父类处理
    return QPushButton::mouseReleaseEvent(e);
}

void MyButton::updateBtnImg(const QString& nmlImg, const QString& hovImg, const QString& prsImg)
{
    QString qsCSS = QString("QPushButton{"
                            "text-align:center;"
                            "background-image: url(%1);"
                            "border: none;"
                            "font: bold 14px;"
                            "}"

                            //鼠标放在按钮上时的样式配置
                            "QPushButton:hover{"
                            "background-image: url(%2);"   //aqua   //鼠标放在按钮上显示的背景颜色
                            "}"

                            //鼠标按下的样式配置
                            "QPushButton:pressed{"
                            "background-image: url(%3);" //按钮按下时的背景颜色
                            "}").arg(nmlImg).arg(hovImg).arg(prsImg);

    this->setStyleSheet(qsCSS);
}
