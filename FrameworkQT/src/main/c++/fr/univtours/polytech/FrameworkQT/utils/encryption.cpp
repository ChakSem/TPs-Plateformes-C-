#include "Qt-AES-master/qaesencryption.h"
#include <QByteArray>
#include <QString>
#include <QRandomGenerator>
#include "encryption.h"

QString Encryption::encrypt(const QString& str) {
    QByteArray byteData = str.toUtf8();

    // Encrypt data
    QByteArray encryptedData = QAESEncryption::Crypt(QAESEncryption::AES_128, QAESEncryption::ECB, byteData, "\xCEh\x19\xCCuB\xA9""8'\x9D\xDAL\xBC\xA4M2");

    // Convert encrypted data back to QString
    return QString::fromUtf8(encryptedData.toBase64());
}

QString Encryption::decrypt(const QString& encryptedText) {
    // Decode Base64
    QByteArray encryptedData = QByteArray::fromBase64(encryptedText.toUtf8());

    // Decrypt data
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::ECB, encryptedData, "\xCEh\x19\xCCuB\xA9""8'\x9D\xDAL\xBC\xA4M2");

    decryptedData = QAESEncryption::RemovePadding(decryptedData);

    // Convert decrypted data back to QString
    return QString::fromUtf8(decryptedData);
}

Encryption::Encryption() {
}
