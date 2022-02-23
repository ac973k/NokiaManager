#ifndef STOCKGSI_H
#define STOCKGSI_H

#include <QWidget>

namespace Ui {
class StockGSI;
}

class StockGSI : public QWidget
{
    Q_OBJECT

public:
    explicit StockGSI(QWidget *parent = nullptr);
    ~StockGSI();

private:
    Ui::StockGSI *ui;
};

#endif // STOCKGSI_H
