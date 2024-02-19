#ifndef PROFILESINTERFACE_H
#define PROFILESINTERFACE_H

#include <QWidget>

namespace Ui {
class ProfilesInterface;
}

class ProfilesInterface : public QWidget
{
    Q_OBJECT

public:
    void actionAddInterface();
    void actionDeleteInterface();
    void actionManageInterface();
    void actionUpdateInterface();
    explicit ProfilesInterface(QWidget *parent = nullptr);
    ~ProfilesInterface();

private:
    Ui::ProfilesInterface *ui;
};

#endif // PROFILESINTERFACE_H
