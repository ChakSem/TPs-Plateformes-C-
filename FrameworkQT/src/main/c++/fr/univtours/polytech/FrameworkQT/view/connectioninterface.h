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
    void actionConnection();
    explicit ConnectionInterface(QWidget *parent = nullptr);
    ~ConnectionInterface();

private:
    Ui::ConnectionInterface *ui;
};

#endif // CONNECTIONINTERFACE_H
