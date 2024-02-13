#ifndef CONNECTIONINTERFACE_H
#define CONNECTIONINTERFACE_H

#include <QWidget>

namespace Ui {
class Connection;
}

class Connection : public QWidget
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = nullptr);
    ~Connection();

private:
    Ui::Connection *ui;
};

#endif // CONNECTIONINTERFACE_H
