#ifndef DATABASEVISUALISATIONINTERFACE_H
#define DATABASEVISUALISATIONINTERFACE_H

#include <QWidget>
#include "QStandardItemModel"

namespace Ui {
class DatabaseVisualisationInterface;
}

class DatabaseVisualisationInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabaseVisualisationInterface(QWidget *parent = nullptr);
    ~DatabaseVisualisationInterface();

    void initializeTableWidget(QString tableName);
    void initializeTableWidgetForSelectQuery(QString requete);

private:
    Ui::DatabaseVisualisationInterface *ui;

    QStandardItemModel* model;
};

#endif // DATABASEVISUALISATIONINTERFACE_H
