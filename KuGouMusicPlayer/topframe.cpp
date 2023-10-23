#include "topframe.h"

TopFrame::TopFrame(QWidget *parent) : QFrame(parent)
{

/************这里是TopFrame整体配置****************************/

    //设置固定宽度
    resize(1280, 660);
    setStyleSheet(QString("QFrame{Background:rgba(255, 255, 255, 0);"    //第四个参数设置控件背景透明度， 0表示完全透明
                          "background-color:rgba(0,0,0,0);"
                          "border-color:rgb(225,225,225);"
                          "border-width:0px;border-style: solid;}"));

    //topFrame 框架内的文字风格
    //字体对象
    QFont f;
    //字体风格
    f.setFamily("FangSong");  //仿宋：FangSong  宋体：SimSun
    //字体大小
    f.setPointSize(20);
    //字体下划线
    f.setUnderline(true);


/*****************这里是类成员初始化**************************************/


    //水平布局：topFrame总体布局
    topHlayout = new QHBoxLayout(this);


    //左侧框架：歌词框架
    lyricFrame = new QFrame(this);
    //左侧框架水平布局
    lyricHlayout = new QHBoxLayout(lyricFrame);

    //左侧框架里的控件
    //歌词控件
    lyrics = new QLabel("暂无歌词", lyricFrame);
    lyrics->setFont(f);
    //lyrics->move((lyricFrame->width() - lyrics->width()) / 2, (lyricFrame->height() - lyrics->height()) / 2);


    //右侧框架
    listFrame = new QFrame(this);
    //右侧框架需要固定尺寸
    listFrame->setFixedSize(300, 660);

    //右侧框架垂直布局
    listVlayout = new QVBoxLayout(listFrame);
    //右侧框架上半部分水平布局
    listTopHlayout = new QHBoxLayout;


    //右侧框架里的控件
    //添加按钮
    add = new MyButton(ADD_NORMAL_PATH, ADD_PRESSED_PATH);
    add->setParent(listFrame);
    //add->setText("添加歌曲");


    //删除按钮
    del = new MyButton(DELETE_NORMAL_PATH, DELETE_PRESSED_PATH);
    del->setParent(listFrame);
    //del->setText("删除歌曲");


    //隐藏按钮
    hide = new MyButton(HIDE_NORMAL_PATH, HIDE_PRESSED_PATH);
    hide->setParent(listFrame);
    //hide->setText("隐藏");

    //歌曲列表控件
    songList = new QListWidget(listFrame);
    f.setPointSize(11);
    songList->setFont(f);
    //songList->addItem(QString("test"));
    songList->resize(300, 600);
    //歌曲列表滑动块风格
    songList->verticalScrollBar()->setStyleSheet(songListSliderStyle);
    songList->horizontalScrollBar()->setStyleSheet(songListSliderStyle);

    //添加完成后默认隐藏歌曲列表
    listFrame->hide();



/********************下面将控件添加到对应布局中区*****************************/
    //添加到歌词框架布局中去
    lyricHlayout->addStretch(1);
    lyricHlayout->addWidget(lyrics);
    lyricHlayout->addStretch(1);


    //添加到右侧框架上半部分水平布局
    listTopHlayout->addWidget(add);
    listTopHlayout->addWidget(del);
    //添加到右侧框架上半部分水平布局
    listTopHlayout->addWidget(hide);
    //将右侧框架上半部分水平布局放入右侧垂直布局中
    listVlayout->addLayout(listTopHlayout);

    //将歌曲列表控件添加到右侧布局中
    listVlayout->addWidget(songList);
    //listVlayout->addStretch(1);

/********************下面是信号连接***************************************/

    //建立右侧按钮信号连接
    //点击hide按钮隐藏歌曲列表songList
    connect(hide, &QPushButton::clicked, [&]{
        listFrame->hide();
        //listVlayout->addStretch(2);
    });

    //点击添加歌曲按钮弹出文件手动添加, 得到歌曲路径并触发addClicked 自定义信号。该信号在BottomFrame中被接收
    connect(add, &QPushButton::clicked, [&]{

        //添加多个音频文件
        //参数：父对象， 浮动框标题，默认打开路径， 过滤器
        QStringList songListPath = QFileDialog::getOpenFileNames(this,QString::fromLocal8Bit("文件"), "D:\\music"); // QString::fromLocal8Bit("音频文件(*.mp3")
        if (!songListPath.isEmpty())
        {
            for (int i = 0; i < songListPath.size(); i++)
            {
                QString songPath = QDir::toNativeSeparators(songListPath.at(i));
                //mdPlayList->addMedia(QUrl::fromLocalFile(path));
                //每得到一个路径，抛出一个信号，在mainWidget中接收
                emit TopFrame::addClickedSignal(songPath);
                //QString songName =path.split("\\").last();
                songList->addItem((songPath.split("\\").last()).split(".").first());
            }
        }

    });

    //点击del按钮，清空歌曲列表，同时清空bottomFrame中的歌单mdPlayList
    connect(del, &QPushButton::clicked, [&]{
        songList->clear();
        emit TopFrame::delClickedSignal();
    });

    //双击songList中的选项时发出双击信号
    connect(songList, &QListWidget::itemDoubleClicked, this, &TopFrame::getItemDoubleClicked);

    //最后将左右两个框架添加到总体水平布局中
    topHlayout->addWidget(lyricFrame);
    topHlayout->addWidget(listFrame);


}

//重新绘图事件
//void TopFrame::paintEvent(QPaintEvent *)
//{

//}



//自定义信号
//点击添加按钮add发送的信号
//void TopFrame::addClickedSignal(QString songPath)
//{
//    //if (songPath == "") return;
//    //得到歌曲路径
//    //songPath = QFileDialog::getOpenFileName(this, "添加歌曲", "路径");
//    //测试，打印歌曲路径
//    qDebug() << "歌曲路径： " << songPath;
//}


/*************************************下面是槽函数********************************/

//接收ButtomFrame中list按钮点击信号的槽函数
void TopFrame::getListClicked(bool checked)
{
    listFrame->show();
}


//itemDoubleClicked槽函数
void TopFrame::getItemDoubleClicked(QListWidgetItem *item)
{
    //获得选中行的row
    int index = songList->row(item);
    //获得该行内容
    QString text = item->text();
    qDebug() << "双击行内容：" << text;
    emit TopFrame::itemDoubleclickedSignal(index, text);
}

//接收BottomFrame中的pre按钮点击信息的槽函数
void TopFrame::getPreClicked(int index)
{
    //得到上一曲的item
    QListWidgetItem* preItem = songList->item(index);
    //将该item设置为当前item
    songList->setCurrentItem(preItem);
    //通过手动触发自定义信号来更改当前播放歌曲名
    emit updateSongName(index, preItem->text());

}

//接收BottomFrame中next按钮点击信号的槽函数
void TopFrame::getNextClicked(int index)
{
    //测试
    //qDebug() << "TopFrame::getNextClicked index : " << index;
    //得到下一曲的item
    QListWidgetItem* Item = songList->item(index);
    //将该item设置为当前item
    songList->setCurrentItem(Item);

    //通过手动触发自定义信号来更改当前播放歌曲名, 在mainWidget中接收
    emit updateSongName(index, Item->text());
}


void TopFrame::getSongInfo(int index)
{
    QListWidgetItem* Item = songList->item(index);
    //通过手动触发自定义信号来更改当前播放歌曲名, 在mainWidget中接收
    emit updateSongName(index, Item->text());
}
