#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>

namespace Ui {
class ComboBox;
}

class comboBox : public QWidget
{
    Q_OBJECT

public:
    explicit comboBox(QWidget *parent = nullptr);
    ~comboBox();

private:
    Ui::ComboBox *ui;
};

#endif // COMBOBOX_H
