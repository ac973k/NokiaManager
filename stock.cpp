#include "stock.h"
#include "ui_stock.h"

Stock::Stock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stock)
{
    ui->setupUi(this);
}

Stock::~Stock()
{
    delete ui;
}
