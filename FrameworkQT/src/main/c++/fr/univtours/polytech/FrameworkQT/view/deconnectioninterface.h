#ifndef DECONNECTIONINTERFACE_H
#define DECONNECTIONINTERFACE_H

#include <QWidget>

namespace Ui {
class DeconnectionInterface;
}

class DeconnectionInterface : public QWidget
{
    Q_OBJECT

public:
    void actionDeconnection();
    explicit DeconnectionInterface(QWidget *parent = nullptr);
    ~DeconnectionInterface();

private:
    Ui::DeconnectionInterface *ui;
};

#endif // DECONNECTIONINTERFACE_H
