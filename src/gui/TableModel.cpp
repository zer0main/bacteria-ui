/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

typedef QModelIndex Index;

TableModel::TableModel(QObject* parent) :
    QAbstractTableModel(parent) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return 1;
}

int TableModel::columnCount(const Index& /*parent*/) const {
    return 1;
}

QVariant TableModel::data(const Index& index,
                          int role) const {
    if (role == Qt::DecorationRole) {
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
