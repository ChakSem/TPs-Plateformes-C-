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
    explicit UserManagementInterface(QWidget *parent = nullptr);
    ~UserManagementInterface();

    /* Actions réalisées par les boutons */
    void actionAddUser();
    void actionDeleteUser();
    void actionUpdateUser();

private:
    void initializeTableView();

    int init();
    Ui::UserManagementInterface *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
