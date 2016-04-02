/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef BOARD_ITEM_DELEGATE_HPP_
#define BOARD_ITEM_DELEGATE_HPP_

#include <QtGui>

class BoardItemDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit BoardItemDelegate(QTableView* view);

    void paint(
        QPainter* painter,
        const QStyleOptionViewItem& option,
        const QModelIndex& index
    ) const;

private:
    QTableView* view_;
};

#endif
