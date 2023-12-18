#ifndef TRANSACTIONS2_H
#define TRANSACTIONS2_H
#include <QtSql>
#include <QSqlDatabase>
#include <QMainWindow>

namespace Ui {
class transactions2;
}

class transactions2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit transactions2(QWidget *parent = nullptr);
    ~transactions2();

private:
    Ui::transactions2 *ui;
    QSqlDatabase db;

    void loadAndDisplayData();
};

#endif // TRANSACTIONS2_H
