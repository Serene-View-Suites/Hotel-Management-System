#include "customer.h"
#include "ui_customer.h"

Customer::Customer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
    ptrInformation = new Information();

}

Customer::~Customer()
{
    delete ui;
    delete ptrInformation;
}






void Customer::on_pushButton_clicked()
{
    ptrInformation->show();
}

