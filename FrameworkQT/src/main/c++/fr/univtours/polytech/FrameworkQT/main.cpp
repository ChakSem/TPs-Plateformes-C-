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

    Data& data = Data::getInstance();

    CparserJson::saveData(Data::getInstance());

    Controller::createUser("arthur", "crochemore", "password", ADMIN);
    Controller::createUser("jhon", "doe", "maison", USER);

    return a.exec();
}
