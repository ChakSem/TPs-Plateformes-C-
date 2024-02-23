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
    explicit DialogValidation(QWidget *parent = nullptr);
    ~DialogValidation();

    /* Actions réalisées par les boutons */
    void actionCancel();
    void actionValidate();

private:
    Ui::DialogValidation *ui;
};

#endif // DIALOGVALIDATION_H
