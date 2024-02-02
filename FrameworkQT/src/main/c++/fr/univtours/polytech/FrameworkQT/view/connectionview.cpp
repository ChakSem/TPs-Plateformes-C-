#include "connectionview.h"
#include "././ui_ConnectionView.h"

ConnectionView::ConnectionView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ConnectionView)
{
    ui->setupUi(this);
}

ConnectionView::~ConnectionView()
{
    delete ui;
}
