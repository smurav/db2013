#include "xmlstructuretreeview.h"
//#include "ui_xmlstructuretreeview.h"

#include "ui_xmlstructuretreeview.h"

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <QFileDialog>
#include <QStandardItemModel>
    #include <QDebug>

XMLStructureTreeView::XMLStructureTreeView(QWidget *parent, char *fileName) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureTreeView)
{
    ui->setupUi(this);
    _model      = NULL;

    _model = new QStandardItemModel;


    if (fileName)
    {
        qDebug() << "We have filename as argv[1]:" << fileName;
        _fileName = QString(fileName);
        _model = new QStandardItemModel;
        if (fillTreeModelWithData())
        {
            qDebug() << "Parsed success";
        } else {
            qDebug() << "Parse ERROR!";
        }
    }

    connect(ui->actionOpen_file, SIGNAL(triggered()),
            this, SLOT(actionOpen_fileTriggered())
            );




return;



//    QStandardItem item1;
//    QStandardItem item1("string_item");

//    QStandardItem item2("string_item_2");

//    item1.appendRow(&item2);

    QStandardItem *item1 = new QStandardItem(0, 0);
    item1->setData("text", Qt::DisplayRole);

    QStandardItem *item2 = new QStandardItem(0, 0);
    item2->setData("Hohoho", Qt::DisplayRole);

    QStandardItem *item3 = new QStandardItem(0, 0);
    item3->setData("Third", Qt::DisplayRole);

    item2->appendRow(item3);
    item1->appendRow(item2);


    _model->setItem(0, item1);



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

    _model->clear();
    QStandardItem *root_model_item = new QStandardItem(0, 0);

    // construct tree
//    root_item->setData(tr("Wow"), Qt::DisplayRole);

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    /* how to convert Qstring <-> char
       http://qt-project.org/faq/answer/how_can_i_convert_a_qstring_to_char_and_vice_versa
    */

    QByteArray buffBA = _fileName.toUtf8();
    const char* fileName_c = buffBA.constData();

        qDebug() << "Try to Open file:" << fileName_c;
    doc = xmlReadFile(fileName_c, NULL, 0);

    if (doc == NULL) {
        fprintf(stderr, "error: could not parse file %s\n", fileName_c);
        // TODO: generate Pop-up error msg
        return false;
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);

    if (root_element == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        // TODO: generate error msg to user
        return false;
    }

    // good to use DTD for that, or smth else
    if (xmlStrcmp(root_element->name, (const xmlChar *) "university"))
    {
            fprintf(stderr,"document of the wrong type, root node != university\n");
            xmlFreeDoc(doc);
            // TODO: need pop-up error
            return false;
    }

    // ok, let's lastly print three)))
    //    printElementNames(root_element);
    fillModelRootItem(root_element, root_model_item);

    /*free the document */
    xmlFreeDoc(doc);
    xmlCleanupParser();

    _model->setItem(0, 0, root_model_item);
    ui->treeView->setModel(_model);
    return true;
}

void XMLStructureTreeView::fillModelRootItem(_xmlNode       *a_node,
                                             QStandardItem  *root_model_item
                                             )
{
    xmlNode *cur_node = NULL;
    QStandardItem *cur_model_node = NULL;

    cur_model_node = root_model_item;
    static int deep = 0;                        // current deep-level in three-hierarchy

    // go along one deep-level (this->brother1->broter2->...)
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            xmlChar *uri;
                    qDebug() << "Current node: " << (char *)cur_node->properties->name;

            // We interested only in attrs 'name'
            uri = xmlGetProp(cur_node, (xmlChar *) "name");
            if (uri)
            {

                cur_model_node->setData((char *)uri, Qt::DisplayRole);
//                root_model_item->setData ((char *) uri, Qt::DisplayRole);
                qDebug() << "Set uri: " << (char *)uri;
                //                printf("set uri: %s\n", uri);
            } else
            {
                qDebug() << "No uri";
                // perhaps, it's 'group' tag
//                printf("%s %s, %s\n", cur_node->name,
//                       xmlGetProp(cur_node, (xmlChar *)"number"),
//                       xmlGetProp(cur_node, (xmlChar *)"entering")
//                       );
            }

//        return; // TEST
        } else {
            qDebug() << "cur_node_type != xml+element_node";
        }


        // print information about childrens
        deep++;

        QStandardItem *childs = new QStandardItem(0, 0);
        qDebug()<< endl;

        fillModelRootItem(cur_node->children, childs);

        if (childs->data(Qt::DisplayRole).isNull())
        {
            qDebug() << "Need not append this:";
            qDebug() << "Append child:" << childs->data(Qt::DisplayRole) <<  "with row count: " << childs->rowCount();
        } else {
            cur_model_node->appendRow(childs);
        }


        deep--; // all done, go to the next brother
    }
}

//----------------------------------------------------------------------------------------
// SLOT: Trigered by actionOpen_file
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
        fillTreeModelWithData();
    }
}















