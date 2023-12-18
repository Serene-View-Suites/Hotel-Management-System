#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptradmin = new Admin();
    ptruser = new user();
    ptrSign = new sign();
     ptrInformation = new Information();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptruser;
    delete ptradmin;
}


void MainWindow::on_pushButton_clicked()
{
    ptradmin->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    ptrSign->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrInformation->show();
}

