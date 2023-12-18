#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user)
{
    ui->setupUi(this);
    ptrSign = new sign();
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    ptrSign->show();
}

