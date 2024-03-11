#ifndef DATABASSEEXECUTIONINTERFACE_H
#define DATABASSEEXECUTIONINTERFACE_H

#include <QWidget>

namespace Ui {
class DatabasseExecutionInterface;
}

class DatabasseExecutionInterface : public QWidget
{
    Q_OBJECT

public:
    explicit DatabasseExecutionInterface(QWidget *parent = nullptr);
    ~DatabasseExecutionInterface();

private:
    Ui::DatabasseExecutionInterface *ui;
};

#endif // DATABASSEEXECUTIONINTERFACE_H
