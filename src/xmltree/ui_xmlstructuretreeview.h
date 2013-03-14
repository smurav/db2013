/********************************************************************************
** Form generated from reading UI file 'xmlstructuretreeview.ui'
**
** Created: Thu Mar 14 08:44:06 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XMLSTRUCTURETREEVIEW_H
#define UI_XMLSTRUCTURETREEVIEW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XMLStructureTreeView
{
public:
    QAction *actionOpen_file;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *XMLStructureTreeView)
    {
        if (XMLStructureTreeView->objectName().isEmpty())
            XMLStructureTreeView->setObjectName(QString::fromUtf8("XMLStructureTreeView"));
        XMLStructureTreeView->resize(500, 500);
        XMLStructureTreeView->setLocale(QLocale(QLocale::Russian, QLocale::RussianFederation));
        actionOpen_file = new QAction(XMLStructureTreeView);
        actionOpen_file->setObjectName(QString::fromUtf8("actionOpen_file"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon);
        actionExit = new QAction(XMLStructureTreeView);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralwidget = new QWidget(XMLStructureTreeView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setAutoExpandDelay(-1);
        treeView->header()->setVisible(false);

        verticalLayout->addWidget(treeView);

        XMLStructureTreeView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(XMLStructureTreeView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        XMLStructureTreeView->setMenuBar(menubar);
        statusbar = new QStatusBar(XMLStructureTreeView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        XMLStructureTreeView->setStatusBar(statusbar);
        mainToolBar = new QToolBar(XMLStructureTreeView);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::RightToolBarArea);
        mainToolBar->setIconSize(QSize(32, 32));
        XMLStructureTreeView->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_file);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionOpen_file);

        retranslateUi(XMLStructureTreeView);

        QMetaObject::connectSlotsByName(XMLStructureTreeView);
    } // setupUi

    void retranslateUi(QMainWindow *XMLStructureTreeView)
    {
        XMLStructureTreeView->setWindowTitle(QApplication::translate("XMLStructureTreeView", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\201\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\213 XML \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        actionOpen_file->setText(QApplication::translate("XMLStructureTreeView", "Open file...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen_file->setToolTip(QApplication::translate("XMLStructureTreeView", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 XML \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen_file->setShortcut(QApplication::translate("XMLStructureTreeView", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("XMLStructureTreeView", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("XMLStructureTreeView", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("XMLStructureTreeView", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("XMLStructureTreeView", "File", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("XMLStructureTreeView", "Tool Bar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XMLStructureTreeView: public Ui_XMLStructureTreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMLSTRUCTURETREEVIEW_H
