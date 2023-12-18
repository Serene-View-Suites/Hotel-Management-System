#include "transactions.h"
#include "ui_transactions.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QFileInfo>

Transactions::Transactions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);

    // Set up the database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/New folder/checkout2/mydatabase.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
        // Create the person_info table if it doesn't exist
        QSqlQuery query(db);
//        if (!query.exec("CREATE TABLE IF NOT EXISTS person_info ("
//                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//                        "name TEXT, "
//                        "cnic TEXT, "
//                        "phone TEXT, "
//                        "email TEXT,"
//                        "password TEXT, "
//                        "confirm_password TEXT"
//                        ")")) {
//            qDebug() << "Error: Failed to create table. " << query.lastError().text();
//        }

        // Create the checkout_info table if it doesn't exist
        if (!query.exec("CREATE TABLE IF NOT EXISTS checkout_info ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "Name,"
                        "Age,"
                        "days INTEGER, "
                        "total_rent INTEGER"
                        ")")) {
            qDebug() << "Error: Failed to create table. " << query.lastError().text();
        }
    }
    // Call the function to load and display data
    loadAndDisplayData();
}

Transactions::~Transactions()
{
    db.close();
    delete ui;
}


void Transactions::loadAndDisplayData() {
    // Clear existing data from the table widget
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0); // Reset row count to 0

    // Set up headers for the table
    ui->tableWidget->setColumnCount(5); // Assuming you have 5 columns in checkout_info table
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Age" << "Days" << "Total Rent");
    QFont headerFont = ui->tableWidget->horizontalHeader()->font();
    headerFont.setPointSize(10);  // Set the font size to 10
    ui->tableWidget->horizontalHeader()->setFont(headerFont);

    // Retrieve data from the checkout_info table
    QSqlQuery selectQuery("SELECT * FROM checkout_info");

    // Check if the query was successful
    if (selectQuery.exec()) {
        // Iterate through the results and display them in the table
        while (selectQuery.next()) {
            int id = selectQuery.value(0).toInt();
            QString name = selectQuery.value(1).toString();
            QString age = selectQuery.value(2).toString();
            int numberOfDays = selectQuery.value(3).toInt();
            int totalRent = selectQuery.value(4).toInt();

            // Insert a new row in the table
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // Populate the table with data
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(name));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(age));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(numberOfDays)));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(totalRent)));
        }
    } else {
        qDebug() << "Error executing query:" << selectQuery.lastError().text();
    }
}



