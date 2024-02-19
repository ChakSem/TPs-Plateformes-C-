#ifndef HOMEUSERINTERFACE_H
#define HOMEUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class homeUserInterface;
}

class homeUserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit homeUserInterface(QWidget *parent = nullptr);
    ~homeUserInterface();

private:
    Ui::homeUserInterface *ui;
};

#endif // HOMEUSERINTERFACE_H
