#include "checkout2.h"
#include "ui_checkout2.h"
#include <QRegularExpression>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QFileInfo>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
Checkout2::Checkout2(QWidget *parent) : QMainWindow(parent), ui(new Ui::Checkout2) {
    ui->setupUi(this);
}

Checkout2::~Checkout2() {
    delete ui;
}

void Checkout2::on_pushButton_clicked() {
    QString days = ui->lineEdit_2->text().trimmed();  // Trim to remove leading/trailing whitespaces
    QString Name = ui->lineEdit->text().trimmed();  // Use the correct line edit for Name
    QString Age = ui->lineEdit_3->text().trimmed();
    QRegularExpression numberRegex("^[0-9-]+$");

    if (days.isEmpty() || Name.isEmpty() || Age.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all the fields");
    } else if (!days.contains(numberRegex)) {
        QMessageBox::warning(this, "Warning", "Days must be in numbers");
    } else {
        int numberOfDays = days.toInt();
        int roomRentPerDay = 75;
        int totalRent = numberOfDays * roomRentPerDay;

        // Establish a connection to the database
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("D:/New folder/checkout2/mydatabase.sqlite");

        if (!db.open()) {
            qDebug() << "Error: Failed to connect to the database.";
        } else {
            qDebug() << "Database connected!";
            QSqlQuery *query = new QSqlQuery(db);

            if (!query->exec("CREATE TABLE IF NOT EXISTS checkout_info ("
                             "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "Name TEXT,"
                             "Age TEXT,"
                             "days INTEGER, "
                             "total_rent INTEGER"
                             ")")) {
                qDebug() << "Error: Failed to create table. " << query->lastError().text();
            }

            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO checkout_info (Name, Age, days, total_rent) VALUES (:Name, :Age, :days, :total_rent)");

            // Bind values only if the query is prepared successfully
            insertQuery.bindValue(":Name", Name);
            insertQuery.bindValue(":Age", Age);
            insertQuery.bindValue(":days", QVariant(numberOfDays));
            insertQuery.bindValue(":total_rent", QVariant(totalRent));

            if (!insertQuery.exec()) {
                qDebug() << "Error: Failed to insert checkout data into the database.";
                qDebug() << "Query error: " << insertQuery.lastError().text();
                qDebug() << "Query executed: " << insertQuery.lastQuery();
            } else {
                QMessageBox::information(this, "Information", "Information saved successfully\n"
                                                              "Number of Days: " + QString::number(numberOfDays) +
                                                                  "\nTotal Rent: $" + QString::number(totalRent));
            }
        }
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "Do you want to download your receipt?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes){
            generateAndSavePDF(Name, Age, numberOfDays, totalRent);
        }
        this->hide();

    }
}
void Checkout2::generateAndSavePDF(const QString &name, const QString &age, int days, int totalRent) {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));

    if (!fileName.isEmpty()) {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QPainter painter;
        painter.begin(&printer);

        // Set up painter properties (font, size, etc.) as needed
        // ...

        // Draw content to the PDF
        painter.setFont(QFont("Times New Roman", 16, QFont::Bold));

        // Title
        painter.drawText(100, 80, "Hotel1 Booking Confirmation");
        painter.setFont(QFont("Times New Roman", 12, QFont::Normal));

        // Information
        painter.drawText(100, 120, "Bookings for 4 Person Room");
        painter.drawText(100, 140, "Name: " + name);
        painter.drawText(100, 160, "Age: " + age);
        painter.drawText(100, 180, "Number of Days: " + QString::number(days));
        painter.drawText(100, 200, "Total Rent: $" + QString::number(totalRent));


        painter.end();
    }
}


