#ifndef ACCOUNTINTERFACE_H
#define ACCOUNTINTERFACE_H

#include <QWidget>

namespace Ui {
class accountinterface;
}

class accountinterface : public QWidget
{
    Q_OBJECT

public:
    explicit accountinterface(QWidget *parent = nullptr);
    ~accountinterface();

private:
    Ui::accountinterface *ui;
};

#endif // ACCOUNTINTERFACE_H
