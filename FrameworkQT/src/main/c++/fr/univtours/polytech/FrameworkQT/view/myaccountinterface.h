#ifndef MYACCOUNTINTERFACE_H
#define MYACCOUNTINTERFACE_H

#include <QWidget>

namespace Ui {
class MyAccountInterface;
}

class MyAccountInterface : public QWidget
{
    Q_OBJECT

public:
    explicit MyAccountInterface(QWidget *parent = nullptr);
    ~MyAccountInterface();

private:
    Ui::MyAccountInterface *ui;
};

#endif // MYACCOUNTINTERFACE_H
