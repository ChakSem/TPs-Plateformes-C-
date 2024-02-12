#ifndef MAINCONNECTION_H
#define MAINCONNECTION_H

#include <QDialog>

namespace Ui {
class MainConnection;
}

class MainConnection : public QDialog
{
    Q_OBJECT

public:
    explicit MainConnection(QWidget *parent = nullptr);
    void static show();
    ~MainConnection();

private:
    Ui::MainConnection *ui;
};

#endif // MAINCONNECTION_H
