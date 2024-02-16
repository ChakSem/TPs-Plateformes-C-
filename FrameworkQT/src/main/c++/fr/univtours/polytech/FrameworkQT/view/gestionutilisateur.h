#ifndef GESTIONUTILISATEUR_H
#define GESTIONUTILISATEUR_H

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

#endif // GESTIONUTILISATEUR_H
