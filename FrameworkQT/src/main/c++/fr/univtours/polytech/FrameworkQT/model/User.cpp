#include "User.h"
#include "Profile.h"

std::string User::getId() {
    return id;
}

void User::setId(std::string newId) {
    id = newId;
}

std::string User::getLastname() {
    return lastname;
}

void User::setLastname(std::string newLastname) {
    lastname = newLastname;
}

std::string User::getFirstname() {
    return firstname;
}

void User::setFirstname(std::string newFirstname) {
    firstname = newFirstname;
}

User::User() {
    id = uuid::generate_uuid_v4();
    lastname = std::string("");
    firstname = std::string("");
    profiles = std::list<Profile>();//std::make_unique<std::list<Profile>>();
}

