#ifndef NOKIAMANAGER_H
#define NOKIAMANAGER_H

#include <QWidget>

#include "loader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class NokiaManager; }
QT_END_NAMESPACE

class NokiaManager : public QWidget
{
    Q_OBJECT

public:
    NokiaManager(QWidget *parent = nullptr);
    ~NokiaManager();

private slots:
    void on_btnLoader_clicked();

private:
    Ui::NokiaManager *ui;

    Loader *load;
};
#endif // NOKIAMANAGER_H
