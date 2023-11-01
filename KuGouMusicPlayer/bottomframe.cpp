#include "bottomframe.h"

BottomFrame::BottomFrame(QWidget *parent) : QFrame(parent)
{
    init();

}

//初始化函数
void BottomFrame::init()
{

/*************************这里是BottomFrame的整体配置*********************************/

    //设置底部固定高度
    setFixedHeight(120);
    setStyleSheet(QString("QFrame{Background:rgba(255, 255, 255, 0);"
                          "background-color:rgba(0,0,0,0);"
                          "border-color:rgb(225,225,225);"
                          "border-width:0px;border-style: none;}"));    //solid
    //设置鼠标追踪
    setMouseTracking(true);


/*************************这里是成员变量的初始化*********************************/

    //需要一个垂直布局
    vLayout = new QVBoxLayout(this);

    //需要一个水平布局
    hLayout = new QHBoxLayout;
    //设置布局与控件的左右边距
    //hLayout->setMargin(1);

    //音频播放列表
    mdPlayList = new QMediaPlaylist(this);
    //mdPlayList->addMedia(QUrl::fromLocalFile("D:\\QTapplication\\KuGouMusicPlayer\\mp3\\yequ.mp3"));
    //设置播放模式(顺序播放，单曲循环，随机播放等)
    mdPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    //playlist->setCurrentIndex(1);

    my_player = new QMediaPlayer(this);
    my_player->setPlaylist(mdPlayList);
    my_player->setVolume(50);


    //时间歌曲名框架
    timeAndNameWidget = new QWidget(this);
    timeAndNameWidget->setFixedSize(96, 64);
    //时间歌曲名布局
    timeAndNameLayout = new QVBoxLayout();
    //音乐时间
    songTime = new MyButton();
    songTime->setParent(timeAndNameWidget);
    //时长按钮初始化
    songTime->setText("-/-");

    //滚动字幕
    scrollText = new MyScrollLabel();
    scrollText->setParent(timeAndNameWidget);
    //将这两个控件添加到时间歌曲名布局中去
    timeAndNameLayout->addWidget(scrollText);
    timeAndNameLayout->addWidget(songTime);
    timeAndNameWidget->setLayout(timeAndNameLayout);


    //上一曲
    pre = new MyButton(BEFORE_IMAGE_PATH, BEFORE_HOVER_IMAGE_PATH, BEFORE_PRESSED_IMAGE_PATH);
    pre->setParent(this);
    pre->setToolTip("上一曲");


//下面是代替方案
//    pre = new QPushButton(this);
//    //设置按钮大小
//    pre->setFixedSize(BUTTON_WIDTH32, BUTTON_HEIGHT32);
//    //设置按钮图标
//    pre->setIcon(QIcon(BEFORE_PRESSED_IMAGE_PATH));
//    //设置图标大小
//    pre->setIconSize(pre->size());
//    //pre->setStyleSheet("QPushButton{Background:rgba(255, 255, 255, 50)}");
//    //设置默认提示
//    //设置鼠标放在按钮上时的图标
//    pre->setCursor(Qt::PointingHandCursor);


    //播放
    play = new MyButton(PLAY_IMAGE_PATH, PLAY_HOVER_IMAGE_PATH, PLAY_PRESSED_IMAGE_PATH);
    play->setParent(this);
    play->setToolTip("播放");

    //下一曲
    next = new MyButton(NEXT_IMAGE_PATH, NEXT_HOVER_IMAGE_PATH, NEXT_PRESSED_IMAGE_PATH);
    next->setParent(this);
    next->setToolTip("下一曲");

    //音量
    voice = new MyButton(VOICE_IMAGE_PATH, VOICE_HOVER_IMAGE_PATH, VOICE_PRESSED_IMAGE_PATH);
    voice->setParent(this);
    voice->setToolTip("音量");

    //音乐列表
    list = new MyButton(LIST_IMAGE_PATH, LIST_HOVER_IMAGE_PATH, LIST_PRESSED_IMAGE_PATH);
    list->setParent(this);
    list->setToolTip("列表");


    //音量滑动块
    voiceSlider = new QSlider(Qt::Horizontal);
    //设置滑动块大小
    voiceSlider->resize(32, 32);
    //隐藏滑动块关闭
    //voiceSlider->setWindowFlag(Qt::FramelessWindowHint);
    //设置滑动条控件的最小值
    voiceSlider->setMinimum(0);
    //设置滑动条控件的最大值
    voiceSlider->setMaximum(100);
    //设置滑动条控件的值:my_player的音量大小
    voiceSlider->setValue(my_player->volume());
    //设置滑动条样式
    voiceSlider->setStyleSheet(voiceSliderStyle);



    //提升：优化滑动块样式
    //自定义滑动块风格在configfile.h中
    //设置为自定义样式


    //音乐进度滑动块
    songSlider = new QSlider(Qt::Horizontal, this);
    songSlider->setValue(0);
    //滑动块进度为当前音乐播放进度
    songSlider->setValue(my_player->position());
    //设置样式
    songSlider->setStyleSheet(songSliderStyle);




/************************这里进行信号连接******************************************************/

    //连接上一曲信号，点击上一曲时，TopFrame中songList中的item也要相应改变。
    //自定义上一曲按钮信号，点击时触发，并携带上一首歌曲索引
    connect(pre, &QPushButton::clicked, this, &BottomFrame::getPreClicked);

    //连接播放play按钮信号
    connect(play, &QPushButton::clicked, this, &BottomFrame::getPlayOrPauseClicked);

    //连接下一曲信号
    //也可声明槽函数代替lambda表达式
    connect(next, &QPushButton::clicked, this, &BottomFrame::getNextClicked);

    //滑动随音乐进度改变
    connect(my_player, &QMediaPlayer::positionChanged, this, &BottomFrame::updateSongSliderPosition);

    //切换歌曲时,进度条总长度随歌曲总时长改变
    connect(my_player, &QMediaPlayer::durationChanged, this, &BottomFrame::updateSongSliderDuration);

    //移动滑动块调整音乐进度, 会有卡顿. 所以这里使用slideerMoved信号而不是valueChanged信号
    connect(songSlider, &QSlider::sliderMoved, this, &BottomFrame::updateMyPlayerPosition);
    connect(songSlider, &QSlider::sliderPressed, this, &BottomFrame::slotSongSliderPressed);
    connect(songSlider, &QSlider::sliderMoved, this, &BottomFrame::slotSongSliderMoved);
    connect(songSlider, &QSlider::actionTriggered, this, &BottomFrame::slotSongSliderActionTrigged);

    //voice
    connect(voice, &QPushButton::clicked, this, &BottomFrame::slotVoiceClicked);

    //音量滑动块生改变时，my_player音量随之改变
    connect(voiceSlider, &QSlider::valueChanged, [&](){
        my_player->setVolume(voiceSlider->value());
    });

    //播放完毕自动切换下一首
    connect(my_player, &QMediaPlayer::mediaChanged, this, [&]{
        emit BottomFrame::nextClickedSignal(mdPlayList->currentIndex());
    });



/***********************这里设计BottomFrame中控件的布局**************************************/

    //将按钮添加到水平布局中
    hLayout->addStretch(0.7);
    hLayout->addSpacing(15);
    //hLayout->addStretch(0.7);//
    //hLayout->addSpacing(20);
    hLayout->addWidget(timeAndNameWidget);
    hLayout->addStretch(0.7);
    hLayout->addStretch(1);

    hLayout->addSpacing(25);
    hLayout->addWidget(pre);
    hLayout->addStretch(0.7);//
    hLayout->addWidget(play);
    hLayout->addStretch(0.7);//
    hLayout->addWidget(next);


    hLayout->addStretch(1);//
    hLayout->addWidget(voice);
    hLayout->addStretch(0.7);//
    hLayout->addWidget(voiceSlider);
    hLayout->addStretch(0.7);//
    hLayout->addWidget(list);
    hLayout->addStretch(0.7);//

    //将布局添加到frame中

    //垂直布局
    vLayout->addWidget(songSlider);
    vLayout->addLayout(hLayout);

    //初始化音量滑动块定时器
    //音量滑动块定时器
    voiceTimer = new QTimer(this);



}

/********************这里实现自己的成员函数***************************************/
//获得当前媒体的时间
QString BottomFrame::getSongTime(qint64 time)
{
    qint64 seconds=time/1000;   //歌曲总时长，s
    const qint64 minutes=seconds/60;    //分钟
    seconds-=minutes*60;                //然后得到具体秒，例time = 74000ms->seconds = 74s->minutes = 1m->seconds = 14->显示格式01:14
    return QString("%1:%2")
            .arg(minutes, 2, 10, QLatin1Char('0'))  //填充到%1位置，该位置值为minutes，宽度为2，十进制，填充字符为‘0’，例minuters = 1, 则显示01
            .arg(seconds, 2, 10, QLatin1Char('0')); //同理， secondes为14显示14

}


/********************这里重写继承自父类的虚函数************************************/

//重写鼠标移动函数
//void BottomFrame::mouseMoveEvent(QMouseEvent *event)
//{

//}

//重写绘图事件
//void BottomFrame::paintEvent(QPaintEvent *)
//{


//}


/***********************下面是自定义信号***************************************/



/************************下面是槽函数*************************************/

//移动播放进度条触发的槽函数
//切换歌曲时触发，更新当前播放歌曲播放时间
void BottomFrame::updateSongSliderDuration(qint64 duration)
{
    //测试：当前歌曲总时长
    qDebug() << "歌曲总时长：" << duration;
    //更改进度条
    songSlider->setRange(0,duration);//根据播放时长来设置滑块的范围
    songSlider->setEnabled(duration>0);
    songSlider->setPageStep(duration/1000);//以及每一步的步数，一秒一步

    //更改底部时长按钮的内容QString songTime
    songTime->setText("00:00/" + getSongTime(duration));

}

//接收歌曲位置改变，那么滑块的位置也要变
void BottomFrame::updateSongSliderPosition(qint64 position)
{
    songSlider->setValue(position);
    //显示当前时间进度songTime
    QString curPostion = getSongTime(position);
    //歌曲总时长
    QString duration = getSongTime(my_player->duration());
    //更新底部时长按钮文本
    songTime->setText(curPostion + "/" + duration);

    //同时通知mainWidget同步更新topframe中的歌词
    emit signalUpdateLyrics(position);
}

//移动滑动块，改变歌曲进度
void BottomFrame::updateMyPlayerPosition(int value)
{
    QMediaPlayer::MediaStatus sts = my_player->mediaStatus();
    if (sts == QMediaPlayer::NoMedia)
    {
        songSlider->setValue(0);
        qDebug() << "当前没有播放歌曲，无法移动进度！";
        return;
    }
    //前面设置了setRange(0,duration)，所以得到的value是ms，毫秒
    //防止卡顿先暂停歌曲
    my_player->pause();
    //setPosition(), 设置当前播放位置
    my_player->setPosition(value);
    //然后更新底部时长按钮
    //歌曲总时长
    QString duration = getSongTime(my_player->duration());
    //显示当前时间进度songTime
    QString curPostion = getSongTime(value);
    //更新底部时长按钮文本
    songTime->setText(curPostion + "/" + duration);
    //设置完后继续播放
    my_player->play();
}

void BottomFrame::slotSongSliderPressed()
{
    qDebug() << "BottomFrame::SlotSongSliderPressed()";
    QMediaPlayer::MediaStatus sts = my_player->mediaStatus();
    if (sts == QMediaPlayer::NoMedia)
    {
        songSlider->setValue(0);
        qDebug() << "当前没有播放歌曲，无法移动进度！";
        return;
    }
}

void BottomFrame::slotSongSliderMoved()
{
    QMediaPlayer::MediaStatus sts = my_player->mediaStatus();
    if (sts == QMediaPlayer::NoMedia)
    {
        songSlider->setValue(0);
        qDebug() << "当前没有播放歌曲，无法移动进度！";
        return;
    }
}

void BottomFrame::slotSongSliderActionTrigged()
{
    qDebug() << "BottomFrame::SlotSongSliderActionTrigged()";
    QMediaPlayer::MediaStatus sts = my_player->mediaStatus();
    if (sts == QMediaPlayer::NoMedia)
    {
        songSlider->setValue(0);
        qDebug() << "当前没有播放歌曲，无法移动进度！";
        return;
    }
}

void BottomFrame::slotVoiceClicked()
{
    int nCurValue = voiceSlider->value();
    if (nCurValue == 0)
    {
        voice->updateBtnImg(VOICE_IMAGE_PATH, VOICE_HOVER_IMAGE_PATH, VOICE_PRESSED_IMAGE_PATH);
        voiceSlider->setValue(50);
    }
    else
    {
        voice->updateBtnImg(VOICE_OFF_IMAGE_PATH, VOICE_OFF_HOVER_IMAGE_PATH, VOICE_OFF_PRESSED_IMAGE_PATH);
        voiceSlider->setValue(0);
    }
}

//接收TopFrame中add按钮按下信号的槽函数
void BottomFrame::getAddClicked(QString songPath)
{
    if (songPath == "") return;
    mdPlayList->addMedia(QUrl::fromLocalFile(songPath));
}

//响应TopFrame中的del按钮按下信号
void BottomFrame::getDelClicked()
{
    //清空播放列表mdPlayList
    mdPlayList->clear();
    //清空播放歌曲信息
    songTime->setText("-/-");
    scrollText->setText("正在播放：暂无播放");
}

//响应TopFrame中songList的itemDoubleClicked信号
void BottomFrame::getItemDoubleClicked(int index, const QString& text)
{
    //播放双击的歌曲，根据index索引
    //设置当前音乐
    mdPlayList->setCurrentIndex(index);
    //如果当前播播放状态为未播放，下一曲后设置播放按钮图标
    if (my_player->state() == 0 || my_player->state() == 2)
    {

        play->updateBtnImg(STOP_IMAGE_PATH, STOP_HOVER_IMAGE_PATH, STOP_PRESSED_IMAGE_PATH);
        play->setIconSize(play->size());
    }
    //设置当前播放歌曲名
    //重置滚动歌曲名的初始位置
    scrollText->setCurIndex(0);
    scrollText->setText(text);

    //播放
    my_player->play();

}


//响应上一曲点击信号的槽函数
void BottomFrame::getPreClicked()
{
    //得到当前列表歌曲数量
    int songNum = mdPlayList->mediaCount();

    if (songNum == 0)
    {
        qDebug() << "歌曲列表为空，请添加歌曲！";
        return;
    }

    //得到当前播放歌曲索引
    int curIndex = mdPlayList->currentIndex();
    //判断当前播放歌曲是否是第一首
    if (--curIndex < 0)
    {
        //是则播放第一首
        curIndex = 0;
    }
    //不是则播放上一首
    //设置列表当前音乐索引
    mdPlayList->setCurrentIndex(curIndex);
    //播放当前索引音乐
    //如果当前播播放状态为未播放，下一曲后设置播放按钮图标
    if (my_player->state() == 0 || my_player->state() == 2)
    {
        //qDebug() << "something";
        play->updateBtnImg(STOP_IMAGE_PATH, STOP_HOVER_IMAGE_PATH, STOP_PRESSED_IMAGE_PATH);
        play->setIconSize(play->size());
    }


    //播放歌曲
    my_player->play();


    //最后手动触发自定义上一曲按钮信号
    emit BottomFrame::preClickedSignal(curIndex);
}

//响应播放/暂停按钮点击信号的槽函数
void BottomFrame::getPlayOrPauseClicked()
{
    if (mdPlayList->isEmpty())
    {
        qDebug() << "歌曲列表为空，请添加歌曲！";
        return;
    }
    //测试：歌曲长度
    //qDebug() << my_player->duration();
    //qDebug() << my_player->bufferStatus();
    if (my_player->state() == 0 || my_player->state() == 2)    //播放停止状态 或 播放暂停状态
    {
        play->updateBtnImg(STOP_IMAGE_PATH, STOP_HOVER_IMAGE_PATH, STOP_PRESSED_IMAGE_PATH);
        play->setToolTip("播放");
        my_player->play();
        //更新歌曲信息
        emit BottomFrame::updateSongInfo(mdPlayList->currentIndex());
    }
    else if (my_player->state() == 1)   //播放状态
    {
        play->updateBtnImg(PLAY_IMAGE_PATH, PLAY_HOVER_IMAGE_PATH, PLAY_PRESSED_IMAGE_PATH);
        play->setToolTip("暂停");
        my_player->pause();
    }

}

//响应下一曲按钮点击信号的槽函数
void BottomFrame::getNextClicked()
{
    //获取当前list歌曲数量
    int songNum = mdPlayList->mediaCount();

    if (songNum == 0)
    {
        qDebug() << "播放列表为空，请添加歌曲！";
        return;
    }

    //获得当前播放歌曲索引
    int curIndex = mdPlayList->currentIndex();
    //判断当前播放歌曲是否是最后一首
    if (++curIndex >= songNum)
    {
        //是则回到第一首
        curIndex = 0;
    }

    //不是则播放下一曲
    //设置当前音乐
    mdPlayList->setCurrentIndex(curIndex);
    //滚动到当前音乐

    //如果当前播播放状态为未播放，下一曲后设置播放按钮图标
    if (my_player->state() == 0 || my_player->state() == 2)
    {
        //play->setIcon(QIcon(STOP_IMAGE_PATH));
        play->updateBtnImg(STOP_IMAGE_PATH, STOP_HOVER_IMAGE_PATH, STOP_PRESSED_IMAGE_PATH);
        play->setIconSize(play->size());
    }

    //播放当前音乐
    my_player->play();

    //最后手动触发下一曲按钮信号
    //qDebug() << "BottomFrame::getNextClicked index: " << curIndex;
    emit BottomFrame::nextClickedSignal(curIndex);
}
//111
