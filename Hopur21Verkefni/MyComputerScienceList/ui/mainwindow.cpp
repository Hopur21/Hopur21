#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addcomputer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fall();

}

//QCoreApplication::quit();
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::fall()
{
    // Display scientists
    //vector<CSPerson> compScientists = _service.getComputerScientistList();

    /*
    ui->table_computerScientist->setRowCount(compScientists.size());
    ui->table_computerScientist->setColumnCount(4);
    for(size_t i = 0; i < compScientists.size(); i++)
    {

        ui->table_computerScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(compScientists[i].getName())));
        ui->table_computerScientist->setItem(i, 1, new QTableWidgetItem(QString::number(compScientists[i].getAge())));
        ui->table_computerScientist->setItem(i, 2, new QTableWidgetItem(QString::number(compScientists[i].getBirthYear())));
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
    }

*/


    /*
    AddType addMyType;
    addMyType.setModal(true);
    int success = addMyType.exec();
    if(success)
    {
        //It returns 1
    }

    */

}

void MainWindow::on_action_Add_Computer_Scientist_triggered()
{
    qDebug() << "Computer scientist pressed";

}

//Toolbar
void MainWindow::on_actionAdd_Computer_Scientist_clicked()
{
    qDebug() << "Toolbar Computer Scientist pressed";
}
void MainWindow::on_action_toolbar_Add_Computer__triggered()
{
    AddComputer addcomp;
    addcomp.setModal(true);
    addcomp.exec();
}
void MainWindow::on_actionAdd_Computer_Scientist_triggered()
{
    AddComputerScientist showScientist;
    showScientist.setModal(true);
    vector<Computer> allComputers = _service.getComputerList();
    showScientist.setComputersList(allComputers);
    showScientist.exec();
}

void MainWindow::on_pushButton_home_clicked()
{
    qDebug() << "ET go home";
    AddComputerScientist showScientist;

    showScientist.setModal(true);

    showScientist.exec();
}

void MainWindow::on_pushButton_add_clicked()
{
    AddComputer addcomp;
    addcomp.setModal(true);
    addcomp.exec();
}

//Sending the trash list onwards into trash view for display
void MainWindow::on_action_toolbar_Show_List_triggered()
{
    _showList.setModal(true);

    //Takes in a vector of computer scientists in the list
    vector<CSPerson> computerScientists = _service.getComputerScientistList();

    //Takes in a vector of computers in the list
    vector<Computer> computers = _service.getComputerList();

    //Takes the vectors and sets them into setList function in the ShowList class
    _showList.setList(computerScientists, computers);
    _showList.exec();
}
void MainWindow::on_action_toolbar_Trash_triggered()
{
    _showTrash.setModal(true);

    //Takes in a vector of computer scientists in the trash
    vector<CSPerson> compScientists = _service.getComputerScientistTrash();

    //Takes in a vector of computers in the trash
    vector<Computer> computerTrashList = _service.getComputerTrash();

    //Takes vectors and sets them into setTrashList function in the ShowTrash class
    _showTrash.setTrashList(compScientists, computerTrashList);
    _showTrash.exec();

}
