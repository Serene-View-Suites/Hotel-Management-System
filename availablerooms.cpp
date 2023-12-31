#include "availablerooms.h"
#include "ui_availablerooms.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QFileInfo>

availableRooms::availableRooms(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::availableRooms)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("information.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
        // Create the person_info table if it doesn't exist
        QSqlQuery query(db);
        if (!query.exec("CREATE TABLE IF NOT EXISTS person_info ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "name TEXT, "
                        "cnic TEXT, "
                        "phone TEXT, "
                        "email TEXT,"
                        "password TEXT, "
                        "confirm_password TEXT"
                        ")")) {
            qDebug() << "Error: Failed to create table. " << query.lastError().text();
        }

        loadAndDisplayData();
    }
}

availableRooms::~availableRooms()
{
    delete ui;
}

void availableRooms::loadAndDisplayData()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0); // Reset row count to 0

    // Set up headers for the table
    ui->tableWidget->setColumnCount(5); // Assuming you have 6 columns in person_info table
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "CNIC" << "Phone" << "Email" );
    QFont headerFont = ui->tableWidget->horizontalHeader()->font();
    headerFont.setPointSize(10);  // Set the font size to 10
    ui->tableWidget->horizontalHeader()->setFont(headerFont);

    // Retrieve data from the person_info table
    QSqlQuery selectQuery("SELECT * FROM person_info");

    // Check if the query was successful
    if (selectQuery.exec()) {
        // Iterate through the results and display them in the table
        while (selectQuery.next()) {
            int id = selectQuery.value(0).toInt();
            QString name = selectQuery.value(1).toString();
            QString cnic = selectQuery.value(2).toString();
            QString phone = selectQuery.value(3).toString();  // Changed to QString
            QString email = selectQuery.value(4).toString();  // Changed to QString
//            QString password = selectQuery.value(5).toString();  // Added

            // Insert a new row in the table
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // Populate the table with data
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(name));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(cnic));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(phone));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(email));
//            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(password));  // Added
        }
    } else {
        qDebug() << "Error executing query:" << selectQuery.lastError().text();
    }
}

void availableRooms::on_pushButton_clicked()
{
    this->hide();
}

