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
    // Display scientists
    vector<CSPerson> compScientists = _service.getComputerScientistList();

    ui->table_computerScientist->setRowCount(compScientists.size());
    ui->table_computerScientist->setColumnCount(3);
    for(size_t i = 0; i < compScientists.size(); i++)
    {

        ui->table_computerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientists[i].getName())));
        ui->table_computerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientists[i].getAge())));
        ui->table_computerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(compScientists[i].getBirthYear())));
<<<<<<< HEAD
        ui->table_computerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(compScientists[i].getAge())));
=======
        ui->table_computerScientist->setItem(i, 3, new QTableWidgetItem(QString::number(compScientists[i].getPassedAwayYear())));
    }

    // Display computers
    vector<Computer> computerList = _service.getComputerList();
    ui->table_computer->setRowCount(computerList.size());
    ui->table_computer->setColumnCount(4);
    for(size_t j = 0; j < computerList.size(); j++)
    {

        ui->table_computer->setItem(j, 0, new QTableWidgetItem(QString::fromStdString(computerList[j].getName())));
        ui->table_computer->setItem(j, 1, new QTableWidgetItem(QString::fromStdString(computerList[j].getType())));
        ui->table_computer->setItem(j, 2, new QTableWidgetItem(QString::number(computerList[j].getDesignYear())));
        ui->table_computer->setItem(j, 3, new QTableWidgetItem(QString::number(computerList[j].getBuildYear())));
>>>>>>> 176c77d595269763c9799ca4318160a011d51f66
    }




}

void MainWindow::on_table_computerScientist_activated(const QModelIndex &index)
{

}

void MainWindow::on_button_quitProgram_clicked()
{
    QCoreApplication::quit();
}
