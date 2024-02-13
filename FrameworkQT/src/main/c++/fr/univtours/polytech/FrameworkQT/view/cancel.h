#ifndef CANCEL_H
#define CANCEL_H

#include <QWidget>

namespace Ui {
class cancel;
}

class cancel : public QWidget
{
    Q_OBJECT

public:
    explicit cancel(QWidget *parent = nullptr);
    ~cancel();

private:
    Ui::cancel *ui;
};

#endif // CANCEL_H
