#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->chooseButton, SIGNAL(clicked()),
            this, SLOT(chooseButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


static QString print_element_names(xmlNode * a_node){

    xmlNode *cur_node = NULL;
    int k = 0;
    static int deep = 0;
    static QString list;


    // ходим по одному уровню (по сёстрам и братьям)
    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {

        if (cur_node->type == XML_ELEMENT_NODE) {
            ++k;
            for (int kol = 0; kol<deep; ++kol){
                printf("\t");
                list.append("    ");
            }
            printf("name:%d __ %s = %s\n", k, (char*)cur_node->properties->name,
                                      (char*)cur_node->properties->children->content
                                        );
            list.append(QString((char*)cur_node->properties->children->content));
            list.append('\n');


        }
        //  переходим к детям, вглубь на 1 уровень
        deep++;
        print_element_names(cur_node->children);
        deep--;
    } 
   return list;
}


void MainWindow::chooseButtonClicked(){

    ui->textEdit->clear();
    QString fileName   =   QFileDialog::getOpenFileName(this, tr("Choose file"), "/home/vika/git/db2013/xml", tr("XML (*.xml)"));

    if (fileName.isEmpty())
        return;
    /*
     * conversion QString to a char*
     */
    QByteArray ba = fileName.toLatin1();

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    /*parse the file and get the DOM */
    doc = xmlReadFile(ba.data(), NULL, 0);

    if (doc == NULL) {
        qDebug() << "Warning~!!!!!!";
        QMessageBox msbox;
        msbox.setWindowTitle("Error!!!!");
        msbox.setText("File is not XML");
        msbox.exec();
    }

    /*Get the root element node */
    root_element = xmlDocGetRootElement(doc);


    ui->textEdit->setText(print_element_names(root_element));

    /*free the document */
    xmlFreeDoc(doc);

    /*
     *Free the global variables that may
     *have been allocated by the parser.
     */
    xmlCleanupParser();





}
