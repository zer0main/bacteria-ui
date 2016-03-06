/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <QtGui>

#include "MainWindow.hpp"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
