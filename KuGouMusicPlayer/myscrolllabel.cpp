#include "myscrolllabel.h"

MyScrollLabel::MyScrollLabel(QWidget *parent) : QLabel(parent)
{
    //重置控件大小
    resize(96, 24);
    //设置控件风格样式
    setStyleSheet(QString("QLabel{"
                          "text-align:center;"
                          "border-style:none;"              //solid
                          "border-width: 1px;"
                          "border-radius: 6px;"              //
                          "font: bold 14px;"
                          "}"));


    //滚动定时器
    scrollTimer = new QTimer();
    //滚动内容
    text = "正在播放：暂无播放";
    //当前位置
    curIndex = 0;

    //连接定时器信号
    connect(scrollTimer, &QTimer::timeout, this, &MyScrollLabel::updateIndex);
    //启动定时器
    scrollTimer->start(50);
}


/********************这里是成员函数*************************************/



/*******************重写继承自基类的虚函数************************************/
//重写绘图事件
void MyScrollLabel::paintEvent(QPaintEvent *e)
{
    //指定 该控件为绘图设备
    QPainter painter(this);
    //绘制后半部分文字
    painter.drawText(curIndex, 13, text);
}


/********************下面是槽函数********************************/
//响应定时器超时信号
void MyScrollLabel::updateIndex()
{
    //每20ms更新位置，实现向左滚动
    //如果文本长度小于控件长度就无需滚动了
    if (text.size() * 15 > this->width())
    {
        //测试
        //qDebug() << "文本长度： " << text.size();
        //qDebug() << "控件长度： " << width();
        curIndex--;
    }

    //如果当前位置大于该控件宽度时
    if (0 - curIndex > text.size() * 15)    //字符串中一个字符大小大概为15个像素点（可在绘图事件中通过画家设置字符像素点大小），
    {
        //测试
        //qDebug() << text.size();
        //qDebug() << "curIndex:" << curIndex;
        curIndex = width();
    }
    //手动调用绘图事件绘制文字
    update();
}
