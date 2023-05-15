#include "nokiamanager.h"
#include "ui_nokiamanager.h"

#include "loader.h"

NokiaManager::NokiaManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NokiaManager)
{
    ui->setupUi(this);

    load = new Loader;
    root = new Root;
    stock = new Stock;
}

NokiaManager::~NokiaManager()
{
    delete ui;

    delete stock;
    delete root;
    delete load;
}


void NokiaManager::on_btnLoader_clicked()
{
    load->show();
}


void NokiaManager::on_btnRoot_clicked()
{
    root->show();
}


void NokiaManager::on_btnStock_clicked()
{
    stock->show();
}

