#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include <QLabel>
#include <QDebug>

/**
 * Permet de récupérer une réference sur l'objet parent MainWindow depuis un QWidget d'un StackedWidget du MainWindow
 * Entrée : widget, QWidget* : le QWidget qui appelle cette méthode
 * Sortie : MainWindow*
 */
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

    if(Controller::isThereUsers() == SOME_USERS) {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    } else {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_FIRST_USER_REGISTRATION);
    }

    openConnection();

    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID);
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);
    
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

    switch(success) {
    case SUCCESS_ADMIN:
        ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_ADMIN); // Access au Home Admin
        displayDeconnection();

        previousPages.push_front(MAINWIDGET_HOME_ADMIN); // On ajoute MAINWIDGET_HOME_ADMIN au chemin pour le retour
        break;
    case SUCCESS_USER:
        ui->MainWidget->setCurrentIndex(MAINWIDGET_HOME_USER); // Access au Home User
        displayDeconnection();

        previousPages.push_front(MAINWIDGET_HOME_USER); // On ajoute MAINWIDGET_HOME_USER au chemin pour le retour
        break;
    default:
         // TODO : Gerer cas echec de la connexion
        ;
    }
}

void MainWindow::actionDeconnection() {
    Controller::deconnection(); // On gere la deconnexion pour les donnees
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID); // On fait disparaitre le bouton deconnexion

    previousPages.clear(); // On réinitialise previousPages
}

void MainWindow::openConnection() {

    /* Si aucun compte user n'existent, on est amené sur une page de création d'un compte user */
    if(Controller::isThereUsers() == SOME_USERS) {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    } else {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_FIRST_USER_REGISTRATION);
    }
}

void MainWindow::openUsers() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_USER_MANAGEMENT); // Access à la page de gestion des utilisateurs
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    previousPages.push_front(MAINWIDGET_USER_MANAGEMENT); // On ajoute MAINWIDGET_USER_MANAGEMENT au chemin pour le retour
}

void MainWindow::openAccount() {
    // TODO : visualiser compte (optionnel)
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);

    // previousPages.push_front(MAINWIDGET_CONNECTION); // On ajoute MAINWIDGET_USER_MANAGEMENT au chemin pour le retour
}

void MainWindow::openMyProfiles() {
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    Controller::openUserProfilesForCurrentUser();

    openProfiles();
}

void MainWindow::openProfiles(User* user) {
    Controller::openUserProfiles(user);

    openProfiles();
}

void MainWindow::openProfiles() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_PROFILES); // Access à la page de gestion des profils

    if(Controller::hasProfiles() == NO_PROFILES) {
        openAddProfiles(); // Si l'utilisateur n'a pas encore de profils, on est emmené sur la page de création de profils
    } else {
        /* Si MAINWIDGET_PROFILES n'est pas déjà empilé */
        if(previousPages.front() != MAINWIDGET_PROFILES) {
            previousPages.push_front(MAINWIDGET_PROFILES); // On ajoute MAINWIDGET_PROFILES au chemin pour le retour
        }

        /* On initialise son élement combobox */
        QWidget* widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_PROFILES);
        qobject_cast<ProfilesInterface*>(widgetToRefresh)->initializeComboBox();
    }
}

void MainWindow::openDatabases() {
    // TODO : partie 2
    // ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);

    // previousPages.push_front(MAINWIDGET_CONNECTION); // On ajoute MAINWIDGET_CONNECTION au chemin pour le retour
}

void MainWindow::openCreateUser() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ACCOUNT_CREATION); // Access à la page de creation d'utilisateurs

    previousPages.push_front(MAINWIDGET_ACCOUNT_CREATION); // On ajoute MAINWIDGET_ACCOUNT_CREATION au chemin pour le retour
}

void MainWindow::openAddProfiles() {
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ADD_PROFILE); // Access à la page d'ajout de profils

    previousPages.push_front(MAINWIDGET_ADD_PROFILE); // On ajoute MAINWIDGET_ADD_PROFILE au chemin pour le retour
}

void MainWindow::updateTableView(User* user){
    UserManagementInterface* userManagementInterface = qobject_cast<UserManagementInterface*>(this->ui->MainWidget->widget(1));
    userManagementInterface->insertNewUser(user);
}

/**
 * Permet de gérer le retour sur la page précedente
 * Entrée :
 * Sortie :
 */
void MainWindow::returnOnPreviousView() {
    previousPages.pop_front(); // On retire la reference vers la page actuelle
    int previousPage = previousPages.front(); // On stocke le numero de la nouvelle page

    ui->MainWidget->setCurrentIndex(previousPage); // On va sur la nouvelle page

    switch(previousPage) {
    case MAINWIDGET_USER_MANAGEMENT:
        Controller::closeUserProfiles();

        break;
    case MAINWIDGET_HOME_ADMIN:
    case MAINWIDGET_HOME_USER:
        ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);
        Controller::closeUserProfiles();

        break;
    }
}
