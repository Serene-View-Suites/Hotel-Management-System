#ifndef CHECKOUT2_H
#define CHECKOUT2_H

#include <QMainWindow>

namespace Ui {
class Checkout2;
}

class Checkout2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Checkout2(QWidget *parent = nullptr);
    ~Checkout2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Checkout2 *ui;
    void generateAndSavePDF(const QString &name, const QString &age, int days, int totalRent)
        ;
};

#endif // CHECKOUT2_H
