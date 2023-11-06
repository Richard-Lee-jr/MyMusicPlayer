#-------------------------------------------------
#
# Project created by QtCreator 2021-03-30T14:59:46
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KuGouMusicPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#win32:QMAKE_CXXFLAGS += -execution-charset:utf-8
#win32:QMAKE_CXXFLAGS += -source-charset:utf-8
win32:QMAKE_CXXFLAGS += -utf-8

SOURCES += \
        main.cpp \
    bottomframe.cpp \
    mainWidget.cpp \
    mlyricitem.cpp \
    topframe.cpp \
    mybutton.cpp \
    myscrolllabel.cpp

HEADERS += \
    mainWidget.h \
    bottomframe.h \
    configfile.h \
    mlyricitem.h \
    topframe.h \
    mybutton.h \
    myscrolllabel.h

RESOURCES += \
    res.qrc



# 平台信息
win32:contains(QT_ARCH, i386) {
    PLATFORM = Windows
    ARCHITECTURE = x86
}

win32:contains(QT_ARCH, x86_64) {
    PLATFORM = Windows
    ARCHITECTURE = x64
}

unix:!macx:contains(QT_ARCH, x86_64) {
    PLATFORM = Linux
    ARCHITECTURE = x64
}

unix:!macx:contains(QT_ARCH, arm64) {
    PLATFORM = Linux
    ARCHITECTURE = aarch64
}

unix:!macx:contains(QT_ARCH, aarch64) {
    PLATFORM = Linux
    ARCHITECTURE = aarch64
}

DESTDIR = $$sprintf($$PWD/../Output/bin_%1_%2_Qt%3, $$PLATFORM, $$ARCHITECTURE, $$QT_VERSION)


