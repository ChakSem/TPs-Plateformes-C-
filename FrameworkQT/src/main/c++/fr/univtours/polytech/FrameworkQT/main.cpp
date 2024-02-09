#include "view/mainwindow.h"
#include "model/User.h"
#include "model/Administrator.h"
#include "model/data.h"
#include "parseurJson/CparserJson.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Data& data = Data::getInstance();
    data.addUser(*new User("arthur", "crochemore"));
    data.addAdministrator(*new Administrator("admin", "sudo"));

    for(User* user : data.getUsers()) {
        qDebug().nospace() << "user" << qPrintable(user->getId());
    }

    for(Administrator* administrator : data.getAdministrators()) {
        qDebug().nospace() << "administrator" << qPrintable(administrator->getId());
    }

    CparserJson::saveData(data);

    return a.exec();
}
