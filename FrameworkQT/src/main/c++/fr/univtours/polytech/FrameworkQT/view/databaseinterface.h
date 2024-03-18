#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QWidget>
#include <QFileDialog>
#include "../controller/controller.h"
#include "../utils/exception.h"
#include "../view/mainwindow.h"

namespace Ui {
class DatabaseInterface;
}

class DatabaseInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseInterface(QWidget *parent = nullptr);
    ~DatabaseInterface();


    void initializeComboBox();
    /* Actions réalisées par les boutons */
    void actionAddDatabase();
    void actionManageDatabase();
    void actionRemoveDatabase();
private:
    Ui::DatabaseInterface *ui;
};

#endif // DATABASEINTERFACE_H
