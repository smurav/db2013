#include "xmlstructuretreeview.h"
#include "ui_xmlstructuretreeview.h"

#include <QDebug>

XMLStructureTreeView::XMLStructureTreeView(QWidget *parent, char *fileName) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureTreeView)
{
    ui->setupUi(this);

    if (fileName)
        qDebug() << "We have filename:" << fileName;
}

XMLStructureTreeView::~XMLStructureTreeView()
{
    delete ui;
}
