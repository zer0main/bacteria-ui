/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setTableViewModels() {
    ui->teamsList->setModel(teams_list_model_);
    ui->boardView->setModel(board_model_);
}

void MainWindow::initializeTeamsListModel(const QStringList& files) {
    QStringList teams;
    for (int i = 0; i < files.size(); i++) {
        teams.append(QFileInfo(files[i]).baseName());
    }
    teams_ = teams.size();
    teams_list_model_ = new TeamsListModel(this, teams);
}

void MainWindow::initializeModels(int width, int height, int bacteria) {
    model_ = QSharedPointer<Abstract::Model>
             (new Implementation::Model(width, height, bacteria, teams_));
    board_model_ = new TableModel(this, model_);
}

void MainWindow::configureTeamsList() {
    QTableView* view = ui->teamsList;
    view->setSelectionMode(QAbstractItemView::NoSelection);
    view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::configureBoardView() {
    QTableView* view = ui->boardView;
    view->setSelectionMode(QAbstractItemView::NoSelection);
    view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setResizeMode(QHeaderView::Stretch);
}

void MainWindow::on_fileButton_clicked() {
    QStringList file_names = QFileDialog::getOpenFileNames(
        this,
        tr("Open File"),
        "/home",
        ""
    );
    int max_teams = (MAX_WIDTH * MAX_HEIGHT) / 2;
    int min_teams = 0;
    int teams = file_names.size();
    if ((teams > min_teams) && (teams < max_teams)) {
        initializeTeamsListModel(file_names);
        ui->stackedWidget->setCurrentWidget(ui->inputpage);
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_playButton_clicked() {
    int width = ui->boardWidth->value();
    int height = ui->boardHeight->value();
    int bacteria = ui->bacteriaNumber->value();
    initializeModels(width, height, bacteria);
    setTableViewModels();
    configureTeamsList();
    configureBoardView();
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}
