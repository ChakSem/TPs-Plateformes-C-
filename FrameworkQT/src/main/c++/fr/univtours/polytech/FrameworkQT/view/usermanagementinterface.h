#ifndef USERMANAGEMENTINTERFACE_H
#define USERMANAGEMENTINTERFACE_H

#include <QWidget>
#include <QStandardItemModel>

#define NO_LINE_SELECTED -1
#define SUPER_ADMIN "59b1fca3"

class User;

namespace Ui {
class UserManagementInterface;
}

class UserManagementInterface : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagementInterface(QWidget *parent = nullptr);
    ~UserManagementInterface();

    /* Actions réalisées par les boutons */
    void actionAddUser();
    void actionDeleteUser();
    void actionUpdateUser();
    void insertNewUser(User* user);

private:
    void initializeTableView();
    int init();

    QStandardItemModel *model;
    int row;
    Ui::UserManagementInterface *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
