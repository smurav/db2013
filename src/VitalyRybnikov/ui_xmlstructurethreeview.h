/********************************************************************************
** Form generated from reading UI file 'xmlstructurethreeview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMLSTRUCTURETHREEVIEW_H
#define UI_XMLSTRUCTURETHREEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XMLStructureThreeView
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *XMLStructureThreeView)
    {
        if (XMLStructureThreeView->objectName().isEmpty())
            XMLStructureThreeView->setObjectName(QString::fromUtf8("XMLStructureThreeView"));
        XMLStructureThreeView->resize(400, 300);
        menuBar = new QMenuBar(XMLStructureThreeView);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        XMLStructureThreeView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(XMLStructureThreeView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        XMLStructureThreeView->addToolBar(mainToolBar);
        centralWidget = new QWidget(XMLStructureThreeView);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        XMLStructureThreeView->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(XMLStructureThreeView);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        XMLStructureThreeView->setStatusBar(statusBar);

        retranslateUi(XMLStructureThreeView);

        QMetaObject::connectSlotsByName(XMLStructureThreeView);
    } // setupUi

    void retranslateUi(QMainWindow *XMLStructureThreeView)
    {
        XMLStructureThreeView->setWindowTitle(QApplication::translate("XMLStructureThreeView", "XMLStructureThreeView", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XMLStructureThreeView: public Ui_XMLStructureThreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMLSTRUCTURETHREEVIEW_H
