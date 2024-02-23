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
    explicit ProfilesInterface(QWidget *parent = nullptr);
    ~ProfilesInterface();

    void initializeComboBox();

    /* Actions réalisées par les boutons */
    void actionAddInterface();
    void actionDeleteInterface();
    void actionManageInterface();
    void actionUpdateInterface();

private:
    Ui::ProfilesInterface *ui;
};

#endif // PROFILESINTERFACE_H
