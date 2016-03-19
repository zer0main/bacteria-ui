/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui>

#include "TeamsListModel.hpp"
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

    TeamsListModel* teams_list_model_;

    TableModel* board_model_;

    QSharedPointer<Abstract::Model> model_;

    int teams_;

    void setTableViewModels();

    void initializeTeamsListModel(const QStringList& file_names);

    void initializeModels(int width, int height, int bacteria_number);

    void configureTeamsList();

    void configureBoardView();

private slots:
    void on_fileButton_clicked();

    void on_quitButton_clicked();

    void on_playButton_clicked();
};

#endif // MAINWINDOW_HPP_
