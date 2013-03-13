#ifndef XMLSTRUCTURETREEVIEW_H
#define XMLSTRUCTURETREEVIEW_H

#include <QMainWindow>

struct _xmlNode;
class QStandardItem;
class QStandardItemModel;

namespace Ui {
class XMLStructureTreeView;
}

class XMLStructureTreeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit XMLStructureTreeView(QWidget *parent = 0, char *fileName = 0);
    ~XMLStructureTreeView();

private:
    QStandardItemModel *_model;
    QString _fileName;

    Ui::XMLStructureTreeView *ui;


    bool fillTreeModelWithData();
    void fillModelRootItem(_xmlNode *a_node, QStandardItem *root_model_item);

private slots:
    void actionOpen_fileTriggered();

};

#endif // XMLSTRUCTURETREEVIEW_H
