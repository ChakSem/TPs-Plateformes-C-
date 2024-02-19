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
    void actionConnection();
    ~ConnectionInterface();

private:
    Ui::ConnectionInterface *ui;
};

#endif // CONNECTIONINTERFACE_H
