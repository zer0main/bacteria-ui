/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GUI_GLOBALS_HPP_
#define GUI_GLOBALS_HPP_

#include <QtCore>

class BoardItemDelegate;

typedef QSharedPointer<BoardItemDelegate> BoardItemDelegatePtr;
typedef QModelIndex Index;

#endif
