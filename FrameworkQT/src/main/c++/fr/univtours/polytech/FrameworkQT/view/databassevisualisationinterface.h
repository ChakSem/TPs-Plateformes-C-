#ifndef DATABASSEVISUALISATIONINTERFACE_H
#define DATABASSEVISUALISATIONINTERFACE_H

#include <QWidget>

namespace Ui {
class DatabasseVisualisationInterface;
}

class DatabasseVisualisationInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabasseVisualisationInterface(QWidget *parent = nullptr);
    ~DatabasseVisualisationInterface();

private:
    Ui::DatabasseVisualisationInterface *ui;
};

#endif // DATABASSEVISUALISATIONINTERFACE_H
