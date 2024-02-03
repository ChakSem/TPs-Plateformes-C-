#ifndef INDEXPROFIL_H
#define INDEXPROFIL_H

#include <QDialog>

namespace Ui {
class IndexProfil;
}

class IndexProfil : public QDialog
{
    Q_OBJECT

public:
    explicit IndexProfil(QWidget *parent = nullptr);
    ~IndexProfil();

private:
    Ui::IndexProfil *ui;
};

#endif // INDEXPROFIL_H
