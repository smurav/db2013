/********************************************************************************
** Form generated from reading UI file 'xmlstructuretreeview.ui'
**
** Created: Thu Apr 4 10:17:25 2013
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
    QAction *actionChoose;
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
        icon.addFile(QString::fromUtf8(":/openFile"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_file->setIcon(icon);
        actionExit = new QAction(XMLStructureTreeView);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/quit"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionChoose = new QAction(XMLStructureTreeView);
        actionChoose->setObjectName(QString::fromUtf8("actionChoose"));
        actionChoose->setEnabled(false);
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
        menubar->setGeometry(QRect(0, 0, 500, 25));
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
        mainToolBar->addAction(actionChoose);

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
        actionChoose->setText(QApplication::translate("XMLStructureTreeView", "Find/Choose", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionChoose->setToolTip(QApplication::translate("XMLStructureTreeView", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\262\321\213\320\261\320\276\321\200\320\272\321\203", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionChoose->setShortcut(QApplication::translate("XMLStructureTreeView", "Shift+\320\241", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("XMLStructureTreeView", "File", 0, QApplication::UnicodeUTF8));
        mainToolBar->setWindowTitle(QApplication::translate("XMLStructureTreeView", "Tool Bar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XMLStructureTreeView: public Ui_XMLStructureTreeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XMLSTRUCTURETREEVIEW_H
