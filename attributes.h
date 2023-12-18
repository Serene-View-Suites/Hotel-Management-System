#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QMainWindow>
#include "roombooking.h"
#include "checkout.h"
#include "transactions.h"
#include "complaints.h"
#include"comp2.h"
namespace Ui {
class Attributes;
}

class Attributes : public QMainWindow
{
    Q_OBJECT

public:
    explicit Attributes(QWidget *parent = nullptr);
    ~Attributes();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    comp2 *ptrcomp;
    Ui::Attributes *ui;
    RoomBooking *ptrBooking;
    CheckOut *ptrCheck;
    Transactions *ptrTransaction;
    Complaints *ptrComp2;
};

#endif // ATTRIBUTES_H
