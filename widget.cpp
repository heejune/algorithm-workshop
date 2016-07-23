#include "widget.h"
#include "ui_widget.h"
#include <QStringListModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listView->setItemDelegate(new ItemDelegate(ui->listView));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showList(std::vector<std::__1::wstring> items)
{
    QStringList numbers;
    for (const auto& e: items) {
        numbers << QString::fromWCharArray(e.c_str());
    }

    QAbstractItemModel *model = new QStringListModel(numbers);
    ui->listView->setModel(model);
}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    bool ok = false;
    index.data(Qt::DisplayRole).toString().toLong(&ok);
    if (ok) {
        // number
        // draw the row and its content

        // highlight
        painter->fillRect(option.rect, QColor(Qt::red));

        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());
        //painter->drawText(option.rect, index.model()->data(index, Qt::DisplayRole).toString());

        drawFocus(painter, option, option.rect);
    } else {
        QItemDelegate::paint(painter, option, index);
    }
}
