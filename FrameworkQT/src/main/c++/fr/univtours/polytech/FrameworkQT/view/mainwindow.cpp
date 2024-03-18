#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

/**
 * Permet de récupérer une réference sur l'objet parent MainWindow depuis un QWidget d'un StackedWidget du MainWindow
 * Entrée : widget, QWidget* : le QWidget qui appelle cette méthode
 * Sortie : MainWindow*
 */
MainWindow *MainWindow::accessToParent(QWidget *widget)
{
    try
    {
        QWidget *parentWidget = widget->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow *>(parentWidget);
        if (mainWindow)
        {
            return mainWindow;
        }
        else
        {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception *e)
    {
        e->EXCAffichageErreur();
        delete e;
        return NULL;
    }
}

/**
 * permet d'afficher un message d'erreur en fonction du type
 * Entrée : - message, QString : le message à afficher
 *         - title, QString : le titre du message
 *        - type, int : le type de message de message
 *          (0: Ok, 1: Reply (Yes/No))
 * Sortie : bool : true si le message est de type Reply et que l'utilisateur a cliqué sur Yes, false sinon
 */
bool MainWindow::messageDialog(QString message, QString title, int type)
{
    try {
        /* En fonction du type de message on affiche un QMessageBox différent */
        switch (type)
        {
        case MESSAGEBOX_OK:
            QMessageBox::information(nullptr, title, message); // nullprt car on est dans un static et qu'on ne peut pas acceder à this
            break;
        case MESSAGEBOX_REPLY:
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(nullptr, title, message, QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::Yes)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        default :
            throw new Exception(ERREUR_FATALE);
        }
    } catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;

        return false;
    }
}

/**
 * Constructeur de la classe MainWindow
 * Entrée :
 * Sortie :
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (Controller::isThereUsers() == SOME_USERS)
    {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    }
    else
    {
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

/**
 * Permet d'afficher le bouton de deconnexion
 * Entrée :
 * Sortie :
 */
void MainWindow::displayDeconnection()
{
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VISIBLE); // On affiche le bouton deconnexion
}

/**
 * Permet de gérer la connexion de l'utilisateur et de le rediriger vers l'interface (home) correspondante (Admin ou User)
 * Entrée : id, QString : l'identifiant de l'utilisateur
 *         password, QString : le mot de passe de l'utilisateur
 * Sortie :
 */
void MainWindow::actionConnection(QString id, QString password)
{
    unsigned int success = Controller::connection(id, password);

    switch (success)
    {
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
        MainWindow::messageDialog("Echec de la connexion, l'identifiant ou le mot de passe est incorrect \n Si vous n'avez pas de compte, veuillez contacter un administrateur.", "Information", MESSAGEBOX_OK);
        break;
    }
}

/**
 * Permet de la deconnexion de l'utilisateur
 * Entrée :
 * Sortie :
 */
void MainWindow::actionDeconnection()
{
    Controller::deconnection(); // On gere la deconnexion pour les donnees
    ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID); // On fait disparaitre le bouton deconnexion

    previousPages.clear(); // On réinitialise previousPages
}

void MainWindow::openConnection()
{

    /* Si aucun compte user n'existent, on est amené sur une page de création d'un compte user */
    if (Controller::isThereUsers() == SOME_USERS)
    {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    }
    else
    {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_FIRST_USER_REGISTRATION);
    }
}
/**
 * Permet de rediriger vers l'interface de gestion des utilisateurs
 * Entrée :
 * Sortie :
 */
void MainWindow::openUsers()
{
    ui->MainWidget->setCurrentIndex(MAINWIDGET_USER_MANAGEMENT); // Access à la page de gestion des utilisateurs
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    previousPages.push_front(MAINWIDGET_USER_MANAGEMENT); // On ajoute MAINWIDGET_USER_MANAGEMENT au chemin pour le retour
}

void MainWindow::openAccount()
{
    ui->MainWidget->setCurrentIndex(MAINWIDGET_MY_ACCOUNT);
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    previousPages.push_front(MAINWIDGET_MY_ACCOUNT); // On ajoute MAINWIDGET_USER_MANAGEMENT au chemin pour le retour

    AccountInformationsInterface *accountInformationsInterface = qobject_cast<AccountInformationsInterface *>(this->ui->MainWidget->widget(MAINWIDGET_MY_ACCOUNT));

    accountInformationsInterface->setAccountInformations();
}

void MainWindow::openMyProfiles()
{
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);

    Controller::openUserProfilesForCurrentUser();

    openProfiles();
}

/**
 * Permet d'ouvrir les profils d'un utilisateur
 * Entrée : user, User* : l'utilisateur pour lequel on veut ouvrir les profils
 * Sortie :
 */
void MainWindow::openProfiles(User *user)
{
    Controller::openUserProfiles(user);

    openProfiles();
}

/**
 * Permet de rediriger vers l'interface des profils
 * si l'utilisateur n'a pas de profils, on est redirigé vers l'interface de création de profils
 * Entrée :
 * Sortie :
 */
void MainWindow::openProfiles()
{
    ui->MainWidget->setCurrentIndex(MAINWIDGET_PROFILES); // Access à la page de gestion des profils
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VISIBLE);  // On l'affiche si ce n'est pas encore le cas

    if (Controller::hasProfiles() == NO_PROFILES)
    {
        openAddProfiles(); // Si l'utilisateur n'a pas encore de profils, on est emmené sur la page de création de profils
    }
    else
    {
        /* Si MAINWIDGET_PROFILES n'est pas déjà empilé */
        if (previousPages.front() != MAINWIDGET_PROFILES)
        {
            previousPages.push_front(MAINWIDGET_PROFILES); // On ajoute MAINWIDGET_PROFILES au chemin pour le retour
        }

        /* On initialise son élement combobox */
        QWidget *widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_PROFILES);
        qobject_cast<ProfilesInterface *>(widgetToRefresh)->initializeComboBox();
    }
}

/**
 * Permet de rediriger vers l'inteface de gestion des bases de données du profil
 * Entrée :
 * Sortie :
 */
void MainWindow::openDatabaseInterface(Profile* profile) {
    previousPages.push_front(MAINWIDGET_DATABASE_INTERFACE);
    Controller::setProfileDatabases(profile);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_DATABASE_INTERFACE); // Access à la page de gestion des bases de données du profil
    QWidget *widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_DATABASE_INTERFACE);
    qobject_cast<DatabaseInterface *>(widgetToRefresh)->initializeComboBox();
}
}

/**
 * Permet de rediriger vers l'inteface de gestion des tables  de la base de donnée
 * Entrée :
 * Sortie :
 */
void MainWindow::openDatabaseManagement(Profile* profile)
{
    previousPages.push_front(MAINWIDGET_DATABASE_MANAGEMENT);
    Controller::setProfileDatabases(profile);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_DATABASE_MANAGEMENT); // Access à la page de gestion des bases de données du profil
    QWidget *widgetToRefresh = ui->MainWidget->widget(MAINWIDGET_DATABASE_MANAGEMENT);
    qobject_cast<DatabaseManagementInterface *>(widgetToRefresh)->initializeComboBox();
}

/**
 * Permet de rediriger vers l'inteface de visualisation de la base de données
 * Entrée :
 * Sortie :
 */
void MainWindow::openDatabaseVisualisation()
{
    previousPages.push_front(MAINWIDGET_DATABASE_MANAGEMENT);
    ui->MainWidget->setCurrentIndex(MAINWIDGET_DATABASE_VISUALISATION); // Access à la page de visualisation de la base de données
}

/**
 * Permet de rediriger vers l'inteface de création d'utilisateur
 * Entrée :
 * Sortie :
 */
void MainWindow::openCreateUser()
{
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ACCOUNT_CREATION); // Access à la page de creation d'utilisateurs
    previousPages.push_front(MAINWIDGET_ACCOUNT_CREATION);        // On ajoute MAINWIDGET_ACCOUNT_CREATION au chemin pour le retour
}
/**
 * Permet de rediriger vers l'interface d'ajout de profil
 * Entrée :
 * Sortie :
 */
void MainWindow::openAddProfiles()
{
    ui->MainWidget->setCurrentIndex(MAINWIDGET_ADD_PROFILE); // Access à la page d'ajout de profils
    previousPages.push_front(MAINWIDGET_ADD_PROFILE);        // On ajoute MAINWIDGET_ADD_PROFILE au chemin pour le retour
}

/**
 * Permet de mettre à jour le tableau des utilisateurs
 * Entrée : user, User* : le nouvel utilisateur à ajouter
 * Sortie :
 */
void MainWindow::updateTableView(User *user)
{
    UserManagementInterface *userManagementInterface = qobject_cast<UserManagementInterface *>(this->ui->MainWidget->widget(MAINWIDGET_USER_MANAGEMENT));
    userManagementInterface->insertNewUser(user);
}

/**
 * Permet de gérer le retour sur la page précedente
 * Entrée :
 * Sortie :
 */
void MainWindow::returnOnPreviousView()
{
    previousPages.pop_front();                // On retire la reference vers la page actuelle
    int previousPage = previousPages.front(); // On stocke le numero de la nouvelle page

    ui->MainWidget->setCurrentIndex(previousPage); // On va sur la nouvelle page

    switch (previousPage)
    {
    case MAINWIDGET_USER_MANAGEMENT:
        Controller::closeUserProfiles();

        break;
    case MAINWIDGET_HOME_ADMIN:
    case MAINWIDGET_HOME_USER:
        ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);
        Controller::closeUserProfiles();

        break;
    case MAINWIDGET_DATABASE_INTERFACE:
        Controller::clearProfileDatabases();
        break;
    }
}
