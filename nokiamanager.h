#ifndef NOKIAMANAGER_H
#define NOKIAMANAGER_H

#include <QWidget>

#include "loader.h"
#include "root.h"
#include "stock.h"
#include "stockgsi.h"
#include "advanced.h"
#include "about.h"

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

    void on_btnRoot_clicked();

    void on_btnStock_clicked();

    void on_btnCustom_clicked();

    void on_btnAdvanced_clicked();

    void on_btnAbout_clicked();

private:
    Ui::NokiaManager *ui;

    Loader *load;
    Root *root;
    Stock *stock;
    StockGSI *stockGSI;
    Advanced *advanced;
    About *about;
};
#endif // NOKIAMANAGER_H
