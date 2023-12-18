#ifndef INFORMATION_H
#define INFORMATION_H
#include "attributes.h"
#include <QMainWindow>

namespace Ui {
class Information;
}

class Information : public QMainWindow
{
    Q_OBJECT
public:
    bool isRegistered;

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Information *ui;
    Attributes *ptrAttributes;

};

#endif // INFORMATION_H
