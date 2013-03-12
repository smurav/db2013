#include "xmlstructurethreeview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XMLStructureThreeView w;
    w.show();
    
    return a.exec();
}
