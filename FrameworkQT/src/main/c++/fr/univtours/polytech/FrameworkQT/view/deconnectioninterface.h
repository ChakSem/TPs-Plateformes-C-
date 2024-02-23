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
    explicit DeconnectionInterface(QWidget *parent = nullptr);
    ~DeconnectionInterface();

    /* Actions réalisées par les boutons */
    void actionDeconnection();

private:
    Ui::DeconnectionInterface *ui;
};

#endif // DECONNECTIONINTERFACE_H
