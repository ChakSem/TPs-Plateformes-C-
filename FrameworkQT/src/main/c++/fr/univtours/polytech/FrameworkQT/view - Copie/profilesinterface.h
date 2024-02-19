#ifndef PROFILESINTERFACE_H
#define PROFILESINTERFACE_H

#include <QWidget>

namespace Ui {
class profilesInterface;
}

class profilesInterface : public QWidget
{
    Q_OBJECT

public:
    explicit profilesInterface(QWidget *parent = nullptr);
    ~profilesInterface();

private:
    Ui::profilesInterface *ui;
};

#endif // PROFILESINTERFACE_H
