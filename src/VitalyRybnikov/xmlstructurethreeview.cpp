#include "xmlstructurethreeview.h"
#include "ui_xmlstructurethreeview.h"

XMLStructureThreeView::XMLStructureThreeView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureThreeView)
{
    ui->setupUi(this);
}

XMLStructureThreeView::~XMLStructureThreeView()
{
    delete ui;
}
