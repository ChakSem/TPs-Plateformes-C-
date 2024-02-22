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
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openAccount(); // On ouvre l'interface de visionage du compte
    }
}

void HomeUserInterface::actionProfile() {
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    /* S'il n'y a pas eu d'erreur */
    if (mainWindow != NULL) {
        mainWindow->openMyProfiles(); // On ouvre l'interface des profils pour l'utilisateur connecté

    }
}
