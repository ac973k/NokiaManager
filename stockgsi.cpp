#include "stockgsi.h"
#include "ui_stockgsi.h"

StockGSI::StockGSI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockGSI)
{
    ui->setupUi(this);
}

StockGSI::~StockGSI()
{
    delete ui;
}
