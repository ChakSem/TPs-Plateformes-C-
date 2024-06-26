#include "usermanagementinterface.h"
#include "ui_usermanagementinterface.h"
#include "QStandardItem"
#include "QMessageBox"
#include "../model/data.h"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "mainwindow.h"

/**
 * Permet d'initialiser l'objet TableView à partir des données de Data
 * Entrée :
 * Sortie :
 */
void UserManagementInterface::initializeTableView() {
    Data& data = Data::getInstance();
    QMap<QString, User*> users = data.getUsers();
    QMap<QString, User*> administrators = data.getAdministrators();

    model = new QStandardItemModel(users.size() + administrators.size(), 2, this);

    model->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom");

    row = 0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        insertNewUser(it.value());
    }

    for (auto it = administrators.begin(); it != administrators.end(); ++it) {
        insertNewUser(it.value());
    }

    // Configurer le QTableView pour utiliser le modèle de données
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

/**
 * Permet d'ajouter un utilisateur à la TableView
 * Entrée : user, User* : l'utilisateur à ajouter
 * Sortie :
 */
void UserManagementInterface::insertNewUser(User* user) {
    // Création des items pour chaque colonne
    QStandardItem *idItem = new QStandardItem(user->getId());
    QStandardItem *nameItem = new QStandardItem(user->getFirstname() +  " " + user->getLastname());

    // Ajout des items à la rangée
    model->setItem(row, 0, idItem);
    model->setItem(row, 1, nameItem);

    idItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    nameItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    ++row;
}


UserManagementInterface::UserManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserManagementInterface)
{
    ui->setupUi(this);

    initializeTableView();

    /* Connexion des boutons aux méthodes(Redirecction vers les informations du compte, les bases de données, les profils et les utilisateurs) */
    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &UserManagementInterface::actionAddUser);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &UserManagementInterface::actionDeleteUser);
    connect( ui->pushButtonProfiles, &QPushButton::clicked, this, &UserManagementInterface::actionUpdateUser);
}

UserManagementInterface::~UserManagementInterface()
{
    delete ui;
}

/**
 * Check qu'une ligne est selectionnée puis initialise row si c'est bon
 * Entrée :
 * Sortie : selectedRow, int : N° de la ligné sélectionnée ou NO_LINE_SELECTED si aucune ligne n'est selectionnée
 */
int UserManagementInterface::init() {
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    try {
        /* Si aucunes lignes n'est selectionnées */
        if(selectedRows.size() != 1) {
            throw new Exception(ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES);
        }
        
        int selectedRow = selectedRows.at(0).row();

        return selectedRow;
    }
    /* Sortie erreur */
    catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
        return NO_LINE_SELECTED;
    }
}

/**
 * Redirige vers la page de creation d'utilisateur
 * Entrée :
 * Sortie :
 */
void UserManagementInterface::actionAddUser() {
    MainWindow *mainWindow = MainWindow::accessToParent(this); // On récupère une réference sur MainWindow

    /* Si accessToParent() s'est bien passé */
    if (mainWindow != NULL) {
        mainWindow->openCreateUser();
    }
}

/**
 * Supprime l'utilisateur selectionné
 * Entrée :
 * Sortie :
 */
void UserManagementInterface::actionDeleteUser() {
    try {
        int selectedRow = init(); // Initialisation de selectedRow

        /* Si init() s'est bien passé */
        if (selectedRow > NO_LINE_SELECTED) {
            QString id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow, 0)).toString(); // On lit l'id de l'utilisateur selectionné
            if (id == SUPER_ADMIN) {
                throw new Exception(ERREUR_USER_MANAGEMENT_SUPPRESSION_SUPER_ADMIN);
            }
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Suppression de profil", "Etes-vous sûr de vouloir supprimer l'utilisateur " + id + " ?", QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No) {
                return;
            }

            Controller::deleteUser(id); // On le supprime

            /* Supprimer la ligne du modèle de données*/
            ui->tableView->model()->removeRow(selectedRow);

            row -= 1;
            
            /* Si l'utilisateur supprimé est l'utilisateur connecté */
            if(id == Controller::getUserConnected()->getId()) {
                MainWindow *mainWindow = MainWindow::accessToParent(this); // On récupère une réference sur MainWindow

                /* Si accessToParent() s'est bien passé */
                if (mainWindow != NULL) {
                    mainWindow->actionDeconnection();
                }
            }
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;
    }
}


/**
 * Ouvre l'interface de gestion des profils pour l'utilisateur selectionné
 * Entrée :
 * Sortie :
 */
void UserManagementInterface::actionUpdateUser() {
    int selectedRow = init(); // Initialisation de row

    /* Si init() s'est bien passé */
    if (selectedRow > NO_LINE_SELECTED) {
        MainWindow *mainWindow = MainWindow::accessToParent(this); // On récupère une réference sur MainWindow

        /* Si accessToParent() s'est bien passé */
        if (mainWindow != NULL) {
            QString id = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow, 0)).toString(); // On lit l'id de l'utilisateur selectionné

            User* userSelected = Controller::getUser(id);

            mainWindow->openProfiles(userSelected);
        }
    }
}


