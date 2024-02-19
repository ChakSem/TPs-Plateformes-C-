#ifndef DECONNECTIONBUTTON_H
#define DECONNECTIONBUTTON_H

#include <QWidget>

namespace Ui {
class Deconnection;
}

class Deconnection : public QWidget
{
    Q_OBJECT

public:
    explicit Deconnection(QWidget *parent = nullptr);
    void actionDeconnection();
    ~Deconnection();

private:
    Ui::Deconnection *ui;
};

#endif // DECONNECTIONBUTTON_H
