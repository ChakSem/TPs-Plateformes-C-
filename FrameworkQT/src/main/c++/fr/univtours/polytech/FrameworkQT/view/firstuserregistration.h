#ifndef FIRSTUSERREGISTRATION_H
#define FIRSTUSERREGISTRATION_H

#include <QWidget>

namespace Ui {
class firstUserRegistration;
}

class firstUserRegistration : public QWidget
{
    Q_OBJECT

public:
    explicit firstUserRegistration(QWidget *parent = nullptr);
    ~firstUserRegistration();

private:
    Ui::firstUserRegistration *ui;
};

#endif // FIRSTUSERREGISTRATION_H
