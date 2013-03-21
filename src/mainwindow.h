#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createActions();
    void createMenus();

public slots :
    void fopen() ;
private:
    Ui::MainWindow *ui;


    QMenu *fileMenu;
    QAction *openAct;

};

#endif // MAINWINDOW_H
