#ifndef ADMINPAGE_H
#define ADMINPAGE_H
#include "availablerooms.h"
#include "transactions.h"
#include"complaintsadmin.h"
#include "transactions2.h"
#include <QMainWindow>

namespace Ui {
class AdminPage;
}

class AdminPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AdminPage *ui;
    availableRooms *ptrAvail;
    Transactions *ptrTransactions;
    complaintsAdmin *ptrComp;
    transactions2 *ptrTransactions2;
};

#endif // ADMINPAGE_H
