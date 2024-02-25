#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/* Réference sur les pages des StackedWidget */
#define MAINWIDGET_CONNECTION 0
#define MAINWIDGET_USER_MANAGEMENT 1
#define MAINWIDGET_FIRST_USER_REGISTRATION 2
#define MAINWIDGET_ACCOUNT_CREATION 3
#define MAINWIDGET_PROFILES 4
#define MAINWIDGET_ADD_PROFILE 5
#define MAINWIDGET_HOME_ADMIN 6
#define MAINWIDGET_HOME_USER 7
#define MAINWIDGET_MY_ACCOUNT 8

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

    void openConnection();
    void openUsers();
    void openAccount();
    void openMyProfiles();
    void openProfiles(User* user);
    void openDatabases();
    void openCreateUser();
    void openAddProfiles();

    void updateTableView(User* user);

    void returnOnPreviousView();

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    void openProfiles();
    Ui::MainWindow *ui;
    QList<int> previousPages; // Sera utilisé par le bouton de retour en arriere
};

#endif // MAINWINDOW_H
