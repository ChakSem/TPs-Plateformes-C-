#ifndef INDEXBDD_H
#define INDEXBDD_H

#include <QDialog>

namespace Ui {
class IndexBdd;
}

class IndexBdd : public QDialog
{
    Q_OBJECT

public:
    explicit IndexBdd(QWidget *parent = nullptr);
    ~IndexBdd();

private:
    Ui::IndexBdd *ui;
};

#endif // INDEXBDD_H
