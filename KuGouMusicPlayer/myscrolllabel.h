#ifndef MYSCROLLLABEL_H
#define MYSCROLLLABEL_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QPainter>

class MyScrollLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyScrollLabel(QWidget *parent = nullptr);

    //设置文本内容
    inline void setText(const QString& t)
    {
        text = t;
    }

    //设置初始位置
    inline void setCurIndex(int index)
    {
        curIndex = index;
    }

protected:
    //重写绘图事件
    void paintEvent(QPaintEvent *);

signals:

public slots:
    //响应定时器超时信号
    void updateIndex();

private:
    //滚动定时器
    QTimer* scrollTimer;
    //滚动内容
    QString text;
    //当前位置
    int curIndex;

};

#endif // MYSCROLLLABEL_H
