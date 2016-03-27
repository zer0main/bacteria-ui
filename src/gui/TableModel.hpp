/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef TABLE_MODEL_HPP_
#define TABLE_MODEL_HPP_

#include <QtGui>

#include "Model.hpp"

typedef QModelIndex Index;
typedef QSharedPointer<const Abstract::Model> ModelPtr;

/** Model for boardView */
class TableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    TableModel(QObject* parent, ModelPtr model, QStringList teams);

    int rowCount(const Index& parent = Index()) const;

    int columnCount(const Index& parent = Index()) const;

    QVariant data(const Index& index, int role =
                      Qt::DisplayRole) const;

    void updateData();

private:
    ModelPtr model_;

    QStringList teams_;
};

#endif
