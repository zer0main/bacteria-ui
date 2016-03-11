/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

TableModel::TableModel(QObject* parent, const QStringList& teams) :
    QAbstractTableModel(parent), teams_(teams) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return teams_.size();
}

int TableModel::columnCount(const Index& /*parent*/) const {
    return 1;
}

QVariant TableModel::data(const Index& index, int role) const {
    if (role == Qt::DecorationRole) {
        uint hash = qHash(teams_[index.row()]);
        return QColor(QRgb(static_cast<int>(hash)));
    } else if (role == Qt::DisplayRole) {
        return teams_[index.row()];
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
