#include "loader.h"
#include "ui_loader.h"

#include <QMessageBox>

Loader::Loader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loader)
{
    ui->setupUi(this);

    proc = new QProcess;
}

Loader::~Loader()
{
    delete ui;

    delete proc;
}

void Loader::on_btnLock_clicked()
{
    proc->setProcessChannelMode(QProcess::MergedChannels);
    proc->start("tools\\adb.exe", QStringList() << "reboot-bootloader");
    ui->textBrowser->append("Перезагружаемся в fastboot...");

    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Loader Lock", "Перезагрузился в fastboot?",
    QMessageBox::Ok);

    if(msgBox->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\fastboot.exe", QStringList() << "oem" << "lock-go");
        ui->textBrowser->append("Блокируем loader...");

        delete msgBox;
    }
}


void Loader::on_btnUnlock_clicked()
{
    proc->setProcessChannelMode(QProcess::MergedChannels);
    proc->start("tools\\adb.exe", QStringList() << "reboot-bootloader");
    ui->textBrowser->append("Перезагружаемся в fastboot...");

    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Loader Unlock", "Перезагрузился в fastboot?",
    QMessageBox::Ok);

    if(msgBox->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\fastboot.exe", QStringList() << "flashing" << "get_unlock_ability");
        ui->textBrowser->append("Разблокировка loader...");

        delete msgBox;
    }

    QMessageBox *msgBoxA = new QMessageBox(QMessageBox::Information, "Loader Unlock", "Следуйте инструкциям на экране телефона... После этого, нажмите OK",
    QMessageBox::Ok);
    if(msgBoxA->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\fastboot.exe", QStringList() << "oem" << "unlock-go");
        ui->textBrowser->append("Unlock...");

        delete msgBoxA;
    }

    QMessageBox *msgBoxB = new QMessageBox(QMessageBox::Information, "Loader Unlock", "Готово. Перезагрузка...",
    QMessageBox::Ok);
    if(msgBoxB->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\fastboot.exe", QStringList() << "reboot");
        ui->textBrowser->append("Reboot...");

        delete msgBoxB;
    }
}

