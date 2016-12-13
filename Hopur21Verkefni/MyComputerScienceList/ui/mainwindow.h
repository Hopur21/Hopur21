#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "services/service.h"
#include "models/computer.h"
#include "models/csperson.h"

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
    void on_table_computerScientist_activated(const QModelIndex &index);

    void on_button_quitProgram_clicked();

    void on_action_Add_Computer_Scientist_triggered();

    void on_pushButton_home_clicked();

    void on_actionAdd_Computer_Scientist_clicked();

private:
    Service _service;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
