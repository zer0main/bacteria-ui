/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

TableModel::TableModel(
    QObject* parent,
    ConstModelPtr model,
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
    if (role == Qt::DecorationRole) {
        Abstract::CellState state =
            model_->cellState(index.row(), index.column());
        QImage image(QSize(100, 100), QImage::Format_ARGB32);
        if (state == Abstract::BACTERIUM) {
            int team = model_->getTeam(index.row(), index.column());
            uint hash = qHash(teams_[team]);
            QPainter painter(&image);
            painter.setBrush(QColor(QRgb(static_cast<int>(hash))));
            painter.drawEllipse(0, 0, 100, 100);
        } else {
            image.fill(Qt::white);
        }
        return image;
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
