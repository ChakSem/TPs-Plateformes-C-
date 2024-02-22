#include "profilesinterface.h"
#include "ui_profilesinterface.h"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "mainwindow.h"

ProfilesInterface::ProfilesInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProfilesInterface)
{
    ui->setupUi(this);
    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &ProfilesInterface::actionAddInterface);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &ProfilesInterface::actionDeleteInterface);
    connect( ui->pushButtonManage, &QPushButton::clicked, this, &ProfilesInterface::actionManageInterface);
    connect( ui->pushButtonUpdate, &QPushButton::clicked, this, &ProfilesInterface::actionUpdateInterface);
}

ProfilesInterface::~ProfilesInterface()
{
    delete ui;
}

void ProfilesInterface::actionAddInterface() {
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->openAddProfilesFromProfiles();
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void ProfilesInterface::actionDeleteInterface() {

}

void ProfilesInterface::actionManageInterface() {

}

void ProfilesInterface::actionUpdateInterface() {

}

