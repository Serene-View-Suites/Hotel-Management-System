#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QtSql>
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Remove the previous database connection if it exists



    // Set up the new database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
    db.setDatabaseName("D:/New folder/information/mydatabase.sqlite");

    // Check if the database is open
    if (!db.open()) {
        qDebug() << "Error: Unable to open the database";
        return 1;
    }

    // Example query to retrieve data from person_info and checkout_info joined on ID
    // Example query to retrieve data from person_info and checkout_info joined on ID
//    QSqlQuery query;
//    if (query.exec("SELECT person_info.id, person_info.name, person_info.cnic, person_info.phone, person_info.email, "
//                   "person_info.password, person_info.confirm_password, "
//                   "checkout_info.days, checkout_info.total_rent "
//                   "FROM person_info "
//                   "LEFT JOIN checkout_info ON person_info.id = checkout_info.id")) {
//        while (query.next()) {
//            int id = query.value(0).toInt();
//            QString name = query.value(1).toString();
//            QString cnic = query.value(2).toString();
//            QString phone = query.value(3).toString();
//            QString email = query.value(4).toString();
//            QString password = query.value(5).toString();
//            QString confirm_password = query.value(6).toString();


//            int numberOfDays = query.value(7).isNull() ? 0 : query.value(7).toInt();
//            int totalRent = query.value(8).isNull() ? 0 : query.value(8).toInt();

//            qDebug() << "ID:" << id << "Name:" << name << "CNIC:" << cnic << "Phone:" << phone << "Email:" << email
//                     << "Password:" << password << "Confirm Password:" << confirm_password
//                     << "Days:" << numberOfDays << "Total Rent:" << totalRent;

            // Check if both days and rent are zero or NULL
//            if (numberOfDays == 0 && totalRent == 0) {
//                qDebug() << name << " has registered but has not booked a room.";
//            }
//        }

//        // Reset the query before executing the next query
//        query.finish();
//    } else {
//        qDebug() << "Error executing query1:" << query.lastError().text();
//    }


//    // Close the database
//    db.close();

    // Remove the database connection from the connection pool
    QSqlDatabase::removeDatabase("my_connection");

    // Show the QLabel
    w.show();
    return a.exec();
}
