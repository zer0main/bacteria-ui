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
    delete model_;
    delete ui;
}

void MainWindow::setTeamsListModel() {
    ui->teamsList->setModel(teams_list_model_);
}

void MainWindow::initializeTeamsListModel(const QStringList& files) {
    QStringList teams;
    for (int i = 0; i < files.size(); i++) {
        teams.append(QFileInfo(files[i]).baseName());
    }
    teams_ = teams.size();
    teams_list_model_ = new TableModel(this, teams);
    setTeamsListModel();
    configureTableView(ui->teamsList);
}

void MainWindow::configureTableView(QTableView* view) {
    view->setSelectionMode(QAbstractItemView::NoSelection);
    view->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    view->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::on_fileButton_clicked() {
    QStringList file_names = QFileDialog::getOpenFileNames(
        this,
        tr("Open File"),
        "/home",
        ""
    );
    if (file_names.size() != 0) {
        initializeTeamsListModel(file_names);
        ui->stackedWidget->setCurrentWidget(ui->inputpage);
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_playButton_clicked() {
    int size = ui->boardSize->value();
    int bacteria_number = ui->bacteriaNumber->value();
    model_ = new Implementation::Model(size, bacteria_number, teams_);
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}
