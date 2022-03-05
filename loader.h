#ifndef LOADER_H
#define LOADER_H

#include <QWidget>

#include <QProcess>

namespace Ui {
class Loader;
}

class Loader : public QWidget
{
    Q_OBJECT

public:
    explicit Loader(QWidget *parent = nullptr);
    ~Loader();

private slots:
    void on_btnLock_clicked();

    void on_btnUnlock_clicked();

private:
    Ui::Loader *ui;

    QProcess *proc;
};

#endif // LOADER_H
