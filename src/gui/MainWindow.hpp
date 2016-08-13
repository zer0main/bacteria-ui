/*
 * bacteria-ui, GUI for cellular automaton
 * Copyright (C) 2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui>

#include "Creator.hpp"
#include "Interpreter.hpp"
#include "CoreGlobals.hpp"

#include "GuiConstants.hpp"
#include "GuiGlobals.hpp"
#include "BoardItemDelegate.hpp"
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

    BoardItemDelegate* board_item_delegate_;

    InterpreterPtr interpreter_;

    ChangerPtrs changers_;

    ModelPtr model_;

    QStringList teams_;

    int bacteria_;

    int curr_team_;

    void createCoreObjects();

    void createBoardItemDelegate();

    void setBoardViewDelegate();

    void setTableViewModels();

    void initializeModels(int width, int height);

    void configureTeamsList();

    void configureBoardView();

    void configureBacteriaSpinBox();

    void configureSizeSpinBoxes();

    Ints updateBacteriaNumbers();

private slots:
    void makeMove();

    void update();

    void on_fileButton_clicked();

    void on_quitButton_clicked();

    void on_nextButton_clicked();

    void on_playButton_clicked();
};

#endif // MAINWINDOW_HPP_
