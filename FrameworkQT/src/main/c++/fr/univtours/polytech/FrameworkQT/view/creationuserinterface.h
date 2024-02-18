#ifndef CREATIONUSERINTERFACE_H
#define CREATIONUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class creationuserinterface;
}

class creationuserinterface : public QWidget
{
    Q_OBJECT

public:
    explicit creationuserinterface(QWidget *parent = nullptr);
    ~creationuserinterface();

private:
    Ui::creationuserinterface *ui;
};

#endif // CREATIONUSERINTERFACE_H
