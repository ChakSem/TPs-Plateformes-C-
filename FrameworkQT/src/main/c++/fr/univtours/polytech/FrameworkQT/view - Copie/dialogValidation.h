#ifndef DIALOGVALIDATION_H
#define DIALOGVALIDATION_H

#include <QDialog>

namespace Ui {
class DialogPopUpValidation;
}

class DialogPopUpValidation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPopUpValidation(QWidget *parent = nullptr);
    ~DialogPopUpValidation();

private:
    Ui::DialogPopUpValidation *ui;
};

#endif // DIALOGVALIDATION_H
