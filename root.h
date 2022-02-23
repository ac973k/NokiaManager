#ifndef ROOT_H
#define ROOT_H

#include <QWidget>

namespace Ui {
class Root;
}

class Root : public QWidget
{
    Q_OBJECT

public:
    explicit Root(QWidget *parent = nullptr);
    ~Root();

private:
    Ui::Root *ui;
};

#endif // ROOT_H
