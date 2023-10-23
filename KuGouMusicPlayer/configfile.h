#ifndef CONFIGFILE_H
#define CONFIGFILE_H
#include <QSlider>

/************mainWindow资源配置************************/
const qint32 MAIN_WINDOW_WIDTH = 1280;  //mainWindow 窗口宽度
const qint32 MAIN_WINDOW_HERGHT = 780;  //mainWindow 窗口高度
const qint32 TOP_FRAME_WIDTH = 800;
const qint32 TOP_FRAME_HEIGHT = 500;
const qint32 BOTTOM_FRAME_WIDTH = 800;
const qint32 BOTTOM_FRAME_HEIGHT = 100;


//相对路径
const QString MAINWIDGET_ICON = ":/images/kugou.png";
const QString MAINWIDGET_BACKGROUND1 = ":/images/mainwidget/wallhaven.png";
const QString MAINWIDGET_BACKGROUND2 = ":/images/mainwidget/manwei.png";


/**************顶部控件资源配置***************************/
//相对路径
const QString ADD_NORMAL_PATH = ":/images/test1/add_normal.png";
const QString ADD_HOVER_PATH = ":/images/test1/add_hover.png";
const QString ADD_PRESSED_PATH = ":/images/test1/add_pressed.png";

const QString DELETE_NORMAL_PATH = ":/images/test1/delete_normal.png";
const QString DELETE_HOVER_PATH = ":/images/test1/delete_hover.png";
const QString DELETE_PRESSED_PATH = ":/images/test1/delete_pressed.png";

const QString HIDE_NORMAL_PATH = ":/images/test1/hide_normal.png";
const QString HIDE_HOVER_PATH = ":/images/test1/hide_hover.png";
const QString HIDE_PRESSED_PATH = ":/images/test1/hide_pressed.png";


/************底部控件资源配置***************************/
//相对路径
const QString PLAY_IMAGE_PATH = ":/images/test1/play_normal.png";
const QString PLAY_HOVER_IMAGE_PATH = ":/images/test1/play_hover.png";
const QString PLAY_PRESSED_IMAGE_PATH = ":/images/test1/play_pressed.png";

const QString STOP_IMAGE_PATH = ":/images/test1/stop_normal.png";
const QString STOP_HOVER_IMAGE_PATH = ":/images/test1/stop_hover.png";
const QString STOP_PRESSED_IMAGE_PATH = ":/images/test1/stop_pressed.png";

const QString BEFORE_IMAGE_PATH = ":/images/test1/before_normal.png";
const QString BEFORE_HOVER_IMAGE_PATH = ":/images/test1/before_hover.png";
const QString BEFORE_PRESSED_IMAGE_PATH = ":/images/test1/before_pressed.png";

const QString NEXT_IMAGE_PATH = ":/images/test1/next_normal.png";
const QString NEXT_HOVER_IMAGE_PATH = ":/images/test1/next_hover.png";
const QString NEXT_PRESSED_IMAGE_PATH = ":/images/test1/next_pressed.png";

const QString VOICE_IMAGE_PATH = ":/images/test1/voice_normal.png";
const QString VOICE_HOVER_IMAGE_PATH = ":/images/test1/voice_hover.png";
const QString VOICE_PRESSED_IMAGE_PATH = ":/images/test1/voice_pressed.png";

const QString VOICE_OFF_IMAGE_PATH = ":/images/test1/voice_off_normal.png";
const QString VOICE_OFF_HOVER_IMAGE_PATH = ":/images/test1/voice_off_hover.png";
const QString VOICE_OFF_PRESSED_IMAGE_PATH = ":/images/test1/voice_off_pressed.png";

const QString LIST_IMAGE_PATH = ":/images/test1/list_normal.png";
const QString LIST_HOVER_IMAGE_PATH = ":/images/test1/list_hover.png";
const QString LIST_PRESSED_IMAGE_PATH = ":/images/test1/list_pressed.png";

const QString SUIJU_IMAGE_PATH = ":/images/test1/suiji_normal.png";
const QString SUIJU_HOVER_PATH = ":/images/test1/suiji_normal.png";
const QString SUIJU_PRESSED_IMAGE_PATH = ":/images/test1/suiji_pressed.png";

const QString SHUNXU_IMAGE_PATH = ":/images/test1/shunxu_normal.png";
const QString SHUNXU_HOVER_IMAGE_PATH = ":/images/test1/shunxu_hover.png";
const QString SHUNXU_PRESSED_IMAGE_PATH = ":/images/test1/shunxu_pressed.png";

const qint32 BUTTON_WIDTH64 = 64;       //各种按钮大小
const qint32 BUTTON_HEIGHT64 = 64;
const qint32 BUTTON_WIDTH32 = 32;
const qint32 BUTTON_HEIGHT32 = 32;
const qint32 BUTTON_WIDTH48 = 48;
const qint32 BUTTON_HEIGHT48 = 48;


//自定义滑动块风格
const QString sliderStyle =
                                "QScrollBar:vertical"
                                "{"
                                "border: none;"
                                "background: transparent;"
                                "width: 0px;"
                                "}";


//QListWidget中的滑动条
const QString songListSliderStyle = "QSlider::groove:horizontal {"
                                 "border: 1px solid #bbb;"
                                 "background: blue;"
                                 "height: 1px;"
                                 "border-radius: 1px;}"

                                 "QSlider::sub-page:horizontal {"
                                 "background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,stop: 0 #66e, stop: 1 #bbf);"//
                                 "background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #bbf, stop: 1 #55f);"//qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #bbf, stop: 1 #55f)
                                 "border: 1px solid blue;"//#777
                                 "height: 10px;"
                                 "border-radius: 4px;"
                                 "}"

                                 "QSlider::add-page:horizontal {"
                                 "background: #fff;"    //
                                 "border: 1px solid #777;"
                                 "height: 10px;"
                                 "border-radius: 4px;"
                                 "}"

                                 "QSlider::handle:horizontal {"
                                 "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #eee, stop:1 #ccc);"
                                 "border: 1px solid #777;"
                                 "width: 2px;"
                                 "margin-top: -2px;"
                                 "margin-bottom: -2px;"
                                 "border-radius: 2px;"
                                 "}"

                                 "QSlider::handle:horizontal:hover {"
                                 "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #fff, stop:1 #ddd);"
                                 "border: 1px solid #444;"
                                 "border-radius: 4px;"
                                 "}"

                                 "QSlider::sub-page:horizontal:disabled {"
                                 "background: #bbb;"
                                 "border-color: #999;"
                                 "}"

                                 "QSlider::add-page:horizontal:disabled {"
                                 "background: #eee;"
                                 "border-color: #999;"
                                 "}"

                                 "QSlider::handle:horizontal:disabled {"
                                 "background: #eee;"
                                 "border: 1px solid #aaa;"
                                 "border-radius: 4px;"
                                 "}";

//音乐进度条
const QString songSliderStyle = "QSlider::groove:horizontal {"
                                 "border: none;"
                                 "background: rgb(21, 175, 255);"
                                 "height: 1px;"
                                 "border-radius: 1px;}"

                                 "QSlider::sub-page:horizontal {"
                                 "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #15AFFF, stop: 1 #15AFFF);"
                                 "border: none;"
                                 "}"

                                 "QSlider::add-page:horizontal {"
                                 "background: #fff;"
                                 "border: none;"
                                 "border-radius: 1px;"
                                 "}"

                                 "QSlider::handle:horizontal {"
                                 "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #15AFFF, stop:1 #15AFFF);"
                                 "border: none;"
                                 "width: 8px;"
                                 "margin-top: -3px;"
                                 "margin-bottom: -3px;"
                                 "border-radius: 3px;"
                                 "}"

                                "QSlider::handle:horizontal:hover {"
                                "background: white;"
                                "border: none;"
                                "border-radius: 3px;"
                                "}";


//音量进度条
const QString voiceSliderStyle = "QSlider::groove:horizontal {"
        "border: none;"
        "background: rgb(21, 175, 255);"
        "height: 1px;"
        "border-radius: 2px;"
        "}"

        "QSlider::sub-page:horizontal {"
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #15AFFF, stop: 1 #15AFFF);"
        "border: none;"
        //"height: 3px;"
        "border-radius: 3px;"
        "}"

        "QSlider::add-page:horizontal {"
        "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 white, stop: 1 white);"
        "border: none;"
        //"height: 3px;"
        "border-radius: 0px;"
        "}"

        "QSlider::handle:horizontal {"
        "background: rgb(21, 175, 255);" //qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #15AFFF, stop:1 #EB3324)
        "border: none;"
        "width: 8px;"        //句柄大小
        "margin-top: -3px;"
        "margin-bottom: -3px;"
        "border-radius: 3px;"
                                 "}"

        "QSlider::handle:horizontal:hover {"
        "background: white;"     //qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #15AFFF, stop:1 15AFFF)
        "border: none;"
        "border-radius: 3px;"
                                 "}";

        //"QSlider::sub-page:horizontal:disabled {"
        //"background: blue;"     //#bbb
        //"border-color: #999;"
        //"}"

        //"QSlider::add-page:horizontal:disabled {"
        //"background: blue;"         //#eee
        //"border-color: #999;"
        //"}"

        //"QSlider::handle:horizontal:disabled {"
        //"background: blue;"             //#eee
        //"border: 1px solid #aaa;"
        //"border-radius: 4px;"
        //"}";


#endif // CONFIGFILE_H
