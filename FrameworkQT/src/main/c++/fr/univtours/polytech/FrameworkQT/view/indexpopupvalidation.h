#ifndef INDEXPOPUPVALIDATION_H
#define INDEXPOPUPVALIDATION_H

#include <QDialog>

namespace Ui {
class indexPopUpValidation;
}

class indexPopUpValidation : public QDialog
{
    Q_OBJECT

public:
    explicit indexPopUpValidation(QWidget *parent = nullptr);
    ~indexPopUpValidation();

private:
    Ui::indexPopUpValidation *ui;
};

#endif // INDEXPOPUPVALIDATION_H
