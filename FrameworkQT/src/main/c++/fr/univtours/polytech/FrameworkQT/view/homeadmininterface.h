#ifndef HOMEADMININTERFACE_H
#define HOMEADMININTERFACE_H

#include <QWidget>

namespace Ui {
class homeAdminInterface;
}

class homeAdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit homeAdminInterface(QWidget *parent = nullptr);
    ~homeAdminInterface();

private:
    Ui::homeAdminInterface *ui;
};

#endif // HOMEADMININTERFACE_H
