#ifndef TABLEDATAUSERS_H
#define TABLEDATAUSERS_H

#include <QWidget>

namespace Ui {
class indexTableDataUsers;
}

class indexTableDataUsers : public QWidget
{
    Q_OBJECT

public:
    explicit indexTableDataUsers(QWidget *parent = nullptr);
    ~indexTableDataUsers();

private:
    Ui::indexTableDataUsers *ui;
};

#endif // TABLEDATAUSERS_H
