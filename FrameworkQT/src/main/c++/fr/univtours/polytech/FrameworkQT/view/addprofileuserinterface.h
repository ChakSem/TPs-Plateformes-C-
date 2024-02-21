#ifndef ADDPROFILEUSERINTERFACE_H
#define ADDPROFILEUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class addProfileUserInterface;
}

class addProfileUserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit addProfileUserInterface(QWidget *parent = nullptr);
    void actionCreateUserProfile();
    ~addProfileUserInterface();

private:
    Ui::addProfileUserInterface *ui;
};

#endif // ADDPROFILEUSERINTERFACE_H
