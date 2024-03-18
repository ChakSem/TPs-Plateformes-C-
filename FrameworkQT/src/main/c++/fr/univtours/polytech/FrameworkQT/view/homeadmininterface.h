#ifndef HOMEADMININTERFACE_H
#define HOMEADMININTERFACE_H

#include <QWidget>

namespace Ui
{
    class HomeAdminInterface;
}

class HomeAdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit HomeAdminInterface(QWidget *parent = nullptr);
    ~HomeAdminInterface();

    /* Actions réalisées par les boutons */
    void actionAccount();
    void actionProfile();
    void actionUser();

private:
    Ui::HomeAdminInterface *ui;
};

#endif // HOMEADMININTERFACE_H
