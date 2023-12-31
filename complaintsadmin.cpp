#include "complaintsadmin.h"
#include "ui_complaintsadmin.h"
#include <QCheckBox>
complaintsAdmin::complaintsAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::complaintsAdmin)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("complaints.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
        // Create the complaints_info table if it doesn't exist
        QSqlQuery query1(db);
        if (!query1.exec("CREATE TABLE IF NOT EXISTS complaints_info ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "Name TEXT, "
                         "complaints TEXT,"
                         "checkbox_state INTEGER)")) {
            qDebug() << "Error: Failed to create table. " << query1.lastError().text();
        }
    }
    // Assuming you have a separate database for checkbox states
    QSqlDatabase checkboxDb = QSqlDatabase::addDatabase("QSQLITE", "checkboxConnection");
    checkboxDb.setDatabaseName("D:/New folder/mydb2/checkboxdatabase.sqlite");

    if (!checkboxDb.open()) {
        qDebug() << "Error: Failed to connect to checkbox database.";
    } else {
        qDebug() << "Checkbox database connected!";
        // Create the checkbox_states table if it doesn't exist
        QSqlQuery checkboxQuery(checkboxDb);
        if (!checkboxQuery.exec("CREATE TABLE IF NOT EXISTS checkbox_states ("
                                "id INTEGER PRIMARY KEY, "
                                "checkbox_state INTEGER)")) {
            qDebug() << "Error: Failed to create checkbox_states table. " << checkboxQuery.lastError().text();
        }
    }



    loadAndDisplayData(); // Load and display complaints data
}

complaintsAdmin::~complaintsAdmin()
{
    delete ui;
}
void complaintsAdmin::loadAndDisplayData() {
    // Clear existing data from the table widget
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0); // Reset row count to 0



        // Set up headers for the table
        ui->tableWidget->setColumnCount(4); // Assuming you have 3 columns in complaints_info table
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Complaints" << "Enable");
        QFont headerFont = ui->tableWidget->horizontalHeader()->font();
        headerFont.setPointSize(10);  // Set the font size to 10
        ui->tableWidget->horizontalHeader()->setFont(headerFont);
        ui->tableWidget->setColumnWidth(0, 50);  // ID column width
        ui->tableWidget->setColumnWidth(1, 100); // Name column width
        ui->tableWidget->setColumnWidth(2, 300); // Complaints column width
        ui->tableWidget->setColumnWidth(3, 80);

        // Retrieve data from the complaints_info table
        QSqlQuery selectQuery("SELECT * FROM complaints_info");

        // Check if the query was successful
        if (selectQuery.exec()) {
            // Iterate through the results and display them in the table
            while (selectQuery.next()) {
                int id = selectQuery.value(0).toInt();
                QString name = selectQuery.value(1).toString();
                QString complaints = selectQuery.value(2).toString();

                // Insert a new row in the table
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);

                // Populate the table with data
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(name));
                ui->tableWidget->setItem(row, 2, new QTableWidgetItem(complaints));

                // Create a checkbox item for the checkbox column
                QCheckBox* checkBox = new QCheckBox();
                ui->tableWidget->setCellWidget(row, 3, checkBox);

                // Connect the checkbox state change signal to a slot
                connect(checkBox, &QCheckBox::stateChanged, this, [=](int state) {
                    // Save the checkbox state to the checkbox database when it changes
                    QSqlQuery updateQuery(checkboxDb);
                    updateQuery.prepare("INSERT OR REPLACE INTO checkbox_states (id, checkbox_state) VALUES (:id, :state)");
                    updateQuery.bindValue(":id", id);
                    updateQuery.bindValue(":state", state == Qt::Checked ? 1 : 0);
                    if (!updateQuery.exec()) {
                        qDebug() << "Error updating checkbox state:" << updateQuery.lastError().text();
                        qDebug() << "Updating checkbox state. ID:" << id << " State:" << state;
                    }
                });

                // Fetch and set the initial state from the checkbox database
                QSqlQuery checkboxStateQuery(checkboxDb);
                checkboxStateQuery.prepare("SELECT checkbox_state FROM checkbox_states WHERE id = :id");
                checkboxStateQuery.bindValue(":id", id);
                if (checkboxStateQuery.exec() && checkboxStateQuery.next()) {
                    int checkboxState = checkboxStateQuery.value(0).toInt();
                    checkBox->setChecked(checkboxState == 1);
                }
            }
        }
 else {
    qDebug() << "Error executing query:" << selectQuery.lastError().text();
}}

