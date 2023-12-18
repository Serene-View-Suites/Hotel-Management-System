#include "complaintsadmin.h"
#include "ui_complaintsadmin.h"

complaintsAdmin::complaintsAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::complaintsAdmin)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/New folder/mydb2/mydatabase.sqlite");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
    } else {
        qDebug() << "Database connected!";
        // Create the complaints_info table if it doesn't exist
        QSqlQuery query1(db);
        if (!query1.exec("CREATE TABLE IF NOT EXISTS complaints_info ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "Name TEXT, "
                         "complaints TEXT)")) {
            qDebug() << "Error: Failed to create table. " << query1.lastError().text();
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
    ui->tableWidget->setColumnCount(3); // Assuming you have 3 columns in complaints_info table
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name" << "Complaints");
    QFont headerFont = ui->tableWidget->horizontalHeader()->font();
    headerFont.setPointSize(10);  // Set the font size to 10
    ui->tableWidget->horizontalHeader()->setFont(headerFont);
    ui->tableWidget->setColumnWidth(0, 50);  // ID column width
    ui->tableWidget->setColumnWidth(1, 100); // Name column width
    ui->tableWidget->setColumnWidth(2, 350);
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
        }
    } else {
        qDebug() << "Error executing query:" << selectQuery.lastError().text();
    }
}


void complaintsAdmin::on_pushButton_clicked()
{
    this->hide();
}

