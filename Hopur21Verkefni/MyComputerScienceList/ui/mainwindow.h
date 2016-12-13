#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "services/service.h"
#include "models/computer.h"
#include "models/csperson.h"
#include "ui/addcomputer.h"
#include "ui/addcomputerscientist.h"
#include "ui/addtype.h"
#include "ui/showlist.h"

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

    void fall();

private slots:

    void on_button_quitProgram_clicked();

    void on_action_Add_Computer_Scientist_triggered();

    void on_pushButton_home_clicked();

    void on_actionAdd_Computer_Scientist_clicked();

    void on_pushButton_add_clicked();

    void on_action_toolbar_Add_Computer__triggered();

    void on_actionAdd_Computer_Scientist_triggered();

private:
    Service _service;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
