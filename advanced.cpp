#include "advanced.h"
#include "ui_advanced.h"

#include <QTextCodec>

Advanced::Advanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advanced)
{
    ui->setupUi(this);

    QObject::connect(ui->checkA, &QCheckBox::clicked, this, [this]() {
        ui->checkB->setChecked(false);
        ui->checkCurrentSlot->setChecked(false);
    });
    QObject::connect(ui->checkB, &QCheckBox::clicked, this, [this]() {
        ui->checkA->setChecked(false);
        ui->checkCurrentSlot->setChecked(false);
    });
    QObject::connect(ui->checkCurrentSlot, &QCheckBox::clicked, this, [this]() {
        ui->checkA->setChecked(false);
        ui->checkB->setChecked(false);
    });
}

Advanced::~Advanced()
{
    delete ui;
}


void Advanced::on_btnFlash_clicked()
{
    procFlash = new QProcess;

    if (ui->checkA->isChecked()) {
        QString partition = ui->boxPart->currentText();

        procFlash->setProcessChannelMode(QProcess::MergedChannels);

        QObject::connect(procFlash, &QProcess::readyReadStandardOutput, this, [this]() {
            while (procFlash->canReadLine()) {
                QByteArray BA = procFlash->readLine();
                QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                QString line = codec->toUnicode(BA.data());
                ui->textLog->append(line);
            }
        });

        procFlash->start("tools\\fastboot.exe", QStringList() << "flash" << "" + partition + "_a" << "IMG\\" + partition + ".img");
        procFlash->waitForStarted();
        QObject::connect(procFlash, &QProcess::finished, this, [this]() {
            ui->textLog->append("OK!");
        });
    }
    else if (ui->checkB->isChecked()) {
        QString partition = ui->boxPart->currentText();

        procFlash->setProcessChannelMode(QProcess::MergedChannels);

        QObject::connect(procFlash, &QProcess::readyReadStandardOutput, this, [this]() {
            while (procFlash->canReadLine()) {
                QByteArray BA = procFlash->readLine();
                QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                QString line = codec->toUnicode(BA.data());
                ui->textLog->append(line);
            }
        });

        procFlash->start("tools\\fastboot.exe", QStringList() << "flash" << "" + partition + "_b" << "IMG\\" + partition + ".img");
        procFlash->waitForStarted();
        QObject::connect(procFlash, &QProcess::finished, this, [this]() {
            ui->textLog->append("OK!");
        });
    }
    else if (ui->checkCurrentSlot->isChecked()) {
        QString partition = ui->boxPart->currentText();

        procFlash->setProcessChannelMode(QProcess::MergedChannels);

        QObject::connect(procFlash, &QProcess::readyReadStandardOutput, this, [this]() {
            while (procFlash->canReadLine()) {
                QByteArray BA = procFlash->readLine();
                QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                QString line = codec->toUnicode(BA.data());
                ui->textLog->append(line);
            }
        });

        procFlash->start("tools\\fastboot.exe", QStringList() << "flash" << "" + partition << "IMG\\" + partition + ".img");
        procFlash->waitForStarted();
        QObject::connect(procFlash, &QProcess::finished, this, [this]() {
            ui->textLog->append("OK!");
        });
    }
}

