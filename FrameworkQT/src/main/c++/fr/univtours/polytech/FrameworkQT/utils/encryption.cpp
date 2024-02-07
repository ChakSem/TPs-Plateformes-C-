#include "encryption.h"

static void Encryption::handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

static std::string Encryption::base64_encode(const unsigned char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, input, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    std::string result(bufferPtr->data, bufferPtr->length);
    BIO_free_all(bio);
    return result;
}

static std::string Encryption::encrypt(const std::string& str) {
    unsigned char iv[IV_SIZE];
    if (!RAND_bytes(iv, IV_SIZE))
        handleErrors();

    unsigned char* encrypted = new unsigned char[str.size() + AES_BLOCK_SIZE];

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_128_gcm(), NULL, secretKey, iv))
        handleErrors();

    int len;
    if (!EVP_EncryptUpdate(ctx, encrypted, &len, reinterpret_cast<const unsigned char*>(str.c_str()), str.size()))
        handleErrors();

    int ciphertext_len = len;

    if (!EVP_EncryptFinal_ex(ctx, encrypted + len, &len))
        handleErrors();

    ciphertext_len += len;

    std::string result(reinterpret_cast<char*>(iv), IV_SIZE);
    result += std::string(reinterpret_cast<char*>(encrypted), ciphertext_len);
    delete[] encrypted;
    return base64_encode(reinterpret_cast<const unsigned char*>(result.c_str()), result.size());
}

static std::string Encryption::decrypt(const std::string& encryptedText) {
    unsigned char* encrypted = new unsigned char[encryptedText.size()];
    int decoded_length = EVP_DecodeBlock(encrypted, reinterpret_cast<const unsigned char*>(encryptedText.c_str()), encryptedText.size());
    if (decoded_length < 0)
        handleErrors();

    unsigned char iv[IV_SIZE];
    std::memcpy(iv, encrypted, IV_SIZE);

    int ciphertext_len = decoded_length - IV_SIZE;
    unsigned char* ciphertext = encrypted + IV_SIZE;

    unsigned char* decrypted = new unsigned char[ciphertext_len + AES_BLOCK_SIZE];

    if (!EVP_DecryptInit_ex(ctx, EVP_aes_128_gcm(), NULL, secretKey, iv))
        handleErrors();

    int len;
    if (!EVP_DecryptUpdate(ctx, decrypted, &len, ciphertext, ciphertext_len))
        handleErrors();

    int plaintext_len = len;

    if (!EVP_DecryptFinal_ex(ctx, decrypted + len, &len))
        handleErrors();

    plaintext_len += len;
    std::string result(reinterpret_cast<char*>(decrypted), plaintext_len);
    delete[] encrypted;
    delete[] decrypted;
    return result;
}
