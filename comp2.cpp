#include "comp2.h"
#include "ui_comp2.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QtSql>
QSqlDatabase db9;
QSqlDatabase *query1;
comp2::comp2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::comp2)
{
    ui->setupUi(this);

}

comp2::~comp2()
{
    delete ui;
}




void comp2::on_pushButton_clicked()
{
    QString Name1 = ui->lineEdit_2->text().trimmed();
    QString Complaint1 = ui->lineEdit->text().trimmed();

    db9 = QSqlDatabase::addDatabase("QSQLITE");
    db9.setDatabaseName("complaints.sqlite");

    if (!db9.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";

        // Create the table if it doesn't exist
        QSqlQuery query1(db9);
        if (!query1.exec("CREATE TABLE IF NOT EXISTS complaints_info ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "Name TEXT, "
                         "complaints TEXT)")) {
            qDebug() << "Error: Failed to create table. " << query1.lastError().text();
        }
    }

    if (Complaint1.isEmpty() || Name1.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in the complaint field");
    } else {
        // Insert complaint into the database
//        QSqlQuery Query;
//        qDebug() << "Complaint1:" << Complaint1;
//        qDebug() << "Name1:" << Name1;
//        Query.prepare("INSERT INTO complaints_info (Name,complaints) VALUES (:Name,:complaints)");
//        qDebug() << Name1 << Complaint1;

//        Query.bindValue(":complaints", Complaint1);
//        Query.bindValue(":Name", Name1);

        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO complaints_info (Name, complaints) VALUES (:Name, :complaints)");
        insertQuery.bindValue(":Name", QVariant(Name1));
        insertQuery.bindValue(":complaints", QVariant(Complaint1));

        qDebug() << "Name value:" << Name1;
        qDebug() << "Complaint value:" << Complaint1;

        if (!insertQuery.exec()) {
//            QMessageBox::critical(this, "Error", "Failed to insert complaint into the database: " + insertQuery.lastError().text());
            qDebug() << "Error: Failed to insert complaint into the database: " << insertQuery.lastError().text();
            qDebug() << "Query error: " << insertQuery.lastError().text();
            qDebug() << "Query executed: " << insertQuery.lastQuery();
        } else {
            QMessageBox::information(this, "Information", "Complaint saved successfully");
            // Optionally, you can hide the current window and show another one, or perform any other actions.
        }
    }
}



void comp2::on_pushButton_2_clicked()
{
    this->hide();
}

