/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef TABLE_MODEL_HPP_
#define TABLE_MODEL_HPP_

#include <string>

#include <QtGui>

#include "constants.hpp"

typedef QModelIndex Index;

/** Model for list of teams */
class TableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    TableModel(QObject* parent, const QStringList& teams);

    int rowCount(const Index& parent = Index()) const;

    int columnCount(const Index& parent = Index()) const;

    QVariant data(const Index& index, int role =
                      Qt::DisplayRole) const;

    void updateData();

    void updateCellSize(int new_width, int new_height);

private:
    QStringList teams_;

    int cell_width_;
    int cell_height_;
};

#endif
