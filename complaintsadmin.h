#ifndef COMPLAINTSADMIN_H
#define COMPLAINTSADMIN_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <QMainWindow>

namespace Ui {
class complaintsAdmin;
}

class complaintsAdmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit complaintsAdmin(QWidget *parent = nullptr);
    ~complaintsAdmin();

private slots:
    void on_pushButton_clicked();

private:
    QSettings settings;
    QSqlDatabase checkboxDb;

    Ui::complaintsAdmin *ui;
    QSqlDatabase db;

    void loadAndDisplayData();
};

#endif // COMPLAINTSADMIN_H
