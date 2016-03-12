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

void MainWindow::resizeEvent(QResizeEvent* event) {
    QWidget* current_page = ui->stackedWidget->currentWidget();
    if (current_page == ui->gamepage) {
        updateCellSize();
        QMainWindow::resizeEvent(event);
    }
}

void MainWindow::setTeamsListModel() {
    ui->teamsList->setModel(teams_list_model_);
}

void MainWindow::initializeTeamsListModel(const QStringList& files) {
    QStringList teams;
    for (int i = 0; i < files.size(); i++) {
        teams.append(QFileInfo(files[i]).baseName());
    }
    teams_list_model_ = new TableModel(this, teams);
    setTeamsListModel();
    configureTableView(ui->teamsList);
}

void MainWindow::configureTableView(QTableView* view) {
    view->setSelectionMode(QAbstractItemView::NoSelection);
    view->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setResizeMode(QHeaderView::Stretch);
}

void MainWindow::updateCellSize() {
    // Use the first row/column because heights/widths
    // of all rows/columns are equal
    int cell_width = ui->teamsList->columnWidth(0);
    int cell_height = ui->teamsList->rowHeight(0);
    teams_list_model_->updateCellSize(cell_width, cell_height);
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
    updateCellSize();
}
