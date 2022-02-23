#ifndef STOCK_H
#define STOCK_H

#include <QWidget>

namespace Ui {
class Stock;
}

class Stock : public QWidget
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();

private:
    Ui::Stock *ui;
};

#endif // STOCK_H
