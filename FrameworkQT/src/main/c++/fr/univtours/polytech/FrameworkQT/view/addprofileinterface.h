#ifndef ADDPROFILEINTERFACE_H
#define ADDPROFILEINTERFACE_H

#include <QWidget>

namespace Ui {
class addProfileInterface;
}

class addProfileInterface : public QWidget
{
    Q_OBJECT

public:
    explicit addProfileInterface(QWidget *parent = nullptr);
    ~addProfileInterface();

private:
    Ui::addProfileInterface *ui;
};

#endif // ADDPROFILEINTERFACE_H
