#ifndef HOMEUSERINTERFACE_H
#define HOMEUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class HomeUserInterface;
}

class HomeUserInterface : public QWidget
{
    Q_OBJECT

public:
    void actionAccount();
    void actionProfile();
    explicit HomeUserInterface(QWidget *parent = nullptr);
    ~HomeUserInterface();

private:
    Ui::HomeUserInterface *ui;
};

#endif // HOMEUSERINTERFACE_H
