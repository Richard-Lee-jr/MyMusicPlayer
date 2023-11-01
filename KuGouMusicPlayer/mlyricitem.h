#ifndef MLYRICITEM_H
#define MLYRICITEM_H

#include <QListWidgetItem>

class MLyricItem : public QListWidgetItem
{
    //Q_OBJECT
public:
    MLyricItem(const QListWidgetItem &other);
    MLyricItem(const QIcon &icon, const QString &text, QListWidget *parent = nullptr, int type = Type);
    MLyricItem(const QString &text, QListWidget *parent = nullptr, int type = Type);
    MLyricItem(QListWidget *parent = nullptr, int type = Type);
};

#endif // MLYRICITEM_H
