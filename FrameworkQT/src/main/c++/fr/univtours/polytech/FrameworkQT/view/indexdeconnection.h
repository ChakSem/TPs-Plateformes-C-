#ifndef INDEXDECONNECTION_H
#define INDEXDECONNECTION_H

#include <QDialog>

namespace Ui {
class IndexDeconnection;
}

class IndexDeconnection : public QDialog
{
    Q_OBJECT

public:
    explicit IndexDeconnection(QWidget *parent = nullptr);
    ~IndexDeconnection();

private:
    Ui::IndexDeconnection *ui;
};

#endif // INDEXDECONNECTION_H
