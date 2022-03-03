#include "root.h"
#include "ui_root.h"

#include <QMessageBox>

Root::Root(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Root)
{
    ui->setupUi(this);

    proc = new QProcess;


}

Root::~Root()
{
    delete ui;

    delete proc;
}

void Root::on_btnRoot_clicked()
{
    proc->setProcessChannelMode(QProcess::MergedChannels);
    proc->start("tools\\adb.exe", QStringList() << "reboot-bootloader");
    ui->textBrowser->append("Перезагружаемся в fastboot...");

    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "Root", "Перезагрузился в fastboot?",
    QMessageBox::Ok);

    if(msgBox->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\fastboot.exe", QStringList() << "boot" << "tools\\twrp.img");
        ui->textBrowser->append("Загружаемся в патченное recovery...");

        delete msgBox;
    }

    QMessageBox *msgBoxA = new QMessageBox(QMessageBox::Information, "Root", "Перейдите в Дополнительно/ADB Sideload",
    QMessageBox::Ok);
    if(msgBoxA->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\adb.exe", QStringList() << "sideload" << "tools\\magisk.zip");
        ui->textBrowser->append("Root...");

        delete msgBoxA;
    }

    QMessageBox *msgBoxB = new QMessageBox(QMessageBox::Information, "Root", "Подождите, пока установится root! После перезагрузки зайдите в приложение Magisk",
    QMessageBox::Ok);
    if(msgBoxB->exec() == QMessageBox::Ok)
    {
        proc->start("tools\\adb.exe", QStringList() << "reboot");
        ui->textBrowser->append("Root...");

        delete msgBoxB;
    }

    QMessageBox *msgBoxC = new QMessageBox(QMessageBox::Information, "Root", "После обновления приложения, зайдите в него и выбирите Magisk->Автоматическая установка для полной установки root",
    QMessageBox::Ok);
    msgBoxC->exec();

    delete msgBoxC;
}

