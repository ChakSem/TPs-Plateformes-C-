#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption
{
public:
    static std::string encrypt(std::string password);
    static std::string decrypt(std::string password);
    Encryption();
};

#endif // ENCRYPTION_H
