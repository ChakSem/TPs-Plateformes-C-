#ifndef USERMANAGEMENTINTERFACE_H
#define USERMANAGEMENTINTERFACE_H

#include <QWidget>
#include <QStandardItemModel>

#define NO_LINE_SELECTED -1

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

private:
    void initializeTableView();
    int init();
    void insertNewUser(User* user);

    QStandardItemModel *model;
    int row;
    Ui::UserManagementInterface *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
