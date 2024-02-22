#include "usermanagementinterface.h"
#include "ui_usermanagementinterface.h"
#include "QStandardItem"
#include "QMessageBox"
#include "../model/data.h"
#include "../utils/exception.h"
#include "../controller/controller.h"
#include "mainwindow.h"

UserManagementInterface::UserManagementInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserManagementInterface)
{
    ui->setupUi(this);

    Data& data = Data::getInstance();
    QMap<QString, User*> users = data.getUsers();
    QMap<QString, User*> administrators = data.getAdministrators();

    QStandardItemModel *model = new QStandardItemModel(users.size() + administrators.size(), 2, this);

    model->setHorizontalHeaderLabels(QStringList() << "ID" << "Nom");

    int row = 0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        User* user = it.value();

        // Création des items pour chaque colonne
        QStandardItem *idItem = new QStandardItem(user->getId());
        QStandardItem *nameItem = new QStandardItem(user->getFirstname() +  " " + user->getLastname());

        // Ajout des items à la rangée
        model->setItem(row, 0, idItem);
        model->setItem(row, 1, nameItem);

        ++row;
    }

    for (auto it = administrators.begin(); it != administrators.end(); ++it) {
        User* admin = it.value();

        // Création des items pour chaque colonne
        QStandardItem *idItem = new QStandardItem(admin->getId());
        QStandardItem *nameItem = new QStandardItem(admin->getFirstname() +  " " + admin->getLastname());

        // Ajout des items à la rangée
        model->setItem(row, 0, idItem);
        model->setItem(row, 1, nameItem);

        ++row;
    }

    // Configurer le QTableView pour utiliser le modèle de données
    ui->tableView->setModel(model);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    connect( ui->pushButtonAdd, &QPushButton::clicked, this, &UserManagementInterface::actionAddUser);
    connect( ui->pushButtonDelete, &QPushButton::clicked, this, &UserManagementInterface::actionDeleteUser);
    connect( ui->pushButtonUpdate, &QPushButton::clicked, this, &UserManagementInterface::actionUpdateUser);
}

UserManagementInterface::~UserManagementInterface()
{
    delete ui;
}

int UserManagementInterface::init() {
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if(selectedRows.size() != 1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une seule ligne à supprimer.");
        return NO_LINE_SELECTED;
    }

    int row = selectedRows.at(0).row();

    return row;
}

void UserManagementInterface::actionAddUser() {
    try {
        int row = init();
        if (row == NO_LINE_SELECTED) {
            throw new Exception(ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES);
        }

        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {

            QString id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
            mainWindow->openProfiles(Controller::getUser(id));
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void UserManagementInterface::actionDeleteUser() {
    try {
        int row = init();
        if (row == NO_LINE_SELECTED) {
            throw new Exception(ERREUR_USER_MANAGEMENT_AUCUNES_LIGNES_SELECTIONNEES);
        }

        QString id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
        qDebug() << "ID sélectionné à supprimer :" << id;

        Controller::deleteUser(id);

        // Supprimer la ligne du modèle de données
        ui->tableView->model()->removeRow(row);
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}

void UserManagementInterface::actionUpdateUser() {

}


