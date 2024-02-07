#include "CparseurJson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

CparseurJson::CparseurJson(std::string filepath) : filePath(QString::fromStdString(filepath))
{
}

std::vector<User> CparseurJson::readUsers()
{
	std::vector<User> users;

	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		// Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return users;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (doc.isArray())
	{
		// Si le document JSON est un tableau
		QJsonArray usersArray = doc.array();

		for (const QJsonValue &userValue : usersArray)
		{
			// Parcours chaque utilisateur dans le tableau JSON
			QJsonObject userObject = userValue.toObject();
			User user;

			// Extrait les données de l'utilisateur depuis le fichier JSON
			user.setId(userObject["id"].toString().toStdString());
			user.setFirstname(userObject["name"].toString().toStdString());

			user.push_back(user);
		}
	}

	file.close();
	return users;
}

void CparseurJson::addUser(User user, std::string password)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (!doc.isArray())
	{
		// Affiche un message d'erreur si le document JSON n'est pas un tableau
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		file.close();
		return;
	}

	// Créer un objet JSON pour l'utilisateur
	QJsonObject userObject;
	userObject["id"] = QString::fromStdString(user.getId());
	userObject["name"] = QString::fromStdString(user.getFirstname());
	userObject["password"] = QString::fromStdString(cryptPassword(password));

	QJsonArray usersArray = doc.array();
	usersArray.append(userObject);

	file.close();

	if (!file.open(QIODevice::WriteOnly))
	{
		// Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON en écriture
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}

	// Écrit le nouveau document JSON dans le fichier
	QJsonDocument newDoc(usersArray);
	file.write(newDoc.toJson());
	file.close();
}

void CparseurJson::removeUser(User user)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (!doc.isArray())
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		file.close();
		return;
	}

	QJsonArray usersArray = doc.array();
	for (int i = 0; i < usersArray.size(); ++i)
	{
		QJsonObject userObject = usersArray[i].toObject();
		if (userObject["id"].toString().toStdString() == user.getId())
		{
			usersArray.removeAt(i);
			break;
		}
	}

	file.close();

	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}
	QJsonDocument newDoc(usersArray);
	file.write(newDoc.toJson());
	file.close();
}

void CparseurJson::updateNameUser(std::string id, std::string newName)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (!doc.isArray())
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		file.close();
		return;
	}

	QJsonArray usersArray = doc.array();
	for (int i = 0; i < usersArray.size(); ++i)
	{
		QJsonObject userObject = usersArray[i].toObject();
		if (userObject["id"].toString().toStdString() == id)
		{
			// Met à jour le nom de l'utilisateur dans le tableau JSON
			userObject["name"] = QString::fromStdString(newName);
			usersArray.replace(i, userObject);
			break;
		}
	}
	file.close();

	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return;
	}

	// Écrit le nouveau document JSON dans le fichier
	QJsonDocument newDoc(usersArray);
	file.write(newDoc.toJson());
	file.close();
}

bool CparseurJson::isIDUserExist(std::string id)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return false;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (!doc.isArray())
	{
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		file.close();
		return false;
	}

	QJsonArray usersArray = doc.array();
	for (const QJsonValue &userValue : usersArray)
	{
		QJsonObject userObject = userValue.toObject();
		if (userObject["id"].toString().toStdString() == id)
		{
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}

void CparseurJson::setPassword(User* user, std::string password)
{
	// TODO : Ecrire dans password.json "user.id : Encryption.encrtypt(password)"" 
}


std::string CparseurJson::getPassword(User* user)
{
	// TODO:  Implémenter la logique de décryptage du mot de passe
	return password;
}


/*
 * Methode qui permet de lire les profils dans le fichier json
 *Entree : Rien
 *Necessite : Rien
 *Sortie : std::vector<Profile>
 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json
 */
std::vector<Profile> readProfils()
{
	std::vector<Profile> profils;
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		// Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return profils;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (doc.isArray())
	{
		// Si le document JSON est un tableau
		QJsonArray profilsArray = doc.array();

		for (const QJsonValue &profilValue : profilsArray)
		{
			// Parcours chaque profil dans le tableau JSON
			QJsonObject profilObject = profilValue.toObject();
			Profile profil;

			// Extrait les données du profil depuis le fichier JSON
			QJsonObject profilData = profilObject["profil"].toObject();
			std::map<std::string, std::string> profilMap;
			for (auto it = profilData.begin(); it != profilData.end(); ++it)
			{
				profilMap[it.key().toStdString()] = it.value().toString().toStdString();
			}
			profil.setProfil(profilMap);

			profils.push_back(profil);
		}
	}

	file.close();
	return profils;
}

/*
 * Methode qui permet de lire les profils dans le fichier json d'un utilisateur
 *Entree : std::string id
 *Necessite : Rien
 *Sortie : std::vector<Profile>
 *Entrain : Retourne un vecteur de profils qui contient tous les profils dans le fichier json d'un utilisateur
 */
std::vector<Profile> readProfilsUser(std::string id);
{
	std::vector<Profile> profils;
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
	{
		// Affiche un message d'erreur en cas d'échec d'ouverture du fichier JSON
		qDebug() << ERREUR_OUVERTURE_FICHIER_JSON;
		return profils;
	}

	// Lit le contenu du fichier JSON
	QByteArray data = file.readAll();
	QJsonDocument doc(QJsonDocument::fromJson(data));

	if (doc.isArray())
	{
		QJsonArray usersArray = doc.array();

		for (const QJsonValue &userValue : usersArray)
		{
			// Parcours chaque utilisateur dans le tableau JSON
			QJsonObject userObject = userValue.toObject();
			if (userObject["id"].toString().toStdString() == id)
			{
				// Extrait les profils de l'utilisateur depuis le fichier JSON
				QJsonArray profilsArray = userObject["profils"].toArray();
				for (const QJsonValue &profilValue : profilsArray)
				{
					QJsonObject profilObject = profilValue.toObject();
					Profile profil;

					// Extrait les données du profil depuis le fichier JSON
					QJsonObject profilData = profilObject["profil"].toObject();
					std::map<std::string, std::string> profilMap;
					for (auto it = profilData.begin(); it != profilData.end(); ++it)
					{
						profilMap[it.key().toStdString()] = it.value().toString().toStdString();
					}
					profil.setProfil(profilMap);

					profils.push_back(profil);
				}
				break;
			}
		}
	}

	file.close();
	return profils;
}
