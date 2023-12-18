#ifndef COMPLAINTS_H
#define COMPLAINTS_H

#include <QMainWindow>

namespace Ui {
class Complaints;
}

class Complaints : public QMainWindow
{
    Q_OBJECT

public:
    explicit Complaints(QWidget *parent = nullptr);
    ~Complaints();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Complaints *ui;
};

#endif // COMPLAINTS_H
