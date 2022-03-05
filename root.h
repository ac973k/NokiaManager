#ifndef ROOT_H
#define ROOT_H

#include <QWidget>

#include <QProcess>

namespace Ui {
class Root;
}

class Root : public QWidget
{
    Q_OBJECT

public:
    explicit Root(QWidget *parent = nullptr);
    ~Root();

private slots:
    void on_btnRoot_clicked();

private:
    Ui::Root *ui;

    QProcess *proc;
};

#endif // ROOT_H
