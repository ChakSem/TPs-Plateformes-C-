#ifndef MYACCOUNTINTERFACE_H
#define MYACCOUNTINTERFACE_H

#include <QWidget>

namespace Ui {
class accountInterface;
}

class accountInterface : public QWidget
{
    Q_OBJECT

public:
    explicit accountInterface(QWidget *parent = nullptr);
    ~accountInterface();

private:
    Ui::accountInterface *ui;
};

#endif // MYACCOUNTINTERFACE_H
