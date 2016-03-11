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

void MainWindow::setTeamsListModel() {
    ui->teamsList->setModel(teams_list_model_);
}

void MainWindow::initializeTeamsListModel(const QStringList& files) {
    Ints hashes;
    for (int i = 0; i < files.size(); i++) {
        uint hash = qHash(files[i]);
        hashes.push_back(static_cast<int>(hash));
    }
    teams_list_model_ = new TableModel(this, hashes);
    setTeamsListModel();
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
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}
