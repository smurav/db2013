#include "xpathrequestwindow.h"
#include "ui_xpathrequestwindow.h"

XPathRequestWindow::XPathRequestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XPathRequestWindow)
{
    ui->setupUi(this);
    requestLine = new QString("");

    connect(ui->buttonBox, SIGNAL(accepted()),
            this, SLOT(okButtonClicked()));
}

XPathRequestWindow::~XPathRequestWindow()
{
    delete requestLine;
    delete ui;
}


QString XPathRequestWindow::getRequestLine()
{
    return *requestLine;
}

void XPathRequestWindow::okButtonClicked()
{
    this->requestLine = this->ui->requestLineEdit->text();
}
