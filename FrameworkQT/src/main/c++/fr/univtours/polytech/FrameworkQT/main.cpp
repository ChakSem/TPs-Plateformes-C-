#include "view/mainwindow.h"
#include "view/mainconnection.h"
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

    CparserJson::saveData(Data::getInstance());

    return a.exec();
}
