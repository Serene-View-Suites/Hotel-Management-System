#include "adminpage.h"
#include "ui_adminpage.h"

AdminPage::AdminPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
    ptrAvail = new availableRooms();
    ptrTransactions = new Transactions();
    ptrComp = new complaintsAdmin();
    ptrTransactions2 = new transactions2();
}

AdminPage::~AdminPage()
{
    delete ui;
}

void AdminPage::on_pushButton_3_clicked()
{
    this->hide();

}


void AdminPage::on_pushButton_clicked()
{

    ptrAvail->show();
}


void AdminPage::on_pushButton_2_clicked()
{

    ptrTransactions->show();
}


void AdminPage::on_pushButton_4_clicked()
{
    ptrComp->show();
}


void AdminPage::on_pushButton_5_clicked()
{
    ptrTransactions2->show();
}

