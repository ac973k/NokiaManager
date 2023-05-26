#include "stockgsi.h"
#include "ui_stockgsi.h"

#include <QTextCodec>

StockGSI::StockGSI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockGSI)
{
    ui->setupUi(this);

    procDisableAuth = new QProcess;
    procFlash = new QProcess;
}

StockGSI::~StockGSI()
{
    delete procDisableAuth;
    delete procFlash;

    delete ui;
}

void StockGSI::on_btnFlash_clicked()
{
    procDisableAuth->setProcessChannelMode(QProcess::MergedChannels);

    QObject::connect(procDisableAuth, &QProcess::readyReadStandardOutput, this, [this]() {
        while (procDisableAuth->canReadLine()) {
            QByteArray BA = procDisableAuth->readLine();
            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
            QString line = codec->toUnicode(BA.data());
            ui->textBrowser->append(line);
        }
    });

    QObject::connect(procFlash, &QProcess::readyReadStandardOutput, this, [this]() {
        while (procFlash->canReadLine()) {
            QByteArray BA = procFlash->readLine();
            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
            QString line = codec->toUnicode(BA.data());
            ui->textBrowser->append(line);
        }
    });

    procDisableAuth->start("tools\\fastboot.exe", QStringList() << "--disable-verity" << "--disable-verification" << "flash" << "vbmeta" << "GSI\\vbmeta.img");
    procDisableAuth->waitForStarted();
    connect(procDisableAuth, &QProcess::finished, this, [this]() {
        ui->textBrowser->append("Firmware...");
        procFlash->start("tools\\fastboot.exe", QStringList() << "flash" << "system" << "GSI\\system.img");
    });
    procFlash->waitForFinished();
    connect(procFlash, &QProcess::finished, this, [this]() {
        ui->textBrowser->append("OK!");
    });
}

