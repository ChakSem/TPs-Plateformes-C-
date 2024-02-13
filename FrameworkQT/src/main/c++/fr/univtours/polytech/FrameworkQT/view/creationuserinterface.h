#ifndef CREATIONUSERINTERFACE_H
#define CREATIONUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class creationUserInterface;
}

class creationUserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit creationUserInterface(QWidget *parent = nullptr);
    ~creationUserInterface();

private:
    Ui::creationUserInterface *ui;
};

#endif // CREATIONUSERINTERFACE_H
