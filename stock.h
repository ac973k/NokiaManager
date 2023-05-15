#ifndef STOCK_H
#define STOCK_H

#include <QWidget>

#include <QFile>

#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class Stock;
}

class Stock : public QWidget
{
    Q_OBJECT

public:
    explicit Stock(QWidget *parent = nullptr);
    ~Stock();

private slots:
    void on_btnDownload_clicked();
    void on_btnFlash_clicked();

    void onDownloadResult(QNetworkReply *replyD);

    void onProgress(qint64 receivedSize, qint64 totalSize);

private:
    Ui::Stock *ui;

    QString url;
    QString path;

    QFile *uFile;

    QNetworkAccessManager *managerDownload;
};

#endif // STOCK_H
