#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include <QLabel>

MainWindow* MainWindow::accessToParent(QWidget* widget) {
    try {
        QWidget *parentWidget = widget->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            return mainWindow;
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
        return NULL;
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID);
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);

    previousPage = MAINWIDGET_CONNECTION;
    
    qDebug() << "Stacked Widget Deconnection initialized with current index:" << ui->DeconnectionWidget->currentIndex();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayDeconnection() {
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VISIBLE); // On affiche le bouton deconnexion
}

void MainWindow::actionConnection(QString id, QString password) {
    unsigned int success = Controller::connection(id, password);
    if (success == SUCCESS_ADMIN) {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_ADMIN); // Access au Home Admin
        displayDeconnection();

        previousPage = MAINWIDGET_HOME_ADMIN; // On initialise pour le bouton de retour
    } else {
        if (success == SUCCESS_USER) {
            ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_USER); // Access au Home User
            displayDeconnection();

            previousPage = MAINWIDGET_HOME_USER; // On initialise pour le bouton de retour
        } else {

            // TODO : Gerer cas echec de la connexion
        }
    }
}

void MainWindow::actionDeconnection() {
    Controller::deconnection(); // On gere la deconnexion pour les donnees
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID); // On fait disparaitre le bouton deconnexion

    previousPage = MAINWIDGET_CONNECTION;
}

void MainWindow::openUsers() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_USER_MANAGEMENT); // Access à la page de gestion des utilisateurs
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    /* On initialise son élement tableview */
    QWidget* widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_USER_MANAGEMENT);
    qobject_cast<UserManagementInterface*>(widgetToRefresh)->initializeTableView();
}

void MainWindow::openAccount() {
    // TODO : visualiser compte (optionnel)
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
}

void MainWindow::openMyProfiles() {
    // TODO : Gerer la recuperation de l'utilisateur dont on visione les profils
    ui->MainWidget->setCurrentIndex(MAINWIDGET_PROFILES); // Access à la page de gestion des profils
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    Controller::openUserProfilesForCurrentUser();

    /* On initialise son élement combobox */
    QWidget* widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_PROFILES);
    qobject_cast<ProfilesInterface*>(widgetToRefresh)->initializeComboBox();
}

void MainWindow::openDatabases() {
    // TODO : partie 2
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
}

void MainWindow::openCreateUser() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ACCOUNT_CREATION); // Access à la page de creation d'utilisateurs
}

void MainWindow::openAddProfilesFromProfiles() {
    previousPage = MAINWIDGET_PROFILES;
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ACCOUNT_CREATION); // Access à la page d'ajout de profils
}

void MainWindow::openAddProfiles(User* user) {
    Controller::openUserProfiles(user);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ADD_PROFILE); // Access à la page d'ajout de profils
}

void MainWindow::openProfiles(User* user) {
    Controller::openUserProfiles(user);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_PROFILES); // Access à la page de gestion des profils d'un utilisateur

    /* On initialise son élement combobox */
    QWidget* widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_PROFILES);
    qobject_cast<ProfilesInterface*>(widgetToRefresh)->initializeComboBox();
}


void MainWindow::returnOnPreviousView() {
    ui->MainWidget->setCurrentIndex(previousPage);

    switch(previousPage) {
    case MAINWIDGET_USER_MANAGEMENT:
        Controller::closeUserProfiles();

        if(Controller::isAdmin() == ADMIN) {
            previousPage = MAINWIDGET_HOME_ADMIN;
        } else {
            previousPage = MAINWIDGET_HOME_USER;
        }

        break;
    case MAINWIDGET_PROFILES:
        //if(Controller::getUserProfiles()->getId() == Controller::getUserConnected()->getId()) //
        // TODO : Gerer comment on a acceder a newProfile
        previousPage = MAINWIDGET_USER_MANAGEMENT;
        break;
    case MAINWIDGET_HOME_ADMIN:
    case MAINWIDGET_HOME_USER:
        ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);
        Controller::closeUserProfiles();
        break;
    }
}
