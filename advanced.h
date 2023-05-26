#ifndef ADVANCED_H
#define ADVANCED_H

#include <QWidget>

#include <QProcess>

namespace Ui {
class Advanced;
}

class Advanced : public QWidget
{
    Q_OBJECT

public:
    explicit Advanced(QWidget *parent = nullptr);
    ~Advanced();

private slots:

    void on_btnFlash_clicked();

private:
    Ui::Advanced *ui;

    QProcess *procFlash;
};

#endif // ADVANCED_H
