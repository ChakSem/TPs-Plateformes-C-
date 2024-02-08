#include <qstring>

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
private:
    static const int KEY_SIZE = 128;
    static const int IV_SIZE = 12; // GCM mode requires a 12-byte IV
    static const int TAG_SIZE = 128; // Size of authentication tag in bits
    static unsigned char* secretKey;

public:
    static QString encrypt(const QString& str);

    static QString decrypt(const QString& encryptedText) ;
};

#endif // ENCRYPTION_H
