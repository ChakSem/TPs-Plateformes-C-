#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QWidget>

namespace Ui {
class cancelButton;
}

class cancelButton : public QWidget
{
    Q_OBJECT

public:
    explicit cancelButton(QWidget *parent = nullptr);
    ~cancelButton();

private:
    Ui::cancelButton *ui;
};

#endif // BACKBUTTON_H
