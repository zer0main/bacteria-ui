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

void MainWindow::updateTeamsList(QStringList file_names) {
    QLabel* list = ui->teamsList;
    list->setText("<b>Teams:</b>");
    for (int i = 0; i < file_names.size(); i++) {
        list->setText(list->text() + file_names[i]);
    }
}

void MainWindow::on_fileButton_clicked() {
    QStringList file_names = QFileDialog::getOpenFileNames(
        this,
        tr("Open File"),
        "/home",
        ""
    );
    updateTeamsList(file_names);
    if (file_names.size() != 0) {
        ui->stackedWidget->setCurrentWidget(ui->inputpage);
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}
