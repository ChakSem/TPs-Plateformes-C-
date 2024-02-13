#ifndef DECONNECTION_H
#define DECONNECTION_H

#include <QWidget>

namespace Ui {
class Deconnection;
}

class Deconnection : public QWidget
{
    Q_OBJECT

public:
    explicit Deconnection(QWidget *parent = nullptr);
    ~Deconnection();

private:
    Ui::Deconnection *ui;
};

#endif // DECONNECTION_H
