#ifndef AVAILABLEROOMS_H
#define AVAILABLEROOMS_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>
#include <QMainWindow>
namespace Ui {
class availableRooms;
}

class availableRooms : public QMainWindow
{
    Q_OBJECT

public:
    explicit availableRooms(QWidget *parent = nullptr);
    ~availableRooms();

private slots:
    void on_pushButton_clicked();

private:
    Ui::availableRooms *ui;
    QSqlDatabase db;
    void loadAndDisplayData();
};

#endif // AVAILABLEROOMS_H
