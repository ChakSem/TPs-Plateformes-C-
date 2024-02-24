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
    ~FirstUserInscription();

    /* Actions réalisées par les boutons */
    void actionAddUser();

private:
    Ui::FirstUserInscription *ui;
};

#endif // FIRSTUSERINSCRIPTION_H
