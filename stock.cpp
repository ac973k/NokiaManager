#include "stock.h"
#include "ui_stock.h"

#include <QNetworkRequest>
#include <QFile>
#include <QDir>

#include <QMessageBox>
#include <QTextCodec>

Stock::Stock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stock)
{
    ui->setupUi(this);

    path = "Android";

    procUnpack = new QProcess;
    procFlash = new QProcess;

    QDir dir(path);
    if (!dir.exists())
    {
        dir.mkdir(".");
    }

    managerDownload = new QNetworkAccessManager();
}

Stock::~Stock()
{
    delete managerDownload;
    delete procFlash;
    delete procUnpack;

    delete ui;
}

void Stock::on_btnDownload_clicked()
{
    QNetworkReply *reply;

    if (ui->boxAndroid->currentText() == "Android 9") {
        ui->textBrowser->append("Download Android 9");

        uFile = new QFile(path + "\\Android_9.7z");
           // Пробуем открыть файл
        if (!uFile->open(QIODevice::WriteOnly))
        {
            delete uFile;
            uFile = nullptr;
        }

        url = "https://github.com/ac973k/NokiaManager/releases/download/Android9/Android_9.7z";

        // Создаём запрос
        QNetworkRequest request(url);
        // Обязательно разрешаем переходить по редиректам
        request.setAttribute(QNetworkRequest::RedirectionTargetAttribute, true);
        // Запускаем скачивание

        reply = managerDownload->get(request);
    }
    else if (ui->boxAndroid->currentText() == "Android 10")
    {
        ui->textBrowser->append("Download Android 10");

        uFile = new QFile(path + "\\Android_10.7z");
           // Пробуем открыть файл
        if (!uFile->open(QIODevice::WriteOnly))
        {
            delete uFile;
            uFile = nullptr;
        }

        url = "https://github.com/ac973k/NokiaManager/releases/download/Android10/Android_10.7z";

        // Создаём запрос
        QNetworkRequest request(url);
        // Обязательно разрешаем переходить по редиректам
        request.setAttribute(QNetworkRequest::RedirectionTargetAttribute, true);
        // Запускаем скачивание

        reply = managerDownload->get(request);
    }
    else if (ui->boxAndroid->currentText() == "Android 11")
    {
             ui->textBrowser->append("Download Android 11");

             uFile = new QFile(path + "\\Android_11.7z");
                // Пробуем открыть файл
             if (!uFile->open(QIODevice::WriteOnly))
             {
                 delete uFile;
                 uFile = nullptr;
             }

             url = "https://github.com/ac973k/NokiaManager/releases/download/Android11/Android_11.7z";

             // Создаём запрос
             QNetworkRequest request(url);
             // Обязательно разрешаем переходить по редиректам
             request.setAttribute(QNetworkRequest::RedirectionTargetAttribute, true);
             // Запускаем скачивание

             reply = managerDownload->get(request);
    }

    QObject::connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onProgress(qint64, qint64)));
    QObject::connect(managerDownload, SIGNAL(finished(QNetworkReply *)), this, SLOT(onDownloadResult(QNetworkReply*))); //отправляем данные и получаем ответ успешно или ошибка
}

void Stock::onDownloadResult(QNetworkReply *replyD)
{

    if(!replyD->error())
    {
        uFile->open(QFile::WriteOnly);
        uFile->write(replyD->readAll());
        uFile->flush();
    }
    else
    {
        ui->textBrowser->append(replyD->errorString());
        replyD->abort();
        replyD->deleteLater();
    }

    uFile->close();
    delete uFile;
    uFile = nullptr;

    replyD->deleteLater();

    ui->textBrowser->append("Загрузка Завершена!");
    ui->textBrowser->append("Файл: " + path + "\\" + replyD->request().url().fileName());
}

void Stock::onProgress(qint64 receivedSize, qint64 totalSize)
{
    ui->textBrowser->clear();
    ui->textBrowser->append("Загружено: " + QString::number(receivedSize/1024/1024) + "MB / " + QString::number(totalSize/1024/1024) + "MB");
}

void Stock::on_btnFlash_clicked()
{
    QString filename;

    if (ui->boxAndroid->currentText() == "Android 9")
    {
        filename = "Android_9";
    }
    else if (ui->boxAndroid->currentText() == "Android 10")
    {
        filename = "Android_10";
    }
    else if (ui->boxAndroid->currentText() == "Android 11")
    {
        filename = "Android_11";
    }

    procUnpack->setProcessChannelMode(QProcess::MergedChannels);

    procFlash->setProcessChannelMode(QProcess::MergedChannels);
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString batFilePath = appDirPath + "/Android/"+ filename +"/flash_all.bat";
    QString batFileDirPath = QFileInfo(batFilePath).absolutePath();
    procFlash->setWorkingDirectory(batFileDirPath);

    ui->textBrowser->append(batFilePath);

    QObject::connect(procUnpack, &QProcess::readyReadStandardOutput, this, [this]() {
        while (procUnpack->canReadLine()) {
            QByteArray BA = procUnpack->readLine();
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

    procUnpack->start("tools\\7za.exe", QStringList() << "-oAndroid\\" << "x" << "Android\\" + filename + ".7z");
    procUnpack->waitForStarted();
    connect(procUnpack, &QProcess::finished, this, [this, batFilePath]() {
        procFlash->start("cmd.exe", QStringList() << "/c" << batFilePath);
    });
    procFlash->waitForFinished();




}

