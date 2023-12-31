#include "sign.h"
#include "ui_sign.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

QSqlDatabase db2;
sign::sign(QWidget *parent) : QMainWindow(parent), ui(new Ui::sign) {
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ptrattributes = new Attributes;
    // Database connection
    db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("information.sqlite");
    if (!db2.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
    }
}

sign::~sign() {
    db2.close();
    delete ui;
}

void sign::on_pushButton_clicked() {
    QString Name = ui->lineEdit->text();  // Assuming the QLineEdit for name is named lineEdit_Name
    QString Password = ui->lineEdit_2->text();  // Assuming the QLineEdit for password is named lineEdit_Password

    if (Name.isEmpty() || Password.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both name and password");
    } else {
        // Check if the provided name and password exist in the database
        QSqlQuery query;
        query.prepare("SELECT * FROM person_info WHERE name = :name AND password = :password");
        query.bindValue(":name", Name);
        query.bindValue(":password", Password);

        if (query.exec() && query.next()) {
            // Match found, proceed with the next steps
            QMessageBox::information(this, "Information", "Sign-in successful");
            this->hide();
            ptrattributes->show();
            // Add code here to navigate to the next window or perform other actions
        } else {
            // No match found
            QMessageBox::warning(this, "Warning", "Invalid name or password");
        }
    }
}
