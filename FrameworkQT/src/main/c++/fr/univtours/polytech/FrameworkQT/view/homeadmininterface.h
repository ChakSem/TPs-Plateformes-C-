#ifndef HOMEADMININTERFACE_H
#define HOMEADMININTERFACE_H

#include <QWidget>

namespace Ui {
class HomeAdminInterface;
}

class HomeAdminInterface : public QWidget
{
    Q_OBJECT

public:
    void actionAccount();
    void actionDatabase();
    void actionProfile();
    void actionUser();
    explicit HomeAdminInterface(QWidget *parent = nullptr);
    ~HomeAdminInterface();

private:
    Ui::HomeAdminInterface *ui;
};

#endif // HOMEADMININTERFACE_H
