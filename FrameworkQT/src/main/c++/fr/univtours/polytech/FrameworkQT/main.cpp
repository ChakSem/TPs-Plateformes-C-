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

    return a.exec();
}
