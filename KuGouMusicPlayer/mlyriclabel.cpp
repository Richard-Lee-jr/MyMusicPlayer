#include "mlyriclabel.h"
#include <QPropertyAnimation>
#include <QPalette>

MLyricLabel::MLyricLabel(QWidget *parent)
    : QLabel{parent}
{
    setFont(QFont("FangSong", 16));

//    QPropertyAnimation* animation = new QPropertyAnimation(this, "palette");
//    animation->setDuration(3000);

//    QPalette pe;
//    pe.setColor(QPalette::WindowText,Qt::white);
//    animation->setStartValue(pe);

//    QPalette end;
//    end.setColor(QPalette::WindowText, Qt::red);
//    animation->setEndValue(end);
//    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
