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

        QJsonArray profilesArray;
        for (Profile* profile : user->getProfiles()) {
            QJsonObject profileObject;
            profileObject["title"] = profile->getTitle();
            // Convert Rights enum to string
            QString rightString;
            switch (profile->getRight()) {
            case Rights::LECTURE:
                rightString = "LECTURE";
                break;
            case Rights::LECTURE_MODIFICATION:
                rightString = "LECTURE_MODIFICATION";
                break;
            case Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION:
                rightString = "LECTURE_MODIFICATION_ECRITURE_SUPPRESSION";
                break;
            default:
                qDebug() << "ERREUR_DROIT_INCONNU";
                return ERROR;
            }
            profileObject["right"] = rightString;
            profilesArray.append(profileObject);
        }
        userObject["profiles"] = profilesArray;

        // TODO : Gérer les bases de données

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
        QJsonObject adminObject;
        adminObject["id"] = administrator->getId();
        adminObject["firstname"] = administrator->getFirstname();
        adminObject["surname"] = administrator->getLastname();

        QJsonArray profilesArray;
        for (Profile* profile : administrator->getProfiles()) {
            QJsonObject profileObject;
            profileObject["title"] = profile->getTitle();
            // Convert Rights enum to string
            QString rightString;
            switch (profile->getRight()) {
            case Rights::LECTURE:
                rightString = "LECTURE";
                break;
            case Rights::LECTURE_MODIFICATION:
                rightString = "LECTURE_MODIFICATION";
                break;
            case Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION:
                rightString = "LECTURE_MODIFICATION_ECRITURE_SUPPRESSION";
                break;
            default:
                qDebug() << "ERREUR_DROIT_INCONNU";
                return ERROR;
            }
            profileObject["right"] = rightString;
            profilesArray.append(profileObject);
        }
        adminObject["profiles"] = profilesArray;

        // TODO : Gérer les bases de données

        adminsArray.append(adminObject);
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

            QJsonArray profilesArray = userObject["profiles"].toArray();
            for (const QJsonValue &profileValue : profilesArray) {
                QJsonObject profileObject = profileValue.toObject();

                Rights right;
                if(profileObject["right"].toString().toStdString() == "LECTURE") {
                    right = Rights::LECTURE;
                } else {
                    if(profileObject["right"].toString().toStdString() == "LECTURE_MODIFICATION") {
                        right = Rights::LECTURE;
                    } else {
                        if(profileObject["right"].toString().toStdString() == "LECTURE_MODIFICATION_ECRITURE_SUPPRESSION") {
                            right = Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION;
                        } else {
                            qDebug() << "ERREUR_DROIT_INCONNU";
                            return ERROR;
                        }
                    }
                }

                Profile* profile = new Profile(user, QString::fromStdString(userObject["title"].toString().toStdString()), right);
                // TODO : Gérer les bases de données

                user->addProfile(*profile);
            }

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

        for (const QJsonValue &adminValue : adminsArray)
        {
            // Parcours chaque utilisateur dans le tableau JSON
            QJsonObject adminObject = adminValue.toObject();
            Administrator* admin = new Administrator(QString::fromStdString(adminObject["id"].toString().toStdString()), QString::fromStdString(adminObject["firstname"].toString().toStdString())
                                                   , QString::fromStdString(adminObject["firstname"].toString().toStdString()));

            QJsonArray profilesArray = adminObject["profiles"].toArray();
            for (const QJsonValue &profileValue : profilesArray) {
                QJsonObject profileObject = profileValue.toObject();

                Rights right;
                if(profileObject["right"].toString().toStdString() == "LECTURE") {
                    right = Rights::LECTURE;
                } else {
                    if(profileObject["right"].toString().toStdString() == "LECTURE_MODIFICATION") {
                        right = Rights::LECTURE;
                    } else {
                        if(profileObject["right"].toString().toStdString() == "LECTURE_MODIFICATION_ECRITURE_SUPPRESSION") {
                            right = Rights::LECTURE_MODIFICATION_ECRITURE_SUPPRESSION;
                        } else {
                            qDebug() << "ERREUR_DROIT_INCONNU";
                            return ERROR;
                        }
                    }
                }

                Profile* profile = new Profile(admin, QString::fromStdString(adminObject["title"].toString().toStdString()), right);
                // TODO : Gérer les bases de données

                admin->addProfile(*profile);
            }

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
