#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../controller/controller.h"
#include "../utils/exception.h"
#include <QLabel>
#include <QMessageBox>


/**
 * Constructeur de la classe MainWindow
 * Entrée :
 * Sortie :
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (Controller::isThereUsers() == SOME_USERS)
    {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_CONNECTION);
    }
    else
    {
        ui->MainWidget->setCurrentIndex(MAINWIDGET_FIRST_USER_REGISTRATION);
    }

    openConnection();

    ui->DeconnectionWidget->setCurrentIndex(DECONNECTIONWIDGET_VOID);
    ui->BackWidget->setCurrentIndex(BACKWIDGET_VOID);

    qDebug() << "Stacked Widget Deconnection initialized with current index:" << ui->DeconnectionWidget->currentIndex();
}

MainWindow::~MainWindow()
{
    delete ui;
}
