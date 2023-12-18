#ifndef USER_H
#define USER_H

#include "information.h"
#include <QMainWindow>
#include "sign.h"
namespace Ui {
class user;
}

class user : public QMainWindow
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();

private slots:
    void on_pushButton_clicked();

private:
    Ui::user *ui;
    Information *ptrInformation;
    sign *ptrSign;
};

#endif // USER_H
