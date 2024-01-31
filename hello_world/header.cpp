#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    QPushButton button ("Hello world !");
    button.show();
    return app.exec();
}


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

#ifndef UTILISATEUR
#define UTILISATEUR 1

#endif