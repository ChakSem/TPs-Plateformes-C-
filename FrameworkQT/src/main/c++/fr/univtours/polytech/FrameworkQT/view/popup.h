#ifndef POPUP_H
#define POPUP_H

#include <QMainWindow>

class PopUp : public QMainWindow
{
    Q_OBJECT
public:
    explicit PopUp(QWidget *parent = nullptr);

signals:
};

#endif // POPUP_H
