#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "services/service.h"
#include "models/computer.h"
#include "models/csperson.h"
#include "ui/addcomputer.h"
#include "ui/addcomputerscientist.h"
#include "ui/addtype.h"
#include "ui/showlist.h"
#include "ui/showtrash.h"
#include "ui/csmoreinfo.h"

#include <QTableWidget>

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

private slots:
    void on_action_toolbar_Home_triggered();
    void on_action_toolbar_Show_List_triggered();
    void on_actionAdd_Computer_Scientist_triggered();
    void on_action_toolbar_Add_Computer__triggered();
    void on_actionAdd_Computer_Type_triggered();
    void on_action_toolbar_Trash_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Service _service;
    ShowList *_showList;
    ShowTrash *_showTrash;
    AddComputer *_addComputer;
    AddComputerScientist *_addComputerScientist;
    CSMoreInfo *_csMoreInfo;
    AddType *_addType;

    //Tabs
    void createAllTabs();
    void deleteAllTabs();
    void addSearchToMenuBar();
};

#endif // MAINWINDOW_H
