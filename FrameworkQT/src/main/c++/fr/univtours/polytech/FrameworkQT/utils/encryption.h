#include <qstring>
#include <QSettings>

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {

public:
    static QString encrypt(const QString& str);
    static QString decrypt(const QString& encryptedText) ;

private :
    Encryption();
    Encryption(Encryption& encryption);
};

#endif // ENCRYPTION_H


