#include "view/mainwindow.h"
#include "model/User.h"
#include "model/Administrator.h"
#include "model/data.h"
#include "parseurJson/CparserJson.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    CparserJson::saveData(Data::getInstance());

    Controller::createUser("andre", "crochemore", "password", ADMIN);
    Controller::createUser("jhonny", "doe", "maison", USER);


    Data& data = Data::getInstance();

    data.addUser(new User("jhon", "doe"));
    data.addAdministrator(new User("patrick", "a"));

    return a.exec();
}
