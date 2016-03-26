/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "GuiConstants.hpp"

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
    for (int i = 0; i < files.size(); i++) {
        teams_.append(QFileInfo(files[i]).baseName());
    }
    teams_list_model_ = new TeamsListModel(this, teams_);
}

void MainWindow::initializeModels(int width, int height) {
    int teams = teams_.size();
    model_ = QSharedPointer<Abstract::Model>
             (Abstract::makeModel<Implementation::Model>(width,
                                                         height,
                                                         bacteria_,
                                                         teams));
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

void MainWindow::configureBacteriaSpinBox() {
    ui->bacteriaNumber->setRange(1, MAX_BACTERIA);
    ui->bacteriaNumber->setValue(1);
}

void MainWindow::configureSizeSpinBoxes() {
    int teams = teams_.size();
    int min_size = static_cast<int>(qSqrt(teams * bacteria_ * 2) + 1);
    int min_width = std::max(MIN_WIDTH, min_size);
    int min_height = std::max(MIN_HEIGHT, min_size);
    ui->boardWidth->setRange(min_width, MAX_WIDTH);
    ui->boardHeight->setRange(min_height, MAX_HEIGHT);
    int default_width = std::min(min_width + INDENT, MAX_WIDTH);
    int default_height = std::min(min_height + INDENT, MAX_HEIGHT);
    ui->boardWidth->setValue(default_width);
    ui->boardHeight->setValue(default_height);
}

void MainWindow::on_fileButton_clicked() {
    QStringList file_names = QFileDialog::getOpenFileNames(
        this,
        tr("Open File"),
        "/home",
        ""
    );
    int teams = file_names.size();
    if ((teams >= 1) && (teams <= MAX_TEAMS)) {
        initializeTeamsListModel(file_names);
        configureBacteriaSpinBox();
        ui->stackedWidget->setCurrentWidget(ui->bacteriaInputpage);
    }
}

void MainWindow::on_quitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_nextButton_clicked() {
    bacteria_ = ui->bacteriaNumber->value();
    configureSizeSpinBoxes();
    ui->stackedWidget->setCurrentWidget(ui->inputpage);
}

void MainWindow::on_playButton_clicked() {
    int width = ui->boardWidth->value();
    int height = ui->boardHeight->value();
    initializeModels(width, height);
    setTableViewModels();
    configureTeamsList();
    configureBoardView();
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
}
