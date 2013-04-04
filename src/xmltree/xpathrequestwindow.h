#ifndef XPATHREQUESTWINDOW_H
#define XPATHREQUESTWINDOW_H

#include <QDialog>

namespace Ui {
class XPathRequestWindow;
}

class XPathRequestWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit XPathRequestWindow(QWidget *parent = 0);
    ~XPathRequestWindow();
    
private:
    Ui::XPathRequestWindow *ui;
};

#endif // XPATHREQUESTWINDOW_H
