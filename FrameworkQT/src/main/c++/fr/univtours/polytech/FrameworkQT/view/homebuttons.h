#ifndef HOMEBUTTONS_H
#define HOMEBUTTONS_H

#include <QWidget>

namespace Ui {
class HomeButtons;
}

class HomeButtons : public QWidget
{
    Q_OBJECT

public:
    explicit HomeButtons(QWidget *parent = nullptr);
    ~HomeButtons();

private:
    Ui::HomeButtons *ui;
};

#endif // HOMEBUTTONS_H
