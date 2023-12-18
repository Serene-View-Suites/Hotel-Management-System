#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDialog>
#include "information.h"

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT
public:
    explicit Customer(QWidget *parent = nullptr);
    ~Customer();

private slots:



    void on_pushButton_clicked();

private:
    Ui::Customer *ui;
    Information *ptrInformation;

};

#endif // CUSTOMER_H
