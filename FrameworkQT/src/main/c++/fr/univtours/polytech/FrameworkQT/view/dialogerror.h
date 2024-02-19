#ifndef DIALOGERROR_H
#define DIALOGERROR_H

#include <QWidget>

namespace Ui {
class DialogError;
}

class DialogError : public QWidget
{
    Q_OBJECT

public:
    void actionError();
    explicit DialogError(QWidget *parent = nullptr);
    ~DialogError();

private:
    Ui::DialogError *ui;
};

#endif // DIALOGERROR_H
