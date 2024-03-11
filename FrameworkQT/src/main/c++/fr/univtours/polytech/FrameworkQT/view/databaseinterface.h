#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QWidget>


namespace Ui {
class DatabaseInterface;
}

class DatabaseInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseInterface(QWidget *parent = nullptr);
    ~DatabaseInterface();

private:
    Ui::DatabaseInterface *ui;
    /*Methode pour recuperer le path d'un fichier .db ou .sqlite*/
    QString getPathFile();
    void actionAddDatabase();
};

#endif // DATABASEINTERFACE_H
