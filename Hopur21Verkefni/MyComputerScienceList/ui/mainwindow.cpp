#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addcomputer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createAllTabs();
    addSearchToMenuBar();
}
MainWindow::~MainWindow()
{
    deleteAllTabs();
    delete ui;
}
void MainWindow::createAllTabs()
{
    ui->tabWidget_MainWindow->removeTab(1);//Remove second (index 1) tab so we can edit it the rest here.
    _showList = new ShowList(this);
    _addComputerScientist = new AddComputerScientist(this);
    _addComputer = new AddComputer(this);
    _addType = new AddType(this);
    _showTrash = new ShowTrash(this);

    ui->tabWidget_MainWindow->addTab(_showList,"Show List");
    ui->tabWidget_MainWindow->addTab(_addComputerScientist,"Add CS");
    ui->tabWidget_MainWindow->addTab(_addComputer,"Add Comp");
    ui->tabWidget_MainWindow->addTab(_addType,"Add Type");
    ui->tabWidget_MainWindow->addTab(_showTrash,"Show Recycle");
    //ui->tabWidget_MainWindow->addTab(tTIW,*(new QIcon(":/icons/images/computer2_icon.png")), tr("Tab Name"));//How to add QIcon
}
void MainWindow::deleteAllTabs()
{
    delete _showList;
    delete _addComputerScientist;
    delete _addComputer;
    delete _addType;
    delete _showTrash;
}
void MainWindow::addSearchToMenuBar()
{
    /*
     * TODO
    QWidgetAction *widgetAction = new QWidgetAction(this);
    widgetAction->setDefaultWidget(new QProgressBar(this));
    QMenuBar::setCornerWidget(widgetAction);
    ui->menuBar->addAction(widgetAction);
    */

}
//void QMenuBar::setCornerWidget ( QWidget * widget, Qt::Corner corner = Qt::TopRightCorner ){}

//Toolbar
void MainWindow::on_action_toolbar_Home_triggered()
{
    //TODO - Refresh all data before entering.
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_HOME);
}

void MainWindow::on_action_toolbar_Show_List_triggered()
{
    //Send our data into the show list tab before we open it.
    _showList->setList(_service.getComputerScientistList(), _service.getComputerList());
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_SHOW_LIST);
}

void MainWindow::on_actionAdd_Computer_Scientist_triggered()
{
    _addComputerScientist->clearFields();
    _addComputerScientist->setComputersList(_service.getComputerList());
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_CS);
}

void MainWindow::on_action_toolbar_Add_Computer__triggered()
{
    //TODO - Refresh all data before opening.
    _addComputer->clearFields();

    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_COMPUTER);
}

void MainWindow::on_actionAdd_Computer_Type_triggered()
{
    //TODO - Refresh all data before opening.
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_TYPE);
}
void MainWindow::on_action_toolbar_Trash_triggered()
{
    _showTrash->setTrashList(_service.getComputerScientistTrash(), _service.getComputerTrash());
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_SHOW_RECYCLE_BIN);
}
void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}
