#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void actionOuvertureExplorateurFichier();
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void XChanged();
    void YChanged();
    void LongueurChanged();
    void HauteurChanged();
    void EnregistrerImage();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QPen pen;
    QRect rect;
    int WIDTH;
    int HEIGHT;
    QImage* image;
};
#endif // MAINWINDOW_H
