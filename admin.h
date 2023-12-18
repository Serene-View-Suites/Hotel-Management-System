#ifndef ADMIN_H
#define ADMIN_H

#include "adminpage.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Admin *ui;
    AdminPage *ptradminpage;
};

#endif // ADMIN_H
