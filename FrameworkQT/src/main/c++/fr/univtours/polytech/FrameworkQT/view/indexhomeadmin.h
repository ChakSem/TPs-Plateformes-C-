#ifndef INDEXHOMEADMIN_H
#define INDEXHOMEADMIN_H

#include <QDialog>

namespace Ui {
class indexHomeAdmin;
}

class indexHomeAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit indexHomeAdmin(QWidget *parent = nullptr);
    ~indexHomeAdmin();

private:
    Ui::indexHomeAdmin *ui;
};

#endif // INDEXHOMEADMIN_H
