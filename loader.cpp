#include "loader.h"
#include "ui_loader.h"

Loader::Loader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loader)
{
    ui->setupUi(this);
}

Loader::~Loader()
{
    delete ui;
}
