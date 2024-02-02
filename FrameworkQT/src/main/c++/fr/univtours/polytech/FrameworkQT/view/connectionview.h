#ifndef CONNECTIONVIEW_H
#define CONNECTIONVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectionView;
}
QT_END_NAMESPACE

class ConnectionView : public QMainWindow
{
    Q_OBJECT

public:
    ConnectionView(QWidget *parent = nullptr);
    ~ConnectionView();

private:
    Ui::ConnectionView *ui;
};
#endif // CONNECTIONVIEW_H
