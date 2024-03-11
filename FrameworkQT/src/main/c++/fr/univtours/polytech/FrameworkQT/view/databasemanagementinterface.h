#ifndef DATABASEMANAGEMENTINTERFACE_H
#define DATABASEMANAGEMENTINTERFACE_H

#include <QWidget>

namespace Ui {
class DatabaseManagementInterface;
}

class DatabaseManagementInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseManagementInterface(QWidget *parent = nullptr);
    ~DatabaseManagementInterface();

private:
    Ui::DatabaseManagementInterface *ui;
};

#endif // DATABASEMANAGEMENTINTERFACE_H
