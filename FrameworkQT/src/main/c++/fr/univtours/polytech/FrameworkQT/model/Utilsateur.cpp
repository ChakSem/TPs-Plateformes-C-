#include "Utilisateur.h"

unsigned long int Utilisateur::getId() {
    return id;
}
void Utilisateur::setId(unsigned long int newId) {
    id = newId;
}

std::string Utilisateur::getLastname() {
    return lastname;
}

void Utilisateur::setLastname(std::string newLastname) {
    lastname = newLastname;
}

std::string Utilisateur::getFirstname() {
    return firstname;
}

void Utilisateur::setFirstname(std::string newFirstname) {
    firstname = newFirstname;
}
