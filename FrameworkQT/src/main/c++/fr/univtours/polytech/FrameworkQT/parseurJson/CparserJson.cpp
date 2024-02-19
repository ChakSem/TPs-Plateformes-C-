#include "CparserJson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

#include "../model/User.h"
#include "../model/Data.h"
#include "../utils/exception.h"
#include "../utils/encryption.h"

#define ERROR 0
#define SUCCESS 1

#define FILEPATHUSER "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/users.json"
#define FILEPATHADMIN "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/admins.json"
#define FILEPATHPASSWORDS "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/passwords.json"

int CparserJson::saveData(Data& data) {

    try {
        QFile fileUser(FILEPATHUSER);
        if (!fileUser.open(QIODevice::ReadOnly))
        {
            // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER);
        }

        QFile fileAdmin(FILEPATHADMIN);
        if (!fileAdmin.open(QIODevice::ReadOnly))
        {
            // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN);
        }

        // Créer un objet JSON pour l'utilisateur
        QJsonArray usersArray;
        for (User* user : data.getUsers()) {
            QJsonObject userObject;
            userObject["id"] = user->getId();
            userObject["firstname"] = user->getFirstname();
            userObject["lastname"] = user->getLastname();

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
                // TODO : Gérer les bases de données

                profilesArray.append(profileObject);
            }
            userObject["profiles"] = profilesArray;

            usersArray.append(userObject);
        }

        fileUser.close();

        if (!fileUser.open(QIODevice::WriteOnly))
        {
            // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON en écriture
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER);
        }

        // Écrit le nouveau document JSON dans le fichier
        QJsonDocument newDocUser(usersArray);
        fileUser.write(newDocUser.toJson());
        fileUser.close();

        // Créer un objet JSON pour l'utilisateur
        QJsonArray adminsArray;
        for (User* administrator : data.getAdministrators()) {
            QJsonObject adminObject;
            adminObject["id"] = administrator->getId();
            adminObject["firstname"] = administrator->getFirstname();
            adminObject["lastname"] = administrator->getLastname();

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
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN);
            return ERROR;
        }

        // Écrit le nouveau document JSON dans le fichier
        QJsonDocument newDocAdmin(adminsArray);
        fileAdmin.write(newDocAdmin.toJson());
        fileAdmin.close();

        return SUCCESS;
    } catch (Exception* e) {
        e->EXCAffichageErreur();
        return ERROR;
    }
}

int CparserJson::updateData(Data& data) {
    try {
        QFile fileUser(FILEPATHUSER);
        if (!fileUser.open(QIODevice::ReadOnly))
        {
            // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER);
        }

        QFile fileAdmin(FILEPATHADMIN);
        if (!fileAdmin.open(QIODevice::ReadOnly))
        {
            // Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN);
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
                                      , QString::fromStdString(userObject["lastname"].toString().toStdString()));

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

                data.addUser(user);
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
                User* admin = new User(QString::fromStdString(adminObject["id"].toString().toStdString()), QString::fromStdString(adminObject["firstname"].toString().toStdString())
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

                data.addAdministrator(admin);
            }
        }

        fileAdmin.close();

        return SUCCESS;

    } catch (Exception* e) {
        e->EXCAffichageErreur();
        return ERROR;
    }
}

void CparserJson::setPassword(QString id, QString password)
{
    QFile file(FILEPATHPASSWORDS);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Erreur lors de l'ouverture du fichier";
    } else {
        QByteArray byteArray = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(byteArray);

        if (doc.isNull() || doc.isEmpty())
            doc = QJsonDocument::fromJson("{}");

        QJsonObject obj = doc.object();
        obj[id] = Encryption::encrypt(password);

        file.resize(0);
        file.write(QJsonDocument(obj).toJson());
        file.close();
    }
}


QString CparserJson::getPassword(QString id)
{
    QFile file(FILEPATHPASSWORDS);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Erreur lors de l'ouverture du fichier";
        return NULL;
    }

    QByteArray byteArray = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(byteArray);

    if (doc.isNull() || doc.isEmpty())
        doc = QJsonDocument::fromJson("{}");

    QJsonObject obj = doc.object();
    return Encryption::decrypt(QString::fromStdString(obj[id].toString().toStdString()));

}
