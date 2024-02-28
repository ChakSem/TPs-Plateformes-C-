#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QWidget>

namespace Ui
{
    class BackButton;
}

class BackButton : public QWidget
{
    Q_OBJECT

public:
    explicit BackButton(QWidget *parent = nullptr);
    ~BackButton();

    /* Actions réalisées par les boutons */
    void actionBack();

private:
    Ui::BackButton *ui;
};

#endif // BACKBUTTON_H
