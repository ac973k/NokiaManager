#include "nokiamanager.h"
#include "ui_nokiamanager.h"

#include "loader.h"

NokiaManager::NokiaManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NokiaManager)
{
    ui->setupUi(this);

    load = new Loader;
}

NokiaManager::~NokiaManager()
{
    delete ui;

    delete load;
}


void NokiaManager::on_btnLoader_clicked()
{
    load->show();
}

