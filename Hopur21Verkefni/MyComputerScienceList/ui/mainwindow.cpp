#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fall();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fall()
{
    vector<CSPerson> compScientists = _service.getComputerScientistList();
    ui->table_computerScientist->setRowCount(compScientists.size());
    ui->table_computerScientist->setColumnCount(3);
    for(size_t i = 0; i < compScientists.size(); i++)
    {

        ui->table_computerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientists[i].getName())));
        ui->table_computerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientists[i].getAge())));
    }

}

void MainWindow::on_table_computerScientist_activated(const QModelIndex &index)
{

}

void MainWindow::on_button_quitProgram_clicked()
{
    QCoreApplication::quit();
}
