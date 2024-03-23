#include "CparserJson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QString>

#include "../model/User.h"
#include "../model/Data.h"
#include "../utils/exception.h"
#include "../utils/encryption.h"

#define ERROR 0
#define SUCCESS 1

#define FILEPATHUSER "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/users.json"
#define FILEPATHADMIN "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/admins.json"
#define FILEPATHPASSWORDS "../FrameworkQT/src/main/c++/fr/univtours/polytech/FrameworkQT/data/passwords.json"

/**
 * Methode qui permet de lire les profils dans le fichier json d'un utilisateur
 * Entree : std::string id
 * Sortie : std::vector<Profile>
 */
int CparserJson::saveData(Data& data) {

    try {
        QFile fileUser(FILEPATHUSER);
        if (!fileUser.open(QIODevice::ReadOnly)) {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_USER);
        }

        QFile fileAdmin(FILEPATHADMIN);
        if (!fileAdmin.open(QIODevice::ReadOnly)) {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_SAUVEGARDE_ADMIN);
        }
        QJsonArray usersArray;// On crée un tableau JSON pour les utilisateurs
        for (User* user : data.getUsers()) {
            
            /*On crée un objet JSON pour les utilisateurs*/
            QJsonObject userObject;
            userObject["id"] = user->getId();
            userObject["firstname"] = user->getFirstname();
            userObject["lastname"] = user->getLastname();

            QJsonArray profilesArray;
            for (Profile* profile : user->getProfiles()) {

                QJsonObject profileObject;
                profileObject["title"] = profile->getTitle();
                /* On convertit l'enum Rights en string */
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
                    throw new Exception(ERREUR_DROIT_INCONNU);
                }
                profileObject["right"] = rightString;

                QJsonArray databasesArray;
                /* On parcourt la map et on écrit ses élements un à un */
                QMap<QString, QString> databases = profile->getDatabases();
                for (auto it = databases.begin(); it != databases.end(); ++it) {
                    const QString& databaseName = it.key();
                    const QString& databasePath = it.value();

                    QJsonObject databaseObject;

                    databaseObject["name"] = databaseName;
                    databaseObject["filePath"] = databasePath;

                    databasesArray.append(databaseObject);
                }
                profileObject["databases"] = databasesArray;

                profilesArray.append(profileObject);
            }
            userObject["profiles"] = profilesArray;

            usersArray.append(userObject);
        }

        fileUser.close();

        if (!fileUser.open(QIODevice::WriteOnly))
        {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json en écriture */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_USER);
        }

        /* Créer un objet .json pour les utilisateurs */
        QJsonDocument newDocUser(usersArray);
        fileUser.write(newDocUser.toJson());
        fileUser.close();

        /* Créer un objet .json pour l'utilisateur */
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
                /* On convertit l'enum Rights en string */
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
                    throw new Exception(ERREUR_DROIT_INCONNU);
                    return ERROR;
                }
                profileObject["right"] = rightString;

                QJsonArray databasesArray;
                /* On parcourt la map et on écrit ses élements un à un */
                QMap<QString, QString> databases = profile->getDatabases();
                for (auto it = databases.begin(); it != databases.end(); ++it) {
                    const QString& databaseName = it.key();
                    const QString& databasePath = it.value();

                    QJsonObject databaseObject;

                    databaseObject["name"] = databaseName;
                    databaseObject["filePath"] = databasePath;

                    databasesArray.append(databaseObject);
                }
                profileObject["databases"] = databasesArray;

                profilesArray.append(profileObject);
            }
            adminObject["profiles"] = profilesArray;
            adminsArray.append(adminObject);
        }

        fileAdmin.close();

        if (!fileAdmin.open(QIODevice::WriteOnly))
        {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json en écriture */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_ECRIRE_DANS_LA_SAUVEGARDE_ADMIN);
            return ERROR;
        }

        /* Écrit le nouveau document .json dans le fichier */
        QJsonDocument newDocAdmin(adminsArray);
        fileAdmin.write(newDocAdmin.toJson());
        fileAdmin.close();

        return SUCCESS;
    } catch (Exception* e) {
        e->EXCAffichageErreur();
        delete e;

        return ERROR;
    }
}

/**
 * Methode qui permet de sauvegarder un utilisateur dans le fichier json et son mot de passe dans le fichier json (on va le crypter avant de le sauvegarder)
 * Entree : User user, std::string password
 * Sortie : Rien
 */
int CparserJson::updateData(Data& data) {
    try {
        QFile fileUser(FILEPATHUSER);
        if (!fileUser.open(QIODevice::ReadOnly)) {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_USER);
        }

        QFile fileAdmin(FILEPATHADMIN);
        if (!fileAdmin.open(QIODevice::ReadOnly)) {
            /* Affiche un message d'erreur en cas d'échec d'ouverture du fichier .json */
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_CHARGER_ADMIN);
        }

        /* Lit le contenu du fichier .json */
        QByteArray byteArray = fileUser.readAll();
        QJsonDocument docUser(QJsonDocument::fromJson(byteArray));

        if (docUser.isArray()) {
            /* Si le document .json est un tableau */
            QJsonArray usersArray = docUser.array();

            for (const QJsonValue &userValue : usersArray) {
                /* Parcours chaque utilisateur dans le tableau .json */
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
                                throw new Exception(ERREUR_DROIT_INCONNU);
                            }
                        }
                    }

                    QJsonArray databasesArray = profileObject["databases"].toArray();
                    QMap<QString, QString> map;
                    /* On parcourt la map et on écrit ses élements un à un */
                    for (const QJsonValue &databaseValue : databasesArray) {
                        QJsonObject databaseObject = databaseValue.toObject();

                        map.insert(databaseObject["name"].toString(), databaseObject["filePath"].toString());
                    }

                    Profile* profile = new Profile(user, QString::fromStdString(profileObject["title"].toString().toStdString()), right, map);

                    user->addProfile(*profile);
                }

                data.addUser(user);
            }
        }

        fileUser.close();

        /* Lit le contenu du fichier JSON */
        byteArray = fileAdmin.readAll();
        QJsonDocument docAdmin(QJsonDocument::fromJson(byteArray));

        if (docAdmin.isArray()) {
            /* Si le document .json est un tableau */
            QJsonArray adminsArray = docAdmin.array();

            for (const QJsonValue &adminValue : adminsArray) {
                /* Parcours chaque utilisateur dans le tableau .json */
                QJsonObject adminObject = adminValue.toObject();
                User* admin = new User(QString::fromStdString(adminObject["id"].toString().toStdString()), QString::fromStdString(adminObject["firstname"].toString().toStdString())
                                                       , QString::fromStdString(adminObject["lastname"].toString().toStdString()));

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
                                throw new Exception(ERREUR_DROIT_INCONNU);
                            }
                        }
                    }

                    QJsonArray databasesArray = profileObject["databases"].toArray();
                    QMap<QString, QString> map;
                    /* On parcourt la map et on écrit ses élements un à un */
                    for (const QJsonValue &databaseValue : databasesArray) {
                        QJsonObject databaseObject = databaseValue.toObject();

                        map.insert(databaseObject["name"].toString(), databaseObject["filePath"].toString());
                    }

                    Profile* profile = new Profile(admin, QString::fromStdString(profileObject["title"].toString().toStdString()), right, map);

                    admin->addProfile(*profile);
                }

                data.addAdministrator(admin);
            }
        }
        fileAdmin.close();
        return SUCCESS;

    } catch (Exception* e) {
        e->EXCAffichageErreur();

        delete e;
        return ERROR;
    }
}

/**
 * Methode qui permet de crypter un mot de passe
 * Entree : std::string password
 * Sortie : std::string
 * Entrain : Retourne le mot de passe crypte
 */
void CparserJson::setPassword(QString id, QString password) {
    try {
        QFile file(FILEPATHPASSWORDS);
        if (!file.open(QIODevice::ReadWrite)) {
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_MOTS_DE_PASSE);
        }
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
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }

}

/**
 * Methode qui permet de decrypter un mot de passe
 * Entree : std::string password
 * Sortie : std::string
 */
QString CparserJson::getPassword(QString id) {
    try {
        /* On ouvre le fichier des mots de passe */
        QFile file(FILEPATHPASSWORDS);
        if (!file.open(QIODevice::ReadWrite)) {
            throw new Exception(ERREUR_OUVERTURE_FICHIER_POUR_MOTS_DE_PASSE);
        }
        /* On lit le contenu du fichier */
        QByteArray byteArray = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(byteArray); // On le convertit en document .json

        if (doc.isNull() || doc.isEmpty())
            doc = QJsonDocument::fromJson("{}"); // Si le document est vide, on le remplit avec un objet vide

        QJsonObject obj = doc.object();
        return Encryption::decrypt(QString::fromStdString(obj[id].toString().toStdString())); // On retourne le mot de passe decrypte
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();

        return NULL;
    }
}
