#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "stdlib.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPoint>
#include <QPaintEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    fileName = "";
    ui->setupUi(this);
    connect(ui->Bouton_OuvertureExplorateurFichier, &QPushButton::clicked, this, &MainWindow::actionOuvertureExplorateurFichier);
    connect(ui->pushButton_Enregistrer, &QPushButton::clicked, this, &MainWindow::EnregistrerImage);

    connect(ui->spinBox_X, &QSpinBox::valueChanged, this, &MainWindow::XChanged);
    connect(ui->spinBox_Y, &QSpinBox::valueChanged, this, &MainWindow::YChanged);
    connect(ui->spinBox_Hauteur, &QSpinBox::valueChanged, this, &MainWindow::HauteurChanged);
    connect(ui->spinBox_Longueur, &QSpinBox::valueChanged, this, &MainWindow::LongueurChanged);
    // frame(int)));LongueurChanged);
    // frame
    image = NULL;

    WIDTH = this->width();
    HEIGHT = this->height();

    pen.setWidth(10);
    pen.setColor(Qt::red);
    //on dimensionne le rectangle a la taille de l'image
    rect.setTopLeft(QPoint(0, 0));
    rect.setWidth(WIDTH * 0.8);
    rect.setHeight(HEIGHT * 0.8);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Methode qui quand on changer la valeur de X dans le spinbox, on change la valeur de X dans le rectangle
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::XChanged()
{

    ui->spinBox_Longueur->setRange(0, 0.8 * WIDTH - ui->spinBox_X->value());
    rect.setTopLeft(QPoint(ui->spinBox_X->value(), ui->spinBox_Y->value()));

    update();
}

/*Methode qui quand on changer la valeur de X dans le spinbox, on change la valeur de X dans le rectangle
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::YChanged()
{
    ui->spinBox_Hauteur->setRange(0, 0.8 * HEIGHT - ui->spinBox_Y->value());
    rect.setTopLeft(QPoint(ui->spinBox_X->value(), ui->spinBox_Y->value()));
    update();
}
/*Methode qui quand on changer la valeur de X dans le spinbox, on change la valeur de X dans le rectangle
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::LongueurChanged()
{
    ui->spinBox_X->setRange(0, 0.8 * WIDTH - ui->spinBox_Longueur ->value());
    rect.setWidth(ui->spinBox_Longueur->value());
    update();
}

/*Methode qui quand on changer la valeur de X dans le spinbox, on change la valeur de X dans le rectangle
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::HauteurChanged()
{
    ui->spinBox_Y->setRange(0, 0.8 * HEIGHT - ui->spinBox_Hauteur->value());
    rect.setHeight(ui->spinBox_Hauteur->value());
    update();
}

/*Methode pour ouvrir une image dans le mainwindow, en utilisant un explorateur de fichier
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::actionOuvertureExplorateurFichier()
{
    QString cheminFichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "C:/", "Images (*.png)");

    if (cheminFichier != "")
    {
        image = new QImage(cheminFichier);
        if (image->isNull())
        {
            QMessageBox::critical(this, "Erreur", "Le fichier n'est pas une image valide");
        }
        else
        {
            fileName = cheminFichier;

            // on set les valeurs de la hauteur et de la longueur
            ui->spinBox_Hauteur->setValue(HEIGHT * 0.8);
            ui->spinBox_Hauteur->setRange(0, HEIGHT * 0.8);
            ui->spinBox_Longueur->setValue(WIDTH * 0.8);
            ui->spinBox_Longueur->setRange(0, HEIGHT * 0.8);
            update();
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Aucun fichier selectionné");
    }
}

/*Methode
 * Entrée : <QPaintEvent *event>
 * Sortie : <void>
 */
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (fileName != "")
    {
        // rendre les spinbox age
        ui->spinBox_X->setEnabled(true);
        ui->spinBox_Y->setEnabled(true);
        ui->spinBox_Hauteur->setEnabled(true);
        ui->spinBox_Longueur->setEnabled(true);

        image = new QImage(fileName);

        // on recuper les dimensions de la fenetre
        image =new QImage(image->scaled(WIDTH * 0.8, HEIGHT * 0.8, Qt::KeepAspectRatio));
        // centrer

        // centrer l'image

        painter.drawImage(QPoint(0, 0), *image);

        painter.setPen(pen);
        painter.drawRect(rect);
    }
}


/*Methode pour enregistrer une image
 * Entrée : <void>
 * Sortie : <void>
 */
void MainWindow::EnregistrerImage()
{
    if (fileName != "")
    {
        image = new QImage(fileName);
        QString cheminFichier = QFileDialog::getSaveFileName(this, "Enregistrer l'image", "C:/", "Images (*.png)");

        if (cheminFichier != "")
        {
            image->copy(ui->spinBox_X->value(), ui->spinBox_Y->value(), ui->spinBox_Longueur->value(), ui->spinBox_Hauteur->value()).save(cheminFichier);
             
        }
        else
        {
            QMessageBox::critical(this, "Erreur", "Aucun fichier selectionné");
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Aucun fichier selectionné");
    }
}
