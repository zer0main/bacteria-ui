/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "BoardItemDelegate.hpp"

BoardItemDelegate::BoardItemDelegate(QTableView* view) :
    QStyledItemDelegate(view), view_(view) {
}

void BoardItemDelegate::paint(
    QPainter* painter,
    const QStyleOptionViewItem& option,
    const QModelIndex& index
) const {
    QVariant vr = index.data(Qt::DecorationRole);
    QImage base_image = vr.value<QImage>();
    int row_height = view_->rowHeight(0);
    int column_width = view_->columnWidth(0);
    QImage scaled_image = base_image.scaled(QSize(column_width,
                                                  row_height));
    painter->save();
    painter->drawImage(QPoint(index.column(), index.row()),
                      scaled_image);
    painter->restore();
}
