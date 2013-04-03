#include "xmlstructuretreeview.h"
#include "ui_xmlstructuretreeview.h"
#include "xml_libxml.h"

#include <libxml/parser.h>
#include <libxml/tree.h>

#include <QFileDialog>
#include <QMessageBox>
#include <QStandardItemModel>
    #include <QDebug>

XMLStructureTreeView::XMLStructureTreeView(QWidget *parent, char *fileName) :
    QMainWindow(parent),
    ui(new Ui::XMLStructureTreeView)
{
    ui->setupUi(this);
    _model = 0;
    _model = new QStandardItemModel;
    if (0 == _model) {
        qDebug() << "Memory fail : we haven't init _model yet";
        exit(-1);
//        qApp->exit(-1);   // may be this?
    }
    ui->statusbar->showMessage(tr("Ready!"));

    /* maybe we have an arg from console..
     */
    if (fileName)
    {
            qDebug() << "We have filename as argv[1]:" << fileName;
        _fileName = QString(fileName);
        if (fillTreeModelWithData()) {
            ui->treeView->expandAll();
            qDebug() << "Parse file :success";
        } else {
            ui->statusbar->showMessage(tr("Ошибка парсинга XML файла."));
            qDebug() << "Parse ERROR!";
        }
    }

    connect(ui->actionOpen_file, SIGNAL(triggered()),
            this, SLOT(actionOpen_fileTriggered())
            );

    connect(ui->actionExit, SIGNAL(triggered()),
            qApp, SLOT(quit())
            );

    /* Icon Naming Specification for `themes' icons`
     * http://standards.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html
     **/
    ui->actionOpen_file->setIcon(QIcon::fromTheme("document-open",
                                                  QIcon(":/openFile")));
    ui->actionExit->setIcon(QIcon::fromTheme("application-exit",
                                             QIcon(":/quit")));
}
//-------------------
XMLStructureTreeView::~XMLStructureTreeView()
{
    if (0 != ui)
    {
        delete ui;
        ui = 0;
    }
    if (0 != _model)
    {
        delete _model;
        _model = 0;
    }
}

//------------------------------------------------------------------------------
/* Parse XML file @_fileName and fill model @_model
 * with data as tree
 **/
bool XMLStructureTreeView::fillTreeModelWithData()
{
    if (_fileName.isEmpty()) {
//        qDebug() << "Empty filename";
        return false;
    }

    // prepare
    _model->clear();
    QStandardItem *root_model_item = new QStandardItem(0, 0);
    xmlDoc *doc;
    xmlNode *root_element;
    LIBXML_TEST_VERSION


    if (0 == root_model_item) {
        qDebug() << "Memory fail - Can't continue. Can't create QStandardItem*";
        exit(-1);
    }


    /* how to convert Qstring <-> char
     * http://qt-project.org/faq/answer/how_can_i_convert_a_qstring_to_char_and_vice_versa
     **/
    QByteArray buffBA = _fileName.toUtf8();
    const char *fileName_c = buffBA.constData();


    /* Validate file with DTD
     **/
    if (validateFileWithDTD(fileName_c)) {
        // ok, go next
        qDebug() << "Validation : PASS";
    } else {
        qDebug() << "Validation : FaiL!------------------------------------" << endl;
        QMessageBox::critical(this, tr("Ошибка форматирования файла"),
                                tr("Файл не соответствует DTD-диаграмме, или она не найдена.\n"
                                   "Программа запущена в debug режиме, так что "
                                   "просто посмотрите вывод программы в консоль."),
                                    QMessageBox::Ok
                                    );
        return false;
    }



    /* parse the file and get the DOM */
    doc = xmlReadFile(fileName_c, 0, XML_PARSE_NOBLANKS);

    if (0 == doc) {
        fprintf(stderr, "error: could not parse file %s\n", fileName_c);
        QMessageBox::critical(this, tr("Ошибка парсинга файла"),
                                tr("Не удалось распарсить файл.\n"
                                   "Более подробную информацию об ошибке можно\n"
                                   "узнать, вызвав программу из консоли с параметрами:\n"
                                   "-c <путь к файлу>.\n"
                                    "Пожалуйста, выберите другой файл."),
                                    QMessageBox::Ok /*| QMessageBox::Open*/
                                    );
        return false;
    }

    /* Get the root element node
     **/
    root_element = xmlDocGetRootElement(doc);

    if (0 == root_element) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        ui->statusbar->showMessage(tr("Empty document!"));
        return false;
    }


    /* fill root_model_item itself with Data
     **/
    xmlNode *cur_node = 0;
    for (cur_node = root_element; cur_node; cur_node = cur_node->next)
    {
    //        qDebug() << "->NEXT; Node type:" << cur_node->type;
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            xmlChar *uri;
            uri = xmlGetProp(cur_node, (xmlChar *)"name");
            if (uri)
            {
                root_model_item->setData((char *)uri, Qt::DisplayRole);
//                qDebug() << "Set uri for root element: " << (char *)uri
//                         << endl << "-------------------------------------";
            }
            break;
        }
    }




    /* construct tree
     * childs will one after one be appended to 'root_model_item' if exist any
     */
    QStandardItem *childs = 0;
    fillModelRootItem(root_element->children, root_model_item, childs);


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
    xmlNode *cur_node;
//    static int deep = 0;                 // current deep-level in tree-hierarchy


    /* go along one deep-level (this->brother1->broter2->...)
     **/
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
//        qDebug() << "->NEXT; Node type:" << cur_node->type;
        if (cur_node->type == XML_ELEMENT_NODE)
        {
            xmlChar *uri;
            uri = xmlGetProp(cur_node, (xmlChar *)"name");
            if (uri)
            {
                new_child_item = new QStandardItem(0, 0);
                if (0 == new_child_item) {
                    qDebug() << "Memory fail.";
                    exit(-1);
                }
                new_child_item->setData((char *)uri, Qt::DisplayRole);
//                qDebug() << "Set uri: " << (char *)uri;
            }
            else
            {
                // perhaps, it's `group` tag
                QString noNameAttr = "";
                noNameAttr.append((char *)xmlGetProp(cur_node, (xmlChar *)"number"));
                noNameAttr.append(tr(", "));
                noNameAttr.append((char *)xmlGetProp(cur_node, (xmlChar *)"entering"));

                new_child_item = new QStandardItem(0, 0);
                if (0 == new_child_item) {
                    qDebug() << "Memory fail.";
                    exit(-1);
                }
                new_child_item->setData(noNameAttr, Qt::DisplayRole);
//                qDebug() << "Set noNameAttr: " << noNameAttr;
            }
        }

        fillModelRootItem(cur_node->children, new_child_item, 0);

        /* save information about childrens
         **/
        if (new_child_item != 0 && parent != 0) {
            parent->appendRow(new_child_item);
//            qDebug() << "Add children:"
//                     << new_child_item->data(Qt::DisplayRole).toString();
            new_child_item = 0;
        }
    }
}

//------------------------------------------------------------------------------
/* SLOT: Trigered by actionOpen_file
 * Show fileDialog to select xml-file
 **/
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
//            qDebug() << "File Parse: success";
        } else {
            qDebug() << "File Parse ERROR!";
        }
    }
}






