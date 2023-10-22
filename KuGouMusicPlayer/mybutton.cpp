#include "mybutton.h"

MyButton::MyButton(QString img)
{
    if (img == "")
    {
        normalImg = "";
        pressImg = "";
        pix = nullptr;
        img = nullptr;

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
                            //"background-color: deepskyblue;"   //aqua   //鼠标放在按钮上显示的背景颜色
                            //"color: deepskyblue;"
                            //"border-color:aqua;"      //鼠标放在按钮上时的边框
                            "}"

                            //鼠标按下的样式配置
                            "QPushButton:pressed{"
                            //"background-color:  deepskyblue;" //按钮按下时的背景颜色
                            //"border-color:deepskyblue;"
                            //"color:deepskyblue;"//deepskyblue //按钮按下时边框颜色

                            "}");

    }
}

MyButton::MyButton(QString nmlImg, QString prsImg)
{
    this->normalImg = nmlImg;
    this->pressImg = prsImg;
    img = new QImage(normalImg);
    pix = new QPixmap();
    *pix = QPixmap::fromImage(*img);
    bool ret = pix->load(normalImg);
    //判断是否打开成功
    if (!ret)
    {
        qDebug() << normalImg << "加载图片失败";
        return;
    }
    //固定按钮的大小
    this->setFixedSize(pix->width(), pix->height());
    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px}");
    //设置按钮图标
    this->setIcon(QIcon(*pix));
    //设置按钮中图标大小
    this->setIconSize(QSize(pix->width(), pix->height()));
    //设置默认提示
    //this->setToolTip("上一曲");
    //设置鼠标放在按钮上时的图标
    this->setCursor(Qt::PointingHandCursor);

    //设置按钮风格
    this->setStyleSheet("QPushButton{"
//                        "width:100px;"
//                       "height:32px;"
                        "text-align:center;"
//                      "line-height:32px;"
                        //"background-color: white;"   //deepskyblue //鼠标未放在按钮上显示的背景颜色，即默认背景颜色
                        "border-style:solid;"
                        "border-width: 1px;"
                        "border-radius: 6px;"
                        //"border-color: deepskyblue;"    //按钮边框颜色
                        "font: bold 14px;"
                        //"color :white;"         //按钮边框颜色
                        "}"

                        //鼠标放在按钮上时的样式配置
                        "QPushButton:hover{"
                        //"background-color: deepskyblue;"   //aqua   //鼠标放在按钮上显示的背景颜色
                        //"color: deepskyblue;"
                        //"border-color:aqua;"      //鼠标放在按钮上时的边框
                        "}"

                        //鼠标按下的样式配置
                        "QPushButton:pressed{"
                        //"background-color:  deepskyblue;" //按钮按下时的背景颜色
                        //"border-color:deepskyblue;"
                        //"color:deepskyblue;"//deepskyblue //按钮按下时边框颜色

                        "}");
}

//重写鼠标按下 和 释放 事件
void MyButton::mousePressEvent(QMouseEvent *e)
{

    if (this->pressImg != "")   //传入的第二个参数不为空说明点击按钮需要切换图片
    {
        //qDebug() << "按下";
        //QPixmap pix;
        bool ret = pix->load(this->pressImg);
        //判断是否打开成功
        if (!ret)
        {
            qDebug() << this->pressImg << "加载图片失败！";
            return;
        }
        //固定按钮的大小
        this->setFixedSize(pix->width(), pix->height());
        //设置不规则图片的样式
        //this->setStyleSheet("QPushButton{border:0px}");
        //设置按钮图标
        this->setIcon(QIcon(*pix));
        //设置按钮中图标大小
        this->setIconSize(QSize(pix->width(), pix->height()));
        //设置默认提示
        //this->setToolTip("上一曲");
        //设置鼠标放在按钮上时的图标
        this->setCursor(Qt::PointingHandCursor);
    }

    //拦截后再交由父类处理
    return QPushButton::mousePressEvent(e);
}
void MyButton::mouseReleaseEvent(QMouseEvent *e)
{

    if (this->pressImg != "")   //传入的第二个参数不为空说明点击按钮需要切换图片
    {
        //qDebug() << "释放";
        //QPixmap pix;
        bool ret = pix->load(this->normalImg);
        //判断是否打开成功
        if (!ret)
        {
            qDebug() << this->normalImg << "加载图片失败！";
            return;
        }
        //固定按钮的大小
        this->setFixedSize(pix->width(), pix->height());
        //设置不规则图片的样式
        //this->setStyleSheet("QPushButton{border:0px}");
        //设置按钮图标
        this->setIcon(QIcon(*pix));
        //设置按钮中图标大小
        this->setIconSize(QSize(pix->width(), pix->height()));
        //设置默认提示
        //this->setToolTip("上一曲");
        //设置鼠标放在按钮上时的图标
        this->setCursor(Qt::PointingHandCursor);
    }

    //拦截后再交由父类处理
    return QPushButton::mouseReleaseEvent(e);
}
