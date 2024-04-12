#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Bouton_OuvertureExplorateurDossiers //    connect(ui->pushButtonDeconnection, &QPushButton::clicked, this, &DeconnectionInterface::actionDeconnection);  
    connect(ui->Bouton_OuvertureExplorateurFichier, &QPushButton::clicked, this, &MainWindow::actionOuvertureExplorateurFichier);
        
}

MainWindow::~MainWindow()
{
    //
    delete ui;
}

//Methode douverture de la fenetre de dialogue
void MainWindow::actionOuvertureExplorateurFichier()
{
    QString cheminFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "C:/", "Images (*.png)");
    if (cheminFichier != "")
    {
        QImage image(cheminFichier);
        if (image.isNull())
        {
            QMessageBox::critical(this, "Erreur", "Le fichier n'est pas une image valide");
        }
        else
        {
            QPainter painter(this);
            painter.drawImage(0, 0, image);
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Aucun fichier selectionné");
    }
}