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
    explicit CreationUserInterface(QWidget *parent = nullptr);
    ~CreationUserInterface();

    /* Actions réalisées par les boutons */
    void actionAddUseer();

private:
    Ui::CreationUserInterface *ui;
};

#endif // CREATIONUSERINTERFACE_H
