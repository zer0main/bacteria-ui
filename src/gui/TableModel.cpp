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
        int pm_height, pm_width;
        if (teams_.size() <= Gui::MIN_TEAMS) {
            pm_height =
                static_cast<int>(cell_height_ * Gui::MIN_SIZE_PROPORTION);
        } else {
            pm_height =
                static_cast<int>(cell_height_ * Gui::MAX_SIZE_PROPORTION);
        }
        pm_width = pm_height * 2;
        QPixmap pm(pm_width, pm_height);
        pm.fill(QColor(QRgb(static_cast<int>(hash))));
        return pm;
    } else if (role == Qt::DisplayRole) {
        return teams_[index.row()];
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}

void TableModel::updateCellSize(int new_width, int new_height) {
    cell_width_ = new_width;
    cell_height_ = new_height;
}
