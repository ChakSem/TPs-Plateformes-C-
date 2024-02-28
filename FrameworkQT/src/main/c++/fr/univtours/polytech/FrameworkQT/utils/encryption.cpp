#include "Qt-AES-master/qaesencryption.h"
#include <QByteArray>
#include <QString>
#include <QRandomGenerator>
#include "encryption.h"


/**
 * Methode qui permet de crypter une chaine de caractere
 * Entree : str, const QString&
 * Sortie : QString
 */
QString Encryption::encrypt(const QString& str) {
    QByteArray byteData = str.toUtf8();

    /* On encrypte la chaîne de caracteres */
    QByteArray encryptedData = QAESEncryption::Crypt(QAESEncryption::AES_128, QAESEncryption::ECB, byteData, "\xCEh\x19\xCCuB\xA9""8'\x9D\xDAL\xBC\xA4M2");

    /* On convertit en QString puis on renvoie */
    return QString::fromUtf8(encryptedData.toBase64());
}
/**
 * Methode qui permet de décrypter une chaine de caractere
 * Entree : encryptedText, const QString&
 * Sortie : QString
 */
QString Encryption::decrypt(const QString& encryptedText) {
    /* On passe en base 64 */
    QByteArray encryptedData = QByteArray::fromBase64(encryptedText.toUtf8());

    /* On decrypte la chaîne de caracteres */
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::ECB, encryptedData, "\xCEh\x19\xCCuB\xA9""8'\x9D\xDAL\xBC\xA4M2");

    /* On retire les caractères vides */
    decryptedData = QAESEncryption::RemovePadding(decryptedData);

    /* On convertit en QString puis on renvoie */
    return QString::fromUtf8(decryptedData);
}

Encryption::Encryption() {
}
