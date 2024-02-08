#include "User.h"
#include "Profile.h"

QString User::getId() {
    return id;
}

QString User::getLastname() {
    return lastname;
}

void User::setLastname(const QString& newLastname) {
    lastname = newLastname;
}

QString User::getFirstname() {
    return firstname;
}

void User::setFirstname(const QString& newFirstname) {
    firstname = newFirstname;
}

void User::addProfile(const Profile& profile) {
    profiles.push_back(new Profile(profile));
}

void User::deleteProfile(const QString title) {
    for(QList<Profile*>::iterator iter = profiles.begin(); iter != profiles.end(); ++iter) {
        if(title == (*iter)->getTitle()) {
            delete *iter;
            profiles.erase(iter);
            break;
        }
    }
}

User::User() {}
User::User(User& user){}

User::User(const QString& newLastname, const QString& newFirstname) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;
}

User::User(const QString& newLastname, const QString& newFirstname, const QList<Profile*>& newProfiles) {
    id = uuid::generate_uuid_v4();
    lastname = newLastname;
    firstname = newFirstname;

    /* On copie et ajoute les profils un à un */
    for(Profile* newProfile : newProfiles) {
        addProfile(*newProfile);
    }
}
