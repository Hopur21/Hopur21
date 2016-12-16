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
#include <QTimer>
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
    public slots:

private slots:
    void on_action_toolbar_Home_triggered();
    void on_action_toolbar_Show_List_triggered();
    void on_actionAdd_Computer_Scientist_triggered();
    void on_action_toolbar_Add_Computer__triggered();
    void on_actionAdd_Computer_Type_triggered();
    void on_action_toolbar_Trash_triggered();
    void on_actionExit_triggered();
    void checkDataAdded();
    void on_TextBox_Search_textChanged();

private:
    Ui::MainWindow *ui;
    Service _service;
    ShowList *_showList;
    ShowTrash *_showTrash;
    AddComputer *_addComputer;
    AddComputerScientist *_addComputerScientist;
    CSMoreInfo *_csMoreInfo;
    AddType *_addType;
    QTimer *timer;

    string _filterSearch;

    //Tabs
    void createAllTabs();
    void deleteAllTabs();
    void goHome();
    //Other
    void hardCodePictureToDB();
    void createTimer();

    //Send data
    void addNewScientist();
    void addNewComputer();
    void addNewType();
    void restoreComputerScientist();
    void restoreComputer();
    void refreshAllTables();


};

#endif // MAINWINDOW_H
