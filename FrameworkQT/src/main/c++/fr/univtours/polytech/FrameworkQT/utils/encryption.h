#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
private:
    static const int KEY_SIZE = 128;
    static const int IV_SIZE = 12; // GCM mode requires a 12-byte IV
    static const int TAG_SIZE = 128; // Size of authentication tag in bits
    static EVP_CIPHER_CTX *ctx;
    static unsigned char* secretKey;

public:
    static void handleErrors() ;

    static std::string base64_encode(const unsigned char* input, int length);

    static std::string encrypt(const std::string& str);

    static std::string decrypt(const std::string& encryptedText) ;
};

#endif // ENCRYPTION_H
