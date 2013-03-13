#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void chooseButtonClicked();


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
