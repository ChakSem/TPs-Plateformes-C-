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

    Controller::deleteUser("5f20da2e-e39b-48db-bdd6-576ea3a602fc");
    Controller::deleteUser("b720beff-8d98-4030-b272-d1ba9c1de19c");

    return a.exec();
}
