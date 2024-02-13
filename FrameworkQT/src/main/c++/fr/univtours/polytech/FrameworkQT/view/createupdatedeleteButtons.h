#ifndef CREATEUPDATEDELETEBUTTONS_H
#define CREATEUPDATEDELETEBUTTONS_H

#include <QWidget>

namespace Ui {
class indexCreateUpdateDelete;
}

class indexCreateUpdateDelete : public QWidget
{
    Q_OBJECT

public:
    explicit indexCreateUpdateDelete(QWidget *parent = nullptr);
    ~indexCreateUpdateDelete();

private:
    Ui::indexCreateUpdateDelete *ui;
};

#endif // CREATEUPDATEDELETEBUTTONS_H
