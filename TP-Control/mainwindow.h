#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../model/profile.h"

/* Réference sur les pages des StackedWidget */
#define MAINWIDGET_CONNECTION 0
class QStackedWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
public:

private:
    Q_OBJECT

public:
    static MainWindow* accessToParent(QWidget* widget);
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    void openProfiles();
    Ui::MainWindow *ui;
    QList<int> previousPages; // Sera utilisé par le bouton de retour en arriere
};

#endif // MAINWINDOW_H
