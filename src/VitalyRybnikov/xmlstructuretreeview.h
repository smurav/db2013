#ifndef XMLSTRUCTURETREEVIEW_H
#define XMLSTRUCTURETREEVIEW_H

#include <QMainWindow>

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
    Ui::XMLStructureTreeView *ui;
};

#endif // XMLSTRUCTURETREEVIEW_H
