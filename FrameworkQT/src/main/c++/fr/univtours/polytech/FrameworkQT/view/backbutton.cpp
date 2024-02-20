#include "backbutton.h"
#include "ui_backbutton.h"
#include "../utils/exception.h"
#include "mainwindow.h"

BackButton::BackButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BackButton)
{
    ui->setupUi(this);
    connect(ui->backButton, &QPushButton::clicked, this, &BackButton::actionBack);
}

BackButton::~BackButton()
{
    delete ui;
}

void BackButton::actionBack()
{
    try {
        QWidget *parentWidget = this->parentWidget()->parentWidget()->parentWidget();
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget);
        if (mainWindow) {
            mainWindow->returnOnPreviousView();
        } else {
            throw new Exception(ERREUR_MAINWINDOW_NON_TROUVE);
        }
    }
    catch (Exception* e) {
        e->EXCAffichageErreur();
    }
}
