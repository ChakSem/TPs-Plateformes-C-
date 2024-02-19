#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QWidget>

namespace Ui {
class BackButton;
}

class BackButton : public QWidget
{
    Q_OBJECT

public:
    void actionBack();
    explicit BackButton(QWidget *parent = nullptr);
    ~BackButton();

private:
    Ui::BackButton *ui;
};

#endif // BACKBUTTON_H
