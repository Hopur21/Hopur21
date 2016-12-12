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

private:
    Service _service;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
