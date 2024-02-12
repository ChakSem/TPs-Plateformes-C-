#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
    //Singleton
    static MainWindow& getInstance()
    {
        static MainWindow instance;
        return instance;
    }
private:
    Q_OBJECT

public:
    Ui::MainWindow* getUi();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
