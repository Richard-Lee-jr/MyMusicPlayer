#ifndef BOTTOMFRAME_H
#define BOTTOMFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QSlider>
#include <QScrollBar>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <QLabel>
#include "configfile.h"
#include "mybutton.h"
#include "myscrolllabel.h"

class BottomFrame : public QFrame
{
    Q_OBJECT
    //将TopFrame声明为自己的友元类，则在TopFrame类中可以使用本类BottomFrame的私有成员
    //friend class TopFrame;

public:
    explicit BottomFrame(QWidget *parent = nullptr);

    //初始化函数
    void init();

    //访问list指针，不可修改
    const MyButton* getList() const
    {
        return list;
    }

    //获得当前媒体的时间
    static QString getSongTime(qint64 time);

    //触发自定义信号函数
    void emitPlayOverSignal();

protected:
    //重写绘图事件
    //void paintEvent(QPaintEvent *);

    //重写鼠标移动函数
    //void mouseMoveEvent(QMouseEvent *event);

signals:
    //自定义上一曲按钮信号
    void preClickedSignal(int index);

    //自定义下一曲按钮信号
    void nextClickedSignal(int index);

    //自定义播放完毕信号, 通过emit playOverSignal() 函数触发
    void playOverSignal();

    //更新歌曲信息信号
    void updateSongInfo(int index);

public slots:
    //移动播放进度条触发的槽函数
    //更新歌曲播放时间
    void updateSongSliderDuration(qint64 duration);

    //接收歌曲位置改变，那么滑块的位置也要变
    void updateSongSliderPosition(qint64 position);

    //移动滑动块，改变歌曲进度
    void updateMyPlayerPosition(int value);

    //响应TopFrame中add按钮按下信号（即自定义信号addClicked(QString)）的槽函数
    void getAddClicked(QString songPath = "");

    //响应TopFrame中的del按钮按下信号
    void getDelClicked();

    //响应TopFrame中songList的itemDoubleClicked信号
    void getItemDoubleClicked(int index, const QString& text);

    //响应上一曲点击信号的槽函数
    void getPreClicked();

    //响应播放/暂停按钮点击信号的槽函数
    void getPlayOrPauseClicked();

    //响应下一曲按钮点击信号的槽函数
    void getNextClicked();

private:
    //需要一个垂直布局
    QVBoxLayout* vLayout;
    //需要一个水平布局
    QHBoxLayout* hLayout;

    //时间歌曲名框架
    QWidget* timeAndNameWidget;
    //时间歌曲名布局
    QVBoxLayout* timeAndNameLayout;
    //音乐时间
    MyButton* songTime;
    //滚动字幕
    MyScrollLabel* scrollText;

    //上一曲
    //QPushButton* pre;
    //使用自定义按钮
    MyButton * pre;
    //播放
    //QPushButton* play;
    MyButton* play;
    //下一曲
    //QPushButton* next;
    MyButton* next;
    //音量
    //QPushButton* voice;
    MyButton* voice;
    //音乐列表
    //QPushButton* list;
    MyButton* list;

    //需要一个画家
    //QPainter* btmPainter;
    //音频播放列表
    QMediaPlaylist* mdPlayList;
    QMediaPlayer* my_player;

    //音量滑动块
    QSlider* voiceSlider;
    //音乐进度滑动块
    QSlider* songSlider;
    //音量滑动块定时器
    QTimer* voiceTimer;

};

#endif // BOTTOMFRAME_H
