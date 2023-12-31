#include "roombooking.h"
#include "ui_roombooking.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QtSql>
#include <QFileInfo>

RoomBooking::RoomBooking(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RoomBooking)

{
    ui->setupUi(this);
    ptrCheck = new CheckOut();
    ptrCheck2 = new Checkout2();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }


    qDebug() << "Loading button states...";
    loadButtonStates();

}

RoomBooking::~RoomBooking()
{
    delete ui;
};

void RoomBooking::loadButtonStates() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS button_states (button_name TEXT PRIMARY KEY, pressed INTEGER)");

    query.exec("SELECT button_name, pressed FROM button_states");
    while (query.next()) {
        QString buttonName = query.value(0).toString();
        bool pressed = query.value(1).toBool(); // Corrected: use toBool() instead of tobool()

        QPushButton* button = findChild<QPushButton*>(buttonName);

        if (button) {
            if (pressed) {
                button->setStyleSheet("background-color: red");
            } else {
                button->setStyleSheet("background-color: white");
            }
        }
    }
}


void RoomBooking::on_pushButton_10_clicked() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.10??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::saveButtonState(const QString& buttonName, bool pressed) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO button_states (button_name, pressed) VALUES (?, ?)");
    query.bindValue(0, buttonName);
    query.bindValue(1, pressed ? 1 : 0);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        qDebug() << "Query text: " << query.lastQuery();
        qDebug() << "Bound values: " << query.boundValues();
    } else {
        qDebug() << "Query executed successfully";
    }
}






void RoomBooking::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.01??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}


void RoomBooking::on_pushButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.02??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.03??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}


void RoomBooking::on_pushButton_4_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.04??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}



void RoomBooking::on_pushButton_5_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.05??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_6_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.06??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_7_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.07??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_8_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.08??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}


void RoomBooking::on_pushButton_9_clicked()
{        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.09??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_11_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.11??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_12_clicked()
{          QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.12??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_13_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.13??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_14_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.14??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_15_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.15??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_16_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.16??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}


void RoomBooking::on_pushButton_27_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.01??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_31_clicked(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.02??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }

}
void RoomBooking::on_pushButton_21_clicked()
{    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.03??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_17_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.04??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_22_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.05??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_29_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.06??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_20_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.07??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_23_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.08??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_30_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.09??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_24_clicked()
{       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.10??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_26_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.11??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_32_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.12??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_18_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.13??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_19_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.14??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}


void RoomBooking::on_pushButton_25_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.15??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }
}

void RoomBooking::on_pushButton_28_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("roombooking.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database";
    } else {
        qDebug() << "Database opened successfully";
    }

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    //    bool isButtonPressed = button->property("pressed").toBool();

    // Check the color of the button
    QString buttonColor = button->styleSheet();
    bool isButtonRed = buttonColor.contains("red", Qt::CaseInsensitive);

    if (isButtonRed) {
        QMessageBox::warning(this, "Already Booked", "This room is already booked!");
    } else {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Hotel Management System", "You want to book Room No.16??", QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            button->setStyleSheet("background-color: red");
            button->setProperty("pressed", true);

            ptrCheck2->show();

            // Save button state to the database
            saveButtonState(button->objectName(), true);
        }
    }}
