#include "mlyricitem.h"

MLyricItem::MLyricItem(const QListWidgetItem &other) : QListWidgetItem(other)
{
    setTextAlignment(Qt::AlignCenter);
}

MLyricItem::MLyricItem(const QIcon &icon, const QString &text, QListWidget *parent, int type) : QListWidgetItem(icon, text, parent, type)
{
    setTextAlignment(Qt::AlignCenter);
}

MLyricItem::MLyricItem(const QString &text, QListWidget *parent, int type) : QListWidgetItem(text, parent, type)
{
    setTextAlignment(Qt::AlignCenter);
}

MLyricItem::MLyricItem(QListWidget *parent, int type) : QListWidgetItem(parent, type)
{
    setTextAlignment(Qt::AlignCenter);
}
