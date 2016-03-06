#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_fileButton_clicked();
};

#endif // MAINWINDOW_HPP_