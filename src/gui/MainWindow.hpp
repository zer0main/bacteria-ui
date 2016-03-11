/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui>

#include "TableModel.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    TableModel* teams_list_model_;

    void setTeamsListModel();

private slots:
    void on_fileButton_clicked();

    void on_quitButton_clicked();

    void on_playButton_clicked();
};

#endif // MAINWINDOW_HPP_
