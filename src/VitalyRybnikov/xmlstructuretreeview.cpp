#include "xmlstructuretreeview.h"
#include "ui_xmlstructuretreeview.h"

#include <QFileDialog>
#include <QStandardItemModel>
    #include <QDebug>

XMLStructureTreeView::XMLStructureTreeView(QWidget *parent, char *fileName) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureTreeView)
{
    ui->setupUi(this);
    _model      = NULL;



    if (fileName)
    {
        qDebug() << "We have filename:" << fileName;
        _fileName = QString(fileName);
    }

    connect(ui->actionOpen_file, SIGNAL(triggered()),
            this, SLOT(actionOpen_fileTriggered())
            );






    _model = new QStandardItemModel;

//    QStandardItem item1;
//    QStandardItem item1("string_item");

//    QStandardItem item2("string_item_2");

//    item1.appendRow(&item2);

    QStandardItem *item1 = new QStandardItem(0, 1);
    item1->setData("text", Qt::DisplayRole);

    QStandardItem *item2 = new QStandardItem(0, 1);
    item2->setData("Hohoho", Qt::DisplayRole);

    item1->appendRow(item2);

//    _model->insertRow(0);
    _model->setItem(0, 0, item1);


//    QModelIndex index;
//    _model->setData(index, "string");
//    _model->setItem(0, &item1);

    ui->treeView->setModel(_model);
}

XMLStructureTreeView::~XMLStructureTreeView()
{
    delete ui;
    delete _model;
}

//----------------------------------------------------------------------------------------
// Parse XML file '_fileName' and fill model '_model'
// with data as tree
bool XMLStructureTreeView::fillTreeModelWithData()
{
    if (_fileName.isEmpty())
        return false;
}
//----------------------------------------------------------------------------------------
// slot: Trigered by actionOpen_file
// Show fileDialog to select xml-file
void XMLStructureTreeView::actionOpen_fileTriggered()
{
    qDebug() << "Open file triggered";

//    QFileDialog filedialog;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Выберите XML файл"),
                                                    ".",
                                                    tr("XML файлы (*.xml)"));
    if ( !fileName.isEmpty() )
    {
        qDebug() << "Select file: " << fileName;
        _fileName = fileName;
    }
}














