/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TeamsListModel.hpp"

TeamsListModel::TeamsListModel(
    QObject* parent,
    ConstModelPtr model,
    const QStringList* teams
)
    : QAbstractTableModel(parent)
    , model_(model)
    , teams_(teams)
{
}

int TeamsListModel::rowCount(const Index& /*parent*/) const {
    return teams_->size();
}

int TeamsListModel::columnCount(const Index& /*parent*/) const {
    return 1;
}

QVariant TeamsListModel::data(const Index& index, int role) const {
    int team_number = index.row();
    QString team = (*teams_)[team_number];
    if (role == Qt::DecorationRole) {
        uint hash = qHash(team);
        return QColor(QRgb(static_cast<int>(hash)));
    } else if (role == Qt::DisplayRole) {
        QString team_name = QFileInfo(team).baseName();
        return team_name;
    } else if (role == Qt::FontRole) {
        return getDataFont(team_number);
    } else if (role == Qt::ForegroundRole) {
        return getForeground(team_number);
    }
    return QVariant();
}

void TeamsListModel::updateData() {
    reset();
}

QColor TeamsListModel::getForeground(int team_number) const {
    bool defeated = (model_->getBacteriaNumber(team_number) <= 0);
    return ((defeated) ? Qt::red : Qt::black);
}

QFont TeamsListModel::getDataFont(int team_number) const {
    QFont font;
    bool defeated = (model_->getBacteriaNumber(team_number) <= 0);
    if (defeated) {
        font.setStrikeOut(true);
    }
    return font;
}
