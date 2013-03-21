#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    ui->setupUi(this);
    qDebug()<<"ooooOO";
    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::fopen()
{

    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Parsing File"),
                                         "/home/vixlun/git/db2013/",
                                         tr("(*.xml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SAX Bookmarks"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }


}

void MainWindow::createActions() {
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(fopen()));
}



void MainWindow::createMenus() {
   fileMenu = menuBar()->addMenu(tr("&File"));
   fileMenu->addAction(openAct);
             }
