#ifndef ADDPROFILEINTERFACE_H
#define ADDPROFILEINTERFACE_H

#include <QWidget>

namespace Ui
{
    class AddProfileInterface;
}

class AddProfileInterface : public QWidget
{
    Q_OBJECT

public:
    explicit AddProfileInterface(QWidget *parent = nullptr);
    ~AddProfileInterface();

    /* Actions réalisées par les boutons */
    void actionCreateProfile();

private:
    Ui::AddProfileInterface *ui;
};

#endif // ADDPROFILEINTERFACE_H
