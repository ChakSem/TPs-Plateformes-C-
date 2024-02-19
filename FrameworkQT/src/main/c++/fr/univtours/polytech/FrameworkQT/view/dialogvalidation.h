#ifndef DIALOGVALIDATION_H
#define DIALOGVALIDATION_H

#include <QWidget>

namespace Ui {
class DialogValidation;
}

class DialogValidation : public QWidget
{
    Q_OBJECT

public:
    void actionCancel();
    void actionValidate();
    explicit DialogValidation(QWidget *parent = nullptr);
    ~DialogValidation();

private:
    Ui::DialogValidation *ui;
};

#endif // DIALOGVALIDATION_H
