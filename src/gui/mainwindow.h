#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

#endif // MAINWINDOW_H
