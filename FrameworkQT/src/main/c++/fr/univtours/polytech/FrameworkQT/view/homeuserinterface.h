#ifndef HOMEUSERINTERFACE_H
#define HOMEUSERINTERFACE_H

#include <QWidget>

namespace Ui {
class HomeUserInterface;
}

class HomeUserInterface : public QWidget
{
    Q_OBJECT

public:
    explicit HomeUserInterface(QWidget *parent = nullptr);
    ~HomeUserInterface();

    /* Actions réalisées par les boutons */
    void actionAccount();
    void actionProfile();

private:
    Ui::HomeUserInterface *ui;
};

#endif // HOMEUSERINTERFACE_H
