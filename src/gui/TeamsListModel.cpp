/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TeamsListModel.hpp"

TeamsListModel::TeamsListModel(QObject* parent, const QStringList& teams) :
    QAbstractTableModel(parent), teams_(teams) {
}

int TeamsListModel::rowCount(const Index& /*parent*/) const {
    return teams_.size();
}

int TeamsListModel::columnCount(const Index& /*parent*/) const {
    return 1;
}

QVariant TeamsListModel::data(const Index& index, int role) const {
    if (role == Qt::DecorationRole) {
        uint hash = qHash(teams_[index.row()]);
        return QColor(QRgb(static_cast<int>(hash)));
    } else if (role == Qt::DisplayRole) {
        return teams_[index.row()];
    }
    return QVariant();
}

void TeamsListModel::updateData() {
    reset();
}