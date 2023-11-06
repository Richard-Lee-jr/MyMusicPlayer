#ifndef TOPFRAME_H
#define TOPFRAME_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <QTextBrowser>
#include <QListWidget>
#include <QFileDialog>
#include <QFont>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QGridLayout>      //网格布局
#include <QDebug>
#include <QMap>
#include <QPlainTextEdit>
#include <QListWidget>
#include "configfile.h"
#include "mybutton.h"

class TopFrame : public QFrame
{
    Q_OBJECT
public:
    explicit TopFrame(QWidget *parent = nullptr);

    void updateLyricFrame(const QString& name);
    void clearLyricFrameWidget();
    bool loadLyric(const QString& name);

protected:
    //重新绘图事件
    //void paintEvent(QPaintEvent *);


signals:
    //点击添加按钮add发送的信号，在BottomFrame中接收
    void addClickedSignal(QString songPath = "");

    //delete按钮的信号，实现点击delete清空歌曲列表
    void delClickedSignal();

    //双击songList中的选项信号
    void itemDoubleclickedSignal(int index, const QString& text);

    //自定义信号更新当前播放歌曲名, 在mainWidget中接收
    void updateSongName(int index, const QString& text);



public slots:
    //接收ButtomFrame中list按钮点击信号的槽函数
    void getListClicked(bool checked = false);

    //itemDoubleClicked槽函数
    void getItemDoubleClicked(QListWidgetItem *item);

    //接收BottomFrame中的pre按钮点击信息的槽函数
    void getPreClicked(int index);

    //接收BottomFrame中next按钮点击信号的槽函数
    void getNextClicked(int index);

    void getSongInfo(int index);

    void slotUpdateLyric(qint64 position);

    void slotDurationChanged(qint64 duration);

private:
    //topFrame总体水平布局
    QHBoxLayout* topHlayout;

    //左侧框架：歌词框架
    QFrame* lyricFrame;
    //左侧框架水平布局
    QHBoxLayout* lyricHlayout;


    //右侧框架：歌曲列表框架
    QFrame* listFrame;
    //右侧框架用网格布局代替水平垂直布局
    //QGridLayout* listGridLayout;
    //右侧框架总体垂直布局
    QVBoxLayout* listVlayout;
    //右侧框架上半部分水平布局
    QHBoxLayout* listTopHlayout;



    //左侧框架里的控件
    //歌词控件
    //QListWidget* lyrics;
    QListWidget* lyricWidget;


    //右侧框架里的控件
    //歌曲列表控件
    QListWidget* songList;
    //添加按钮
    MyButton* add;
    //删除按钮
    MyButton* del;
    //隐藏按钮
    MyButton* hide;

    QMap<int, QString> lyricMap;
    int curPos;

};

#endif // TOPFRAME_H
