/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef GLOBALS_HPP_
#define GLOBALS_HPP_

#include <QtCore>

namespace Abstract {

class Model;

}

class BoardItemDelegate;

typedef QSharedPointer<const Abstract::Model> ConstModelPtr;
typedef QSharedPointer<Abstract::Model> ModelPtr;
typedef QSharedPointer<BoardItemDelegate> BoardItemDelegatePtr;

#endif
