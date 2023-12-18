#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ptradminpage = new AdminPage();
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
//    ui->lineEdit->setEchoMode(QLineEdit::UserName);
}

Admin::~Admin()
{
    delete ui;
    delete ptradminpage;
}

void Admin::on_pushButton_clicked()
{
    QString UserName = ui->lineEdit->text();
    QString PassWord = ui->lineEdit_2->text();
    if(UserName == "Hotel1" && PassWord == "Nust2003"){
        QMessageBox::information(this, "Hotel Management System", "You have successfully logged in.");
        this -> hide();
        ptradminpage->show();
    }
    else{
        QMessageBox::warning(this, "Hotel Management System", "Enter Valid Email or Password");
    }

}


void Admin::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Hotel Management System", "Are You Sure?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes){
        this->hide();

    }

}

