#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/* Réference sur les pages des StackedWidget */
#define MAINWIDGET_CONNECTION 0
#define MAINWIDGET_USER_MANAGEMENT 1
#define MAINWIDGET_ACCOUNT_CREATION 2
#define MAINWIDGET_PROFILES 3
#define MAINWIDGET_ADD_PROFILE 4
#define MAINWIDGET_HOME_ADMIN 5
#define MAINWIDGET_HOME_USER 6

#define BACKWIDGET_VOID 1
#define BACKWIDGET_VISIBLE 0

#define DECONNECTIONWIDGET_VOID 1
#define DECONNECTIONWIDGET_VISIBLE 0

class QStackedWidget;

class User;

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

    void displayDeconnection();
    void displayBack();
    void actionConnection(QString id, QString password);
    void actionDeconnection();

    void openUsers();
    void openAccount();
    void openMyProfiles();
    void openDatabases();
    void openCreateUser();
    void openAddProfiles(User* user);
    void openAddProfilesFromProfiles();
    void openProfiles(User* user);

    void returnOnPreviousView();

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int previousPage; // Sera utilisé par le bouton de retour en arriere
};

#endif // MAINWINDOW_H
