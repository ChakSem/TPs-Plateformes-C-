#ifndef USERMANAGEMENTINTERFACE_H
#define USERMANAGEMENTINTERFACE_H

#include <QWidget>

#define NO_LINE_SELECTED -1

namespace Ui {
class UserManagementInterface;
}

class UserManagementInterface : public QWidget
{
    Q_OBJECT

public:
    void initializeTableView();

    void actionAddUser();
    void actionDeleteUser();
    void actionUpdateUser();
    explicit UserManagementInterface(QWidget *parent = nullptr);
    ~UserManagementInterface();

private:
    int init();
    Ui::UserManagementInterface *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
