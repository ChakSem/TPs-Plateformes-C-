#ifndef CONNECTIONINTERFACE_H
#define CONNECTIONINTERFACE_H

#include <QWidget>

namespace Ui {
class ConnectionInterface;
}

class ConnectionInterface : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionInterface(QWidget *parent = nullptr);
    ~ConnectionInterface();

    /* Actions réalisées par les boutons */
    void actionConnection();

private:
    Ui::ConnectionInterface *ui;
};

#endif // CONNECTIONINTERFACE_H
