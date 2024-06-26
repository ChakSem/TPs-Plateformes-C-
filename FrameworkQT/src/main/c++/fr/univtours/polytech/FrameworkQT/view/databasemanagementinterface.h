#ifndef DATABASEMANAGEMENTINTERFACE_H
#define DATABASEMANAGEMENTINTERFACE_H

#include <QWidget>

namespace Ui {
class DatabaseManagementInterface;
}

class DatabaseManagementInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseManagementInterface(QWidget *parent = nullptr);
    ~DatabaseManagementInterface();

    void initializeComboBox();
    /* Actions réalisées par les boutons */
    void actionVisualization();
    void actionExecute();

private:
    Ui::DatabaseManagementInterface *ui;
    /*Methode pour recuperer le path d'un fichier .db ou .sqlite*/
    QString getPathFile();
    void actionAddDatabase();
};

#endif // DATABASEMANAGEMENTINTERFACE_H
