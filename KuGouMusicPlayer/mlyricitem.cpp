#include "mlyricitem.h"

MLyricItem::MLyricItem(const QListWidgetItem &other) : QListWidgetItem(other)
{

}

MLyricItem::MLyricItem(const QIcon &icon, const QString &text, QListWidget *parent, int type) : QListWidgetItem(icon, text, parent, type)
{

}

MLyricItem::MLyricItem(const QString &text, QListWidget *parent, int type) : QListWidgetItem(text, parent, type)
{

}

MLyricItem::MLyricItem(QListWidget *parent, int type) : QListWidgetItem(parent, type)
{

}
