#ifndef CREATIONUSERINTERFACE_H
#define CREATIONUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class CreationUserInterface;
}

class CreationUserInterface : public QWidget
{
    Q_OBJECT

public:
    void actionAddUseer();
    explicit CreationUserInterface(QWidget *parent = nullptr);
    ~CreationUserInterface();

private:
    Ui::CreationUserInterface *ui;
};

#endif // CREATIONUSERINTERFACE_H
