#include "xpathrequestwindow.h"
#include "ui_xpathrequestwindow.h"

XPathRequestWindow::XPathRequestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XPathRequestWindow)
{
    ui->setupUi(this);
}

XPathRequestWindow::~XPathRequestWindow()
{
    delete ui;
}
