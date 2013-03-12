#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <libxml/parser.h>
#include <libxml/tree.h>

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

void MainWindow::chooseButtonClicked(){

    QString fileName   =   QFileDialog::getOpenFileName(this, tr("Choose file"), QDir::currentPath(), tr("XML (*.xml)"));

    if (fileName.isEmpty())
        return;


}
