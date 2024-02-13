#ifndef INDEXTABLEDATAUSERS_H
#define INDEXTABLEDATAUSERS_H

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

#endif // INDEXTABLEDATAUSERS_H
