/********************************************************************************
** Form generated from reading UI file 'xpathrequestwindow.ui'
**
** Created: Thu Apr 4 09:42:38 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XPATHREQUESTWINDOW_H
#define UI_XPATHREQUESTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XPathRequestWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *requestLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *XPathRequestWindow)
    {
        if (XPathRequestWindow->objectName().isEmpty())
            XPathRequestWindow->setObjectName(QString::fromUtf8("XPathRequestWindow"));
        XPathRequestWindow->resize(400, 130);
        XPathRequestWindow->setMinimumSize(QSize(400, 130));
        XPathRequestWindow->setMaximumSize(QSize(400, 130));
        widget = new QWidget(XPathRequestWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 361, 91));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        requestLineEdit = new QLineEdit(widget);
        requestLineEdit->setObjectName(QString::fromUtf8("requestLineEdit"));

        verticalLayout->addWidget(requestLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(XPathRequestWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), XPathRequestWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), XPathRequestWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(XPathRequestWindow);
    } // setupUi

    void retranslateUi(QDialog *XPathRequestWindow)
    {
        XPathRequestWindow->setWindowTitle(QApplication::translate("XPathRequestWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("XPathRequestWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \320\267\320\260\320\277\321\200\320\276\321\201:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class XPathRequestWindow: public Ui_XPathRequestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XPATHREQUESTWINDOW_H
