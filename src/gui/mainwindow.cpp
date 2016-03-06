#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "/home",
        tr("All files (*.*)")
    );
}
