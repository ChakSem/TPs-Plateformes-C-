#ifndef ACCOUNTINFORMATIONSINTERFACE_H
#define ACCOUNTINFORMATIONSINTERFACE_H

#include <QWidget>
namespace Ui {
class AccountInformationsInterface;
}

class AccountInformationsInterface : public QWidget
{
    Q_OBJECT

public:
    explicit AccountInformationsInterface(QWidget *parent = nullptr);
    ~AccountInformationsInterface();

private:
    void setAccountInformations();
    Ui::AccountInformationsInterface *ui;


  
     
};

#endif // ACCOUNTINFORMATIONSINTERFACE_H
