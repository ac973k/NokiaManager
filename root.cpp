#include "root.h"
#include "ui_root.h"

Root::Root(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Root)
{
    ui->setupUi(this);
}

Root::~Root()
{
    delete ui;
}
