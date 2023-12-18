#ifndef SIGN_H
#define SIGN_H
#include "attributes.h"
#include <QMainWindow>

namespace Ui {
class sign;
}

class sign : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sign *ui;
    Attributes *ptrattributes;
};

#endif // SIGN_H
