/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

TableModel::TableModel(QObject* parent, Ints hashes) :
    QAbstractTableModel(parent), hashes_(hashes) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return 1;
}

int TableModel::columnCount(const Index& /*parent*/) const {
    return hashes_.size();
}

QVariant TableModel::data(const Index& index, int role) const {
    if (role == Qt::DecorationRole) {
        return QColor(QRgb(hashes_[index.column()]));
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
