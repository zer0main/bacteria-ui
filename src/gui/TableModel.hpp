/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef TABLE_MODEL_HPP_
#define TABLE_MODEL_HPP_

#include <QtGui>

/** Model for QTableView */
class TableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    TableModel(QObject* parent);

    int rowCount(const QModelIndex& parent =
                     QModelIndex()) const;

    int columnCount(const QModelIndex& parent =
                        QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role =
                      Qt::DisplayRole) const;

    void updateData();
};

#endif
