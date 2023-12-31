#include "information.h"
#include "ui_information.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QFileInfo>

// Add QSqlDatabase and QSqlQuery as private member variables in the Information class

QSqlDatabase db;
QSqlQuery *query;  // Declare QSqlQuery as a member variable

Information::Information(QWidget *parent) : QMainWindow(parent), ui(new Ui::Information) {
    ui->setupUi(this);

    // Database connection moved to class member
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("information.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
        // Create the table if it doesn't exist
        // Modify the table creation query in your MainWindow constructor
        // Modify the table creation query in your MainWindow constructor
        query = new QSqlQuery(db);
        if (!query->exec("CREATE TABLE IF NOT EXISTS person_info ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name TEXT, "
                         "cnic TEXT, "
                         "phone TEXT, "
                         "email TEXT, "
                         "password TEXT, "
                         "confirm_password TEXT"
                         ")")) {
            qDebug() << "Error: Failed to create table. " << query->lastError().text();
        }


    }
}

// Destructor: clean up the query object
Information::~Information() {
    db.close();
    delete query;  // Release the allocated query object
    delete ui;
}

void Information::on_pushButton_clicked() {
    QString Name = ui->lineEdit->text();
    QString CNIC = ui->lineEdit_2->text();
    QString Phone = ui->lineEdit_3->text();
    QString Email = ui->lineEdit_4->text();
    QString Password = ui->lineEdit_5->text();  // Assuming the QLineEdit for password is named lineEdit_5
    QString ConfirmPassword = ui->lineEdit_6->text();
    QRegularExpression numberRegex("^[0-9-]+$");
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

    if (Name.isEmpty() || CNIC.isEmpty() || Phone.isEmpty() || Email.isEmpty()||Password.isEmpty()||ConfirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all the fields");
    }
    else if(Password.length() < 6 || Password != ConfirmPassword){
    QMessageBox::warning(this, "Warning", "Invalid password or passwords do not match");}
    else if (!Phone.contains(numberRegex) || !CNIC.contains(numberRegex) || !Email.contains(emailRegex)) {
        QMessageBox::warning(this, "Warning", "Invalid input format");
    } else {
        // Insert data into the database
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO person_info (name, cnic, phone, email,password,confirm_password) VALUES (:name, :cnic, :phone, :email,:password,:confirm_password)");
        insertQuery.bindValue(":name", Name);
        insertQuery.bindValue(":cnic", CNIC);
        insertQuery.bindValue(":phone", Phone);
        insertQuery.bindValue(":email", Email);
        insertQuery.bindValue(":password", Password);
        insertQuery.bindValue(":confirm_password", ConfirmPassword);
//        qDebug() << Name << CNIC << Phone << Email;

        if (!insertQuery.exec()) {
            qDebug() << "Error: Failed to insert data into the database. " << insertQuery.lastError().text();
        } else {
            QMessageBox::information(this, "Information", "User Created Successfully");
            this->hide();
//            ptrAttributes = new Attributes();  // Create a new instance
//            ptrAttributes->show();
        }
    }
}

void Information::on_pushButton_2_clicked()
{
    this->hide();
}

