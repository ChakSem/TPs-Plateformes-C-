#include "view/mainwindow.h"
#include "model/User.h"
#include "model/data.h"
#include "parseurJson/CparserJson.h"
#include "controller/controller.h"
#include "utils/encryption.h"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString passwordEnc = Encryption::encrypt("123Soleil");

    qDebug() << passwordEnc << " - " << Encryption::decrypt(passwordEnc);

    passwordEnc = Encryption::encrypt("super_password");

    qDebug() << passwordEnc << " - " << Encryption::decrypt("L+CESy3uGzIABgPUFWVNOw==");
    return a.exec();
}
