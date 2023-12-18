#include "attributes.h"
#include "ui_attributes.h"

Attributes::Attributes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Attributes)
{
    ui->setupUi(this);
    ptrcomp = new comp2();
    ptrComp2 = new Complaints();
    ptrBooking = new RoomBooking();
    ptrCheck = new CheckOut();
    ptrTransaction = new Transactions();
}

Attributes::~Attributes()
{
    delete ui;
}

void Attributes::on_pushButton_clicked()
{
    ptrBooking->show();

}


void Attributes::on_pushButton_2_clicked()
{
    ptrcomp->show();

}


void Attributes::on_pushButton_3_clicked()
{
    this->hide();
}

