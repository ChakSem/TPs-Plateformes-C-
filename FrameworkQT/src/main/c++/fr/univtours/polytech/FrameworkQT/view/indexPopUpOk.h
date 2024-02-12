#ifndef INDEXPOPUPOK_H
#define INDEXPOPUPOK_H

#include <QDialog>

namespace Ui {
class indexPopUpChampsManquants;
}

class indexPopUpChampsManquants : public QDialog
{
    Q_OBJECT

public:
    explicit indexPopUpChampsManquants(QWidget *parent = nullptr);
    ~indexPopUpChampsManquants();

private:
    Ui::indexPopUpChampsManquants *ui;
};

#endif // INDEXPOPUPOK_H
