#include "homeuserinterface.h"
#include "ui_homeuserinterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

HomeUserInterface::HomeUserInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeUserInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeUserInterface::actionAccount);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeUserInterface::actionProfile);
}

HomeUserInterface::~HomeUserInterface()
{
    delete ui;
}


void HomeUserInterface::actionAccount() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openAccount(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void HomeUserInterface::actionProfile() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openMyProfiles(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}
