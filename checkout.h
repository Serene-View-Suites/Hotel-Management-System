#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QMainWindow>

namespace Ui {
class CheckOut;
}

class CheckOut : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckOut(QWidget *parent = nullptr);
    ~CheckOut();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CheckOut *ui;
    void generateAndSavePDF(const QString &name, const QString &age, int days, int totalRent)
        ;};

#endif // CHECKOUT_H
