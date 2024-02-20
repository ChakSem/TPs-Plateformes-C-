#include "homeadmininterface.h"
#include "ui_homeadmininterface.h"
#include "../utils/exception.h"
#include "mainwindow.h"

HomeAdminInterface::HomeAdminInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeAdminInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAccount, &QPushButton::clicked, this, &HomeAdminInterface::actionAccount);
    connect( ui->pushButtonDatabase, &QPushButton::clicked, this, &HomeAdminInterface::actionDatabase);
    connect( ui->pushButtonProfile, &QPushButton::clicked, this, &HomeAdminInterface::actionProfile);
    connect( ui->pushButtonUser, &QPushButton::clicked, this, &HomeAdminInterface::actionUser);
}

HomeAdminInterface::~HomeAdminInterface()
{
    delete ui;
}

void HomeAdminInterface::actionAccount() {
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

void HomeAdminInterface::actionDatabase() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openDatabases(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void HomeAdminInterface::actionProfile() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openProfiles(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void HomeAdminInterface::actionUser() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openUsers(); // On affiche le bouton deconnexion
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}
