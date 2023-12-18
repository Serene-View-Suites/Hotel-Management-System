#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>

namespace Ui {
class Transactions;
}

class Transactions : public QMainWindow
{
    Q_OBJECT

public:
    explicit Transactions(QWidget *parent = nullptr);
    ~Transactions();

private:
    Ui::Transactions *ui;
    QSqlDatabase db;

    void loadAndDisplayData();
};

#endif // TRANSACTIONS_H
