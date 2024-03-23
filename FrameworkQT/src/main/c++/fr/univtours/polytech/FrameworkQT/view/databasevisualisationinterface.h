#ifndef DATABASEVISUALISATIONINTERFACE_H
#define DATABASEVISUALISATIONINTERFACE_H

#include <QWidget>

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

private:
    Ui::DatabaseVisualisationInterface *ui;
};

#endif // DATABASEVISUALISATIONINTERFACE_H
