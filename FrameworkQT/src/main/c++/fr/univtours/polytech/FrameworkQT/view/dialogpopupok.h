#ifndef DIALOGPOPUPOK_H
#define DIALOGPOPUPOK_H

#include <QDialog>

namespace Ui {
class DialogPopUpOk;
}

class DialogPopUpOk : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPopUpOk(QWidget *parent = nullptr);
    ~DialogPopUpOk();

private:
    Ui::DialogPopUpOk *ui;
};

#endif // DIALOGPOPUPOK_H
