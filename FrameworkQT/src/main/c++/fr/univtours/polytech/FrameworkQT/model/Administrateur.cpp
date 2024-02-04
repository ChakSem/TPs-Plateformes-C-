#include "Administrateur.h"

unsigned long int Administrateur::getId() {
    return id;
}
void Administrateur::setId(unsigned long int newId) {
    id = newId;
}

std::string Administrateur::getLastname() {
    return lastname;
}

void Administrateur::setLastname(std::string newLastname) {
    lastname = newLastname;
}

std::string Administrateur::getFirstname() {
    return firstname;
}

void Administrateur::setFirstname(std::string newFirstname) {
    firstname = newFirstname;
}
