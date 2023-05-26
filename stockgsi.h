#ifndef STOCKGSI_H
#define STOCKGSI_H

#include <QWidget>

#include <QProcess>

namespace Ui {
class StockGSI;
}

class StockGSI : public QWidget
{
    Q_OBJECT

public:
    explicit StockGSI(QWidget *parent = nullptr);
    ~StockGSI();

private slots:
    void on_btnFlash_clicked();

private:
    Ui::StockGSI *ui;

    QProcess *procDisableAuth;
    QProcess *procFlash;
};

#endif // STOCKGSI_H
