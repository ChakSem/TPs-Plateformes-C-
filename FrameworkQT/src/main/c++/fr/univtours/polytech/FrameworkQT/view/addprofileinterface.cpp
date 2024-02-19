#include "addprofileinterface.h"
#include "ui_addprofileinterface.h"

AddProfileInterface::AddProfileInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddProfileInterface)
{
    ui->setupUi(this);
    connect( ui->pushButton, &QPushButton::clicked, this, &AddProfileInterface::actionAddProfile);  
}

void AddProfileInterface::actionAddProfile()
{
    QString name = ui->idLogin->text();
    if(name.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Le nom du profil ne peut pas être vide");
        return;
    }
    if(ui->radioButoonReadRight->isChecked())
    {
        emit addProfile(name, 1);
    }
    else if(ui->radioButoonReadUpdateRight->isChecked())
    {
        emit addProfile(name, 2);
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Veuillez selectionner un droit");
        return;
    }
    this->close();
}


AddProfileInterface::~AddProfileInterface()
{
    delete ui;
}
