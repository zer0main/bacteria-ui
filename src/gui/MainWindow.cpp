/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include <string>
#include <fstream>

#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "GuiConstants.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    curr_team_(0) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createCoreObjects() {
    Strings script_strs;
    for (int i = 0; i < teams_.size(); i++) {
        std::ifstream script(teams_[i].toStdString().c_str());
        std::string script_str;
        int instructions = 0;
        for (std::string buffer; getline(script, buffer); ) {
            script_str += buffer + '\n';
            instructions++;
        }
        ChangerPtr changer = ChangerPtr(
            new Implementation::Changer(model_, i, 0, instructions)
        );
        changers_.push_back(changer);
        script_strs.push_back(script_str);
        script.close();
    }
    interpreter_ = InterpreterPtr(
        new Implementation::Interpreter()
    );
    interpreter_->makeBytecode(script_strs);
}

void MainWindow::createBoardItemDelegate() {
    board_item_delegate_ = new BoardItemDelegate(ui->boardView);
}

void MainWindow::setBoardViewDelegate() {
    ui->boardView->setItemDelegate(board_item_delegate_);
}

void MainWindow::setTableViewModels() {
    ui->teamsList->setModel(teams_list_model_);
    ui->boardView->setModel(board_model_);
}

void MainWindow::initializeModels(int width, int height) {
    int teams = teams_.size();
    model_ = ModelPtr(Abstract::makeModel<Implementation::Model>(
        width,
        height,
        bacteria_,
        teams
    ));
    board_model_ = new TableModel(this, model_, &teams_);
    teams_list_model_ = new TeamsListModel(this, model_, &teams_);
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

void MainWindow::makeMove() {
    interpreter_->makeMove(*(changers_[curr_team_].data()), 0);
    curr_team_ = (curr_team_ + 1) % teams_.size();
    QTimer::singleShot(MOVE_WAIT, this, SLOT(update()));
}

void MainWindow::update() {
    board_model_->updateData();
    teams_list_model_->updateData();
    QTimer::singleShot(MOVE_WAIT, this, SLOT(makeMove()));
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
        for (int i = 0; i < teams; i++) {
            teams_.append(file_names[i]);
        }
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
    createCoreObjects();
    configureTeamsList();
    configureBoardView();
    createBoardItemDelegate();
    setBoardViewDelegate();
    ui->stackedWidget->setCurrentWidget(ui->gamepage);
    makeMove();
}
