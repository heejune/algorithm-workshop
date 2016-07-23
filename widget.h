#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <string>
#include <QItemDelegate>
#include <QPainter>

namespace Ui {
class Widget;
}

class ItemDelegate : public QItemDelegate
{
public:
    explicit ItemDelegate(QObject *parent = 0) : QItemDelegate(parent) {}
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void showList(std::vector<std::wstring> items);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
