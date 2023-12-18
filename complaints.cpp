#include "complaints.h"
#include "ui_complaints.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QFileInfo>
#include <QtSql>

QSqlDatabase db8;

Complaints::Complaints(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Complaints)
{
    ui->setupUi(this);
    db8 = QSqlDatabase::addDatabase("QSQLITE");
    db8.setDatabaseName("D:/New folder/mydb1/mydatabase.sqlite");

    if (!db8.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";

        // Create the table if it doesn't exist
        QSqlQuery query1(db8);
        if (!query1.exec("CREATE TABLE IF NOT EXISTS info ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "Name TEXT, "
                         "complaints TEXT"")")) {
            qDebug() << "Error: Failed to create table. " << query1.lastError().text();
        }
    }
}

Complaints::~Complaints()
{
    delete ui;
}

void Complaints::on_pushButton_2_clicked()
{
    this->hide();
}

void Complaints::on_pushButton_clicked() {
    QString Complaint1 = ui->lineEdit->text();
    QString Name1 = ui->lineEdit_2->text();

    if (Complaint1.isEmpty() || Name1.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in the complaint field");
    } else {
        // Insert complaint into the database
        QSqlQuery insertQuery(db8);  // Use the member database object here
        insertQuery.prepare("INSERT INTO complaints_info (complaints1, Name1) VALUES (:complaints, :Name)");

        insertQuery.bindValue(":complaints", Complaint1);
        insertQuery.bindValue(":Name", Name1);

        if (!insertQuery.exec()) {
            qDebug() << "Error: Failed to insert complaint into the database!!!. " << insertQuery.lastError().text();
            qDebug() << "Query error: " << insertQuery.lastError().text();
            qDebug() << "Query executed: " << insertQuery.lastQuery();
        } else {
            QMessageBox::information(this, "Information", "Complaint saved successfully");
            // Optionally, you can hide the current window and show another one, or perform any other actions.
        }
    }
}
