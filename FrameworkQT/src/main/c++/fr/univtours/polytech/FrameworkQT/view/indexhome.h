#ifndef INDEXHOME_H
#define INDEXHOME_H

#include <QDialog>

namespace Ui {
class IndexHome;
}

class IndexHome : public QDialog
{
    Q_OBJECT

public:
    explicit IndexHome(QWidget *parent = nullptr);
    ~IndexHome();

private:
    Ui::IndexHome *ui;
};

#endif // INDEXHOME_H
