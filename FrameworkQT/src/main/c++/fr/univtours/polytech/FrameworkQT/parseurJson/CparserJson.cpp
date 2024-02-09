#include "CparserJson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

#include "../model/User.h"
#include "../model/Administrator.h"
#include "../model/Data.h"

#define ERROR 1
#define SUCCESS 0

#define FILEPATHUSER "../data/users.json"
#define FILEPATHADMIN "../data/admins.json"

int CparserJson::saveData(Data& data) {

    QFile fileUser(FILEPATHUSER);
    if (!fileUser.open(QIODevice::ReadOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    QFile fileAdmin(FILEPATHADMIN);
    if (!fileAdmin.open(QIODevice::ReadOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    // Lit le contenu du fichier JSON
    QByteArray byteArray = fileUser.readAll();
    QJsonDocument docUser(QJsonDocument::fromJson(byteArray));

    if (!docUser.isArray())
    {
        // Affiche un message d'erreur si le document JSON n'est pas un tableau
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        fileUser.close();
        return ERROR;
    }

    // Créer un objet JSON pour l'utilisateur
    QJsonArray usersArray = docUser.array();
    for (User* user : data.getUsers()) {
        QJsonObject userObject;
        userObject["id"] = user->getId();
        userObject["firstname"] = user->getFirstname();
        userObject["surname"] = user->getLastname();

        usersArray.append(userObject);
    }

    fileUser.close();

    if (!fileUser.open(QIODevice::WriteOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON en écriture
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    // Écrit le nouveau document JSON dans le fichier
    QJsonDocument newDocUser(usersArray);
    fileUser.write(newDocUser.toJson());
    fileUser.close();

    // Lit le contenu du fichier JSON
    byteArray = fileAdmin.readAll();
    QJsonDocument docAdmin(QJsonDocument::fromJson(byteArray));

    if (!docAdmin.isArray())
    {
        // Affiche un message d'erreur si le document JSON n'est pas un tableau
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        fileUser.close();
        return ERROR;
    }

    // Créer un objet JSON pour l'utilisateur
    QJsonArray adminsArray = docAdmin.array();
    for (Administrator* administrator : data.getAdministrators()) {
        QJsonObject userObject;
        userObject["id"] = administrator->getId();
        userObject["firstname"] = administrator->getFirstname();
        userObject["surname"] = administrator->getLastname();

        usersArray.append(adminsArray);
    }

    fileAdmin.close();

    if (!fileAdmin.open(QIODevice::WriteOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON en écriture
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    // Écrit le nouveau document JSON dans le fichier
    QJsonDocument newDocAdmin(adminsArray);
    fileAdmin.write(newDocAdmin.toJson());
    fileAdmin.close();

    return SUCCESS;
}

int CparserJson::updateData(Data& data) {

    QFile fileUser(FILEPATHUSER);
    if (!fileUser.open(QIODevice::ReadOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    QFile fileAdmin(FILEPATHADMIN);
    if (!fileAdmin.open(QIODevice::ReadOnly))
    {
        // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
        qDebug() << "ERREUR_OUVERTURE_FICHIER_JSON";
        return ERROR;
    }

    // Lit le contenu du fichier JSON
    QByteArray byteArray = fileUser.readAll();
    QJsonDocument docUser(QJsonDocument::fromJson(byteArray));

    if (docUser.isArray())
    {
        // Si le document JSON est un tableau
        QJsonArray usersArray = docUser.array();

        for (const QJsonValue &userValue : usersArray)
        {
            // Parcours chaque utilisateur dans le tableau JSON
            QJsonObject userObject = userValue.toObject();
            User* user = new User(QString::fromStdString(userObject["id"].toString().toStdString()), QString::fromStdString(userObject["firstname"].toString().toStdString())
                                  , QString::fromStdString(userObject["firstname"].toString().toStdString()));

            data.addUser(*user);
        }
    }

    fileUser.close();

    // Lit le contenu du fichier JSON
    byteArray = fileAdmin.readAll();
    QJsonDocument docAdmin(QJsonDocument::fromJson(byteArray));

    if (docAdmin.isArray())
    {
        // Si le document JSON est un tableau
        QJsonArray adminsArray = docAdmin.array();

        for (const QJsonValue &userValue : adminsArray)
        {
            // Parcours chaque utilisateur dans le tableau JSON
            QJsonObject userObject = userValue.toObject();
            Administrator* admin = new Administrator(QString::fromStdString(userObject["id"].toString().toStdString()), QString::fromStdString(userObject["firstname"].toString().toStdString())
                                                   , QString::fromStdString(userObject["firstname"].toString().toStdString()));


            data.addAdministrator(*admin);
        }
    }

    fileAdmin.close();

    return SUCCESS;
}

void CparserJson::setPassword(User* user, QString password)
{
	// TODO : Ecrire dans password.json "user.id : Encryption.encrtypt(password)"" 
}


QString CparserJson::getPassword(User* user)
{
	// TODO:  Implémenter la logique de décryptage du mot de passe
    return "password";
}
