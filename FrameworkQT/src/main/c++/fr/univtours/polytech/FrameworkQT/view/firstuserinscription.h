#ifndef FIRSTUSERINSCRIPTION_H
#define FIRSTUSERINSCRIPTION_H

#include <QWidget>

namespace Ui {
class FirstUserInscription;
}

class FirstUserInscription : public QWidget
{
    Q_OBJECT

public:
    explicit FirstUserInscription(QWidget *parent = nullptr);
    void actionAddUser();
    ~FirstUserInscription();

private:
    Ui::FirstUserInscription *ui;
};

#endif // FIRSTUSERINSCRIPTION_H
