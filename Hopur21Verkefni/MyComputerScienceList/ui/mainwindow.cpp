#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/addcomputer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createAllTabs();
    createTimer();
}
MainWindow::~MainWindow()
{
    deleteAllTabs();
    delete timer;
    delete ui;
}
//We use the timer to check if user has tried to add data to the program.
void MainWindow::createTimer()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkDataAdded()));
    timer->start(500); //time specified in ms
}

void MainWindow::hardCodePictureToDB()
{
    /*
    QString filename = "no-image-available.png";
    QFile file("../../Computers/computer scientists/" + filename);
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Could Open File";
        QByteArray inByteArray = file.readAll();
        _service.onlyAddPicturetoDB(filename.toStdString(),inByteArray);//Uncomment this line to write Picture to database.
    }
    */
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

//Toolbar
void MainWindow::goHome()
{
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_HOME);//Head back home
}

void MainWindow::on_action_toolbar_Home_triggered()
{
    //TODO - Refresh all data before entering.
    goHome();
}

void MainWindow::on_action_toolbar_Show_List_triggered()
{
    //Send our data into the show list tab before we open it.
    _showList->setList(_service.getComputerScientistList(_filterSearch), _service.getComputerList(_filterSearch));
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_SHOW_LIST);
}

void MainWindow::on_actionAdd_Computer_Scientist_triggered()
{
    _addComputerScientist->resetAllData();
    _addComputerScientist->setComputersList(_service.getComputerList(_filterSearch));
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_CS);
}

void MainWindow::on_action_toolbar_Add_Computer__triggered()
{
    _addComputer->clearFields();
    _addComputer->resetData();
    _addComputer->setComputerType(_service.getComputerTypesList());
    _addComputer->setComputerScientistList(_service.getComputerScientistList(_filterSearch));
    _addComputer->setComputerTypesComboBox();
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_COMPUTER);
}

void MainWindow::on_actionAdd_Computer_Type_triggered()
{
    _addType->clearFields();
    _addType->resetData();
    _addType->setTypes(_service.getComputerTypesList());//Sending computer types so we can check if this type already exist.
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_ADD_TYPE);
}
void MainWindow::on_action_toolbar_Trash_triggered()
{
    _showTrash->setTrashList(_service.getComputerScientistTrash(_filterSearch), _service.getComputerTrash(_filterSearch));
    ui->tabWidget_MainWindow->setCurrentIndex(constants::TAB_SHOW_RECYCLE_BIN);
}
void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

//Check if data is needed to be inserted into the database.
void MainWindow::checkDataAdded()
{
    //If Computer Scientist was added.
    if(_addComputerScientist->result())//If Add computer scientist was valid.
    {
        addNewScientist();
        _addComputerScientist->setResult(false);//Set result back to false
        goHome();
    }
    //If Computer was added.
    if(_addComputer->result())
    {
        addNewComputer();
        _addComputer->setResult(false);
        goHome();
    }
    //If computer type was added
    if(_addType->result())
    {
        addNewType();
        _addType->setResult(false);
        goHome();
    }
    //If we are going to restore some data
    if(_showTrash->result())
    {
        if(_showTrash->getCompOrScientistToRestore() == constants::COMPUTER_SCIENTIST)
        {
            restoreComputerScientist();
            _showTrash->setResult(false);
        }
        else//Restore computer
        {
            restoreComputer();
            _showTrash->setResult(false);
        }
    }
    //If we are going to remove some data
    if(_showList->result())
    {
        if(_showList->getIfToRemoveComputer() == constants::COMPUTER)
        {
            _service.removeComputerFromList(to_string(_showList->getIdToRemove()));
        }
        else
        {
            _service.removePersonFromList(to_string(_showList->getIdToRemove()));
        }
        _showList->setList(_service.getComputerScientistList(_filterSearch), _service.getComputerList(_filterSearch));
        _showList->setResult(false);
    }
}
void MainWindow::addNewScientist()
{

    CSPerson newScientist = _addComputerScientist->getPerson();
    _service.addNewPersonToList(_addComputerScientist->getComputersConnected(),\
                                newScientist.getName(),\
                                newScientist.getGender(),\
                                to_string(newScientist.getBirthYear()),\
                                to_string(newScientist.getPassedAwayYear()),\
                                newScientist.getComments(),\
                                _addComputerScientist->getImageName(),\
                                _addComputerScientist->getImage());
}
void MainWindow::addNewComputer()
{
    Computer newComputer = _addComputer->getComputer();
    _service.addNewComputerToList(_addComputer->getCSconntedToComp(),\
                                  newComputer.getName(),\
                                  newComputer.getDesignYear(),\
                                  newComputer.getBuildYear(),\
                                  newComputer.getTypeID(),\
                                  newComputer.getIsCreated(),\
                                  _addComputer->getImageName(),\
                                  _addComputer->getImage());
}
void MainWindow::addNewType()
{
    _service.addComputerType(_addType->getTypeName());
}
void MainWindow::restoreComputerScientist()
{
    _service.restorePersonToList(_showTrash->getCSidToRestore());
    _showTrash->setTrashList(_service.getComputerScientistTrash(_filterSearch), _service.getComputerTrash(_filterSearch));
}
void MainWindow::restoreComputer()
{
    _service.restoreComputerToList(_showTrash->getComputerIDToRestore());
    _showTrash->setTrashList(_service.getComputerScientistTrash(_filterSearch), _service.getComputerTrash(_filterSearch));
}

void MainWindow::on_TextBox_Search_textChanged()
{
    _filterSearch = ui->TextBox_Search->text().toStdString();
}
