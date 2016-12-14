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
//Toolbar
void MainWindow::on_action_toolbar_Add_Computer__triggered()
{
    _addComputer.setModal(true);
    _addComputer.exec();
}
void MainWindow::on_actionAdd_Computer_Scientist_triggered()
{
    AddComputerScientist showScientist;
    showScientist.setModal(true);
    vector<Computer> allComputers = _service.getComputerList();
    showScientist.setComputersList(allComputers);
    showScientist.exec();
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
