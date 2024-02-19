#ifndef USERMANAGEMENTINTERFACE_H
#define USERMANAGEMENTINTERFACE_H

#include <QWidget>

namespace Ui {
class UserManagementInterface;
}

class UserManagementInterface : public QWidget
{
    Q_OBJECT

public:
    void actionAddUser();
    void actionDeleteUser();
    void actionUpdateUser();
    explicit UserManagementInterface(QWidget *parent = nullptr);
    ~UserManagementInterface();

private:
    Ui::UserManagementInterface *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
