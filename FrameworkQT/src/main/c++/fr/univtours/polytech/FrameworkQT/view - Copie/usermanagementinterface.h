#ifndef USERMANAGEMENTINTERFACE_H
#define USERMANAGEMENTINTERFACE_H

#include <QWidget>

namespace Ui {
class GestionUtilisateur;
}

class GestionUtilisateur : public QWidget
{
    Q_OBJECT

public:
    explicit GestionUtilisateur(QWidget *parent = nullptr);
    ~GestionUtilisateur();

private:
    Ui::GestionUtilisateur *ui;
};

#endif // USERMANAGEMENTINTERFACE_H
