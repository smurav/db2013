#ifndef XPATHREQUESTWINDOW_H
#define XPATHREQUESTWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class XPathRequestWindow;
}

class XPathRequestWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit XPathRequestWindow(QWidget *parent = 0);
    ~XPathRequestWindow();

    QString getRequestLine();
    
private:
    Ui::XPathRequestWindow *ui;
    QString                *requestLine;

private slots:
    void okButtonClicked();
};

#endif // XPATHREQUESTWINDOW_H
