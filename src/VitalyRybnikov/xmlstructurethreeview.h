#ifndef XMLSTRUCTURETHREEVIEW_H
#define XMLSTRUCTURETHREEVIEW_H

#include <QMainWindow>

namespace Ui {
class XMLStructureThreeView;
}

class XMLStructureThreeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit XMLStructureThreeView(QWidget *parent = 0, char *fileName = NULL);
    ~XMLStructureThreeView();

private:
    Ui::XMLStructureThreeView *ui;
};

#endif // XMLSTRUCTURETHREEVIEW_H
