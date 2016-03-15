/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

TableModel::TableModel(
    QObject* parent,
    int size,
    int bacteria,
    int teams
)
    : QAbstractTableModel(parent)
    , model_(new Implementation::Model(size, bacteria, teams))
{
}

TableModel::~TableModel() {
    delete model_;
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return model_->size();
}

int TableModel::columnCount(const Index& /*parent*/) const {
    return model_->size();
}

QVariant TableModel::data(const Index& index, int role) const {
    if (role == Qt::DisplayRole) {
        Abstract::Model::CellState state =
            model_->cellState(index.column(), index.row());
        if (state == Abstract::Model::BACTERIUM) {
            return model_->getTeam(index.column(), index.row());
        } else {
            return 0;
        }
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
