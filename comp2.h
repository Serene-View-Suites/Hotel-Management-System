#ifndef COMP2_H
#define COMP2_H

#include <QMainWindow>

namespace Ui {
class comp2;
}

class comp2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit comp2(QWidget *parent = nullptr);
    ~comp2();

private slots:
    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::comp2 *ui;
};

#endif // COMP2_H
