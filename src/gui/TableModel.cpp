/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

TableModel::TableModel(
    QObject* parent,
    ModelPtr model,
    QStringList teams
)
    : QAbstractTableModel(parent)
    , model_(model)
    , teams_(teams)
{
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return model_->getWidth();
}

int TableModel::columnCount(const Index& /*parent*/) const {
    return model_->getHeight();
}

QVariant TableModel::data(const Index& index, int role) const {
    if (role == Qt::DisplayRole) {
        Abstract::CellState state =
            model_->cellState(index.row(), index.column());
        if (state == Abstract::BACTERIUM) {
            return model_->getTeam(index.row(), index.column());
        } else {
            return -1;
        }
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
