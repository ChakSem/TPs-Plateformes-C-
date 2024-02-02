#include "mainview.h"
#include "././././././././ui_MainView.h"

MainView::ConnectionView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConnectionView)
{
    ui->setupUi(this);
}

ConnectionView::~ConnectionView()
{
    delete ui;
}
