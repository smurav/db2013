#include "xmlstructurethreeview.h"
#include "ui_xmlstructurethreeview.h"

XMLStructureThreeView::XMLStructureThreeView(QWidget *parent, char *fileName) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureThreeView)
{
    ui->setupUi(this);
}

XMLStructureThreeView::~XMLStructureThreeView()
{
    delete ui;
}
