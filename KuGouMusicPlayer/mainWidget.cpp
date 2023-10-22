#include "mainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //设置主窗口大小
    resize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HERGHT);
    //设置主窗口名称
    setWindowTitle("KuGouMusicPlayer");
    setStyleSheet("QFrame{Background:rgb(255, 255, 255, 0.5);border-color:rgb(225,225,225);border-width:0px;border-style: solid;}");
    //设置主窗口图标
    setWindowIcon(QIcon(MAINWIDGET_ICON));

    topFrame = new TopFrame(this);
    btmFrame = new BottomFrame(this);

    //点击BottomFrame框架中的list则弹出歌曲列表songList
    connect(btmFrame->getList(),  &QPushButton::clicked, topFrame, &TopFrame::getListClicked);

    //点击添加歌曲按钮弹出文件手动添加, 在mainWidget中实现
    //接收来自TopFrame的addClickedSignal信号
    connect(topFrame, &TopFrame::addClickedSignal, btmFrame, &BottomFrame::getAddClicked);

    //接收来自TopFrame的delClickedSignal信号，同时BottomFrame中的槽函数相应
    connect(topFrame, &TopFrame::delClickedSignal, btmFrame, &BottomFrame::getDelClicked);

    //接收来自TopFrame中songList的itemDoubleClicked信号
    connect(topFrame, &TopFrame::itemDoubleclickedSignal, btmFrame, &BottomFrame::getItemDoubleClicked);
    connect(topFrame, &TopFrame::updateSongName, btmFrame, &BottomFrame::getItemDoubleClicked);

    //接收来自BottomFrame中的pre按钮信号，改变TopFrame中songList的item位置
    connect(btmFrame, &BottomFrame::preClickedSignal, topFrame, &TopFrame::getPreClicked);

    //接收来自BottomFrame中的next按钮信号，改变TopFrame中songList的item位置
    connect(btmFrame, &BottomFrame::nextClickedSignal, topFrame, &TopFrame::getNextClicked);

    connect(btmFrame, &BottomFrame::updateSongInfo, topFrame, &TopFrame::getSongInfo);


    //主框架
    //mainFrame = new QFrame(this);
    //还需要一个垂直布局
    mainVLayout = new QVBoxLayout(this);

    mainVLayout->addWidget(topFrame);
    mainVLayout->addSpacing(1);
    mainVLayout->addWidget(btmFrame);

    setLayout(mainVLayout);

}

MainWidget::~MainWidget()
{

}

//重新绘图事件
void MainWidget::paintEvent(QPaintEvent *event)
{
    //初始化画家并指定绘图设备
    QPainter painter(this);
    QImage Image;
    Image.load(MAINWIDGET_BACKGROUND1);
    QPixmap pixmap = QPixmap::fromImage(Image);

    QPixmap fitpixmap = pixmap.scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // 饱满填充
    //QPixmap fitpixmap = pixmap.scaled(this->width(), this->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    painter.drawPixmap(0, 0, fitpixmap);

}
