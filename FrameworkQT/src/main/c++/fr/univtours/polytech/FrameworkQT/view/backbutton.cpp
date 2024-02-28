#include "backbutton.h"
#include "ui_backbutton.h"
#include "../utils/exception.h"
#include "mainwindow.h"

BackButton::BackButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackButton)
{
    ui->setupUi(this);
    // Connexion du bouton de retour à la méthode de retour
    connect(ui->backButton, &QPushButton::clicked, this, &BackButton::actionBack);
}

BackButton::~BackButton()
{
    delete ui;
}

/**
 * Méthode pour revenir en arrière
 * Entrée :
 * Sortie :
 */
void BackButton::actionBack()
{
    MainWindow *mainWindow = MainWindow::accessToParent(this);

    if (mainWindow != NULL) {
            mainWindow->returnOnPreviousView();
    }
}
