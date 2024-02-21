#ifndef ADDPROFILEADMININTERFACE_H
#define ADDPROFILEADMININTERFACE_H

#include <QWidget>

namespace Ui {
class addProfileAdminInterface;
}

class addProfileAdminInterface : public QWidget
{
    Q_OBJECT

public:
    explicit addProfileAdminInterface(QWidget *parent = nullptr);
    void actionCreateAdminProfile();
    ~addProfileAdminInterface();

private:
    Ui::addProfileAdminInterface *ui;
};

#endif // ADDPROFILEADMININTERFACE_H
