#include "xmlstructuretreeview.h"
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
//    _model      = NULL;
    _model = new QStandardItemModel;


    if (fileName)
    {
            qDebug() << "We have filename as argv[1]:" << fileName;
        _fileName = QString(fileName);
        if (fillTreeModelWithData())
        {
            ui->treeView->expandAll();
            qDebug() << "Parsed success";
        } else {
            qDebug() << "Parse ERROR!";
        }
    }

    connect(ui->actionOpen_file, SIGNAL(triggered()),
            this, SLOT(actionOpen_fileTriggered())
            );

    /* Icon Naming Specification for 'themes'
     * http://standards.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html
     **/
    ui->actionOpen_file->setIcon(QIcon::fromTheme("document-open",
                                                  QIcon(":/openFile")));
    ui->actionExit->setIcon(QIcon::fromTheme("application-exit",
                                             QIcon(":/quit")));

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
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;

    LIBXML_TEST_VERSION


    /* how to convert Qstring <-> char
       http://qt-project.org/faq/answer/how_can_i_convert_a_qstring_to_char_and_vice_versa
    */
    QByteArray buffBA = _fileName.toUtf8();
    const char* fileName_c = buffBA.constData();

        qDebug() << "Try to Open file:" << fileName_c << endl;
    /*parse the file and get the DOM */
    doc = xmlReadFile(fileName_c, NULL, XML_PARSE_NOBLANKS);

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

    // fill root_model_item with Data
    xmlNode *cur_node = NULL;
    for (cur_node = root_element; cur_node; cur_node = cur_node->next)
    {
//        qDebug() << "->NEXT; Node type:" << cur_node->type;
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            xmlChar *uri;
            uri = xmlGetProp(cur_node, (xmlChar *) "name");
            if (uri)
            {
                root_model_item->setData((char *)uri, Qt::DisplayRole);
                qDebug() << "Set uri for root element: " << (char *)uri
                         << endl << "-------------------------------------";
            } else {
                root_model_item->setData(tr("NoName University :)"), Qt::DisplayRole);
            }
            break;
        }
    }

    // ok, let's lastly print this tree)))
    QStandardItem *childs = NULL;
    // root element must be only one in XML-file
    fillModelRootItem(root_element->children, root_model_item, childs);
    // childs will one after one be appended to 'root_model_item' if exist any

    /*free the document */
    xmlFreeDoc(doc);
    xmlCleanupParser();

    _model->setItem(0, 0, root_model_item);
    ui->treeView->setModel(_model);
    return true;
}

void XMLStructureTreeView::fillModelRootItem( _xmlNode          *a_node
                                             , QStandardItem    *parent
                                             , QStandardItem    *new_child_item
                                             )
{
    xmlNode *cur_node = NULL;
    static int deep = 0;                        // current deep-level in tree-hierarchy
        qDebug() << "Enter func, deep: " << deep;


    // go along one deep-level (this->brother1->broter2->...)
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
        qDebug() << "->NEXT; Node type:" << cur_node->type;
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            xmlChar *uri;
            uri = xmlGetProp(cur_node, (xmlChar *) "name");
            if (uri)
            {
                new_child_item = new QStandardItem(0, 0);
                new_child_item->setData((char *)uri, Qt::DisplayRole);
                qDebug() << "Set uri: " << (char *)uri;
            }
            else
            {
                qDebug() << "No name field / no uri";
                // do nothing with this Node
                // perhaps, it's `group` tag
//                       xmlGetProp(cur_node, (xmlChar *)"number"),
//                       xmlGetProp(cur_node, (xmlChar *)"entering")
//                       );
            }
        } else {
            qDebug() << "cur_node_type != xml+element_node (text between tags)"
                     << endl << "Content:" << (char *)cur_node->content;
        }

            deep++;
//        qDebug()<< endl;

            qDebug() << "Go deeper, deep: " << deep;
        fillModelRootItem(cur_node->children, new_child_item, NULL);

        // save information about childrens
        if (new_child_item != NULL && parent != NULL)
        {
            parent->appendRow(new_child_item);
            qDebug() << "Add children:"
                     << new_child_item->data(Qt::DisplayRole).toString();
            new_child_item = NULL;
        }
            deep--; // all done, go to the next brother
            qDebug() << "Go back, deep: " << deep;
    }
}

//----------------------------------------------------------------------------------------
// SLOT: Trigered by actionOpen_file
// Show fileDialog to select xml-file
void XMLStructureTreeView::actionOpen_fileTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Выберите XML файл"),
                                                    ".",
                                                    tr("XML файлы (*.xml)"));
    if ( !fileName.isEmpty() )
    {
        qDebug() << "Select file: " << fileName;
        _fileName = fileName;
        if (fillTreeModelWithData())
        {
            ui->treeView->expandAll();
            qDebug() << "Parsed success";
        } else {
            qDebug() << "Parse ERROR!";
        }
    }
}















