#include "addcomputer.h"
#include "ui_addcomputer.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);
    int year = getCurrentYear();
    initValidationData(year);
}

void AddComputer::initValidationData(int year)
{
    // Validation for year of design and year of build
    // the parameters are (lowest number, highest number)
    yearValidator = new QIntValidator(1,year);
    // here the validation is set to both: yearofdesign and yearofbuild fields
    // more info on this in the extra features document
    ui->lineEdit_AddComputer_designYear->setValidator(yearValidator);
    ui->lineEdit_AddComputer_buildYear->setValidator(yearValidator);
}

int AddComputer::getCurrentYear()
{
    // getCurrent year   (year is the current year)
    // therefore in the year 2016 the variable year becomes 2016
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;
    return year;
}

AddComputer::~AddComputer()
{
    delete yearValidator;
    delete ui;
}

void AddComputer::setComputerType(vector<ComputerType> computerTypes)
{
    _listOfComputerTypes = computerTypes;
}

void AddComputer::setComputerTypesComboBox()
{
    ui->comboBox_AddComputer_selectTypeOfComputer->clear();//Clear the combobox before we insert into it.
    for(unsigned int i=0;i<_listOfComputerTypes.size();i++)
    {
        ui->comboBox_AddComputer_selectTypeOfComputer->addItem(QString::fromStdString(_listOfComputerTypes[i].getName()));
    }
}

void AddComputer::setComputerScientistList(vector<CSPerson> allScientists, vector<ComputerScientistToComputer> computerConnection)
{
    _computerCSconnection = computerConnection;
    _listOfScientists = allScientists;
    ui->tableWidget_AddComputer_selectScientistForComputer->setRowCount(allScientists.size());
    ui->tableWidget_AddComputer_selectScientistForComputer->setColumnCount(3);
    for(size_t i = 0; i < allScientists.size(); i++)
    {
        ui->tableWidget_AddComputer_selectScientistForComputer->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(allScientists[i].getName())));
        ui->tableWidget_AddComputer_selectScientistForComputer->setItem(i, 1, new QTableWidgetItem(QString::number(allScientists[i].getBirthYear())));
        ui->tableWidget_AddComputer_selectScientistForComputer->setItem(i, 2, new QTableWidgetItem(QString::number(allScientists[i].getID())));
        ui->tableWidget_AddComputer_selectScientistForComputer->setColumnHidden(2,true);//Hide our ID column
    }
}

void AddComputer::on_pushButton_AddComputer_browseComputer_clicked()
{
    try
    {
        if(comvertAndSaveFile())
        {
            setImageButtonAsImage();
        }
    }
    catch(int e)
    {

    }
}

void AddComputer::on_pushButton_imageComputer_clicked()
{
    try
    {
        if(comvertAndSaveFile())
        {
            setImageButtonAsImage();
        }
    }
    catch(int e)
    {

    }
}

void AddComputer::on_pushButton_AddComputer_saveComputer_clicked()
{
    // clear the error messages
    clearErrorMessages();

    // If validation fails these are used
    bool nameFail = false;
    bool designYearFail = false;
    bool buildYearFail = false;
    bool computerTypeFail = false;

    // invalid build year in context with design year
    bool buildYearInvalid = false;

    // If validation fails this is set as false
    bool canCreateComputer = true;

    // isBuilt is connected to the checkbox
    bool isBuilt;
    QString name = ui->lineEdit_AddComputer_nameComputer->text();
    QString designYear = ui->lineEdit_AddComputer_designYear->text();
    QString buildYear = "";
    isBuilt = ui->checkBox_AddComputer_wasComputerBuilt->isChecked();

    // This function saves the IDs of the selected computer scientist to a member variable
    saveComputerScientistIDs();

    // Index of the selected type
    int computerTypeComboBoxSelectedIndex = ui->comboBox_AddComputer_selectTypeOfComputer->currentIndex();
    int computerTypeID = _listOfComputerTypes.at(computerTypeComboBoxSelectedIndex).getID();

    if(isBuilt)
    {
        buildYear = ui->lineEdit_AddComputer_buildYear->text();
    }
    else
    {
        // If the computer was never built then buildYear is set to 0
        buildYear = "0";
    }

    // Validations
    if(name == "")
    {
        canCreateComputer = false;
        nameFail = true;
    }

    if(designYear == "")
    {
        canCreateComputer = false;
        designYearFail = true;
    }
    if(isBuilt == true && buildYear == "")
    {
        canCreateComputer = false;
        buildYearFail = true;
    }
    if(designYear >= buildYear && isBuilt == true)
    {
        canCreateComputer = false;
        buildYearInvalid = true;
    }
    if(computerTypeID == constants::NOTHING_SELECTED)
    {
        canCreateComputer = false;
        computerTypeFail = true;
    }
    // If canCreatePerson is true, the person can be created
    if(canCreateComputer)
    {
        Computer newComputer;
        _newComputer = newComputer;
        _newComputer.setName(name.toStdString());
        _newComputer.setDesignYear(designYear.toInt());
        _newComputer.setCreated(ui->checkBox_AddComputer_wasComputerBuilt->isChecked());
        _newComputer.setBuildYear(buildYear.toInt());
        _newComputer.setType(ui->comboBox_AddComputer_selectTypeOfComputer->currentText().toStdString(),computerTypeID);
        this->setResult(QDialog::Accepted);
        clearFields();
    }
    else
    {
        QString initial = "The following fields are missing: ";
        QString errorMessage = validateUserInput(nameFail,designYearFail, buildYearFail, computerTypeFail, buildYearInvalid);
        ui->AddComputer_ErrorMessage->setText(initial + "<span style = 'color : red'>" + errorMessage + "</span>");
        this->setResult(QDialog::Rejected);
    }
}

// This function creates the error string for: on_pushButton_AddComputer_saveComputer_clicked()
QString AddComputer::validateUserInput(bool nameFail, bool designYearFail, bool buildYearFail, bool computerTypeFail, bool buildYearInvalid)
{
    QString errorString = "";

    if(nameFail == true)
    {
        errorString += "* Name *";
    }
    if(designYearFail == true)
    {
        errorString += "* Design year *";
    }
    if(buildYearInvalid == true)
    {
        QString message = "Invalid year of build";
        ui->AddComputer_InvalidBuildYear->setText("<span style = 'color : red'>" + message + "</span>");
    }
    if(buildYearFail == true)
    {
        errorString += "* Build year *";
    }
    if(computerTypeFail == true)
    {
        QString message = "Please select a type";
        ui->AddComputer_InvalidBuildYear->setText("<span style = 'color : red'>" + message + "</span>");
    }

    return errorString;
}

void AddComputer::on_checkBox_AddComputer_wasComputerBuilt_toggled(bool checked)
{
    // If checkbox is not checked then it is not possible to edit the buildyear
    if(checked)
    {
        ui->checkBox_AddComputer_wasComputerBuilt->setChecked(constants::ENABLED);
        ui->label_buildYear->setEnabled(constants::ENABLED);
        ui->lineEdit_AddComputer_buildYear->setEnabled(constants::ENABLED);
    }
    else if(!checked)
    {
        ui->checkBox_AddComputer_wasComputerBuilt->setChecked(constants::DISABLED);
        ui->lineEdit_AddComputer_buildYear->clear();
        ui->label_buildYear->setDisabled(constants::ENABLED);
        ui->lineEdit_AddComputer_buildYear->setEnabled(constants::DISABLED);
    }
}

void AddComputer::on_pushButton_AddComputer_clearFields_clicked()
{
    clearFields();
}

void AddComputer::saveComputerScientistIDs()
{
    // This clears the computer vector
    _scientistsConnected.clear();
    QItemSelectionModel *select = ui->tableWidget_AddComputer_selectScientistForComputer->selectionModel();

    for(int i = 0; i < select->selectedRows(2).count(); i++)//SelectedRows(2) = the ID column
    {
        int scientistID = select->selectedRows(2).value(i).data().toInt();
        _scientistsConnected.push_back(scientistID);
    }
}

void AddComputer::resetData()
{
    vector<ComputerType> listOfComputerTypes;
    _listOfComputerTypes = listOfComputerTypes;

    vector<int> scientistsConnected;
    _scientistsConnected = scientistsConnected;

    Computer newComputer;
    _newComputer = newComputer;

    QByteArray image;
    _image = image;
    string imageName;
    _imageName = imageName;

    vector<ComputerScientistToComputer> computerCSconnection;
    _computerCSconnection = computerCSconnection;
}

void AddComputer::clearFields()
{
    // set checkbox default as checked
    on_checkBox_AddComputer_wasComputerBuilt_toggled(true);

    // clear the error messages
    ui->AddComputer_ErrorMessage->clear();
    ui->AddComputer_InvalidBuildYear->clear();

    // Clear fields
    ui->lineEdit_AddComputer_nameComputer->clear();
    ui->lineEdit_AddComputer_designYear->clear();
    ui->lineEdit_AddComputer_buildYear->clear();
    ui->tableWidget_AddComputer_selectScientistForComputer->clearSelection();

    //Browse picture button
    QPixmap pix(":/icons/images/image_computer.png");
    QIcon icon(pix);
    ui->pushButton_imageComputer->setIcon(icon);
}

void AddComputer::clearErrorMessages()
{
    ui->AddComputer_ErrorMessage->clear();
    ui->AddComputer_InvalidBuildYear->clear();
}


QString AddComputer::browseForFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file", "directoryToOpen",
            "Images (*.png *.gif *.jpg)");
    return filename;
}

bool AddComputer::comvertAndSaveFile()
{
    QString fileLocation = browseForFile();
    QFile file(fileLocation);
    if (file.open(QIODevice::ReadOnly))
    {
        QFileInfo fileInfo(fileLocation);
        _imageName = fileInfo.fileName().toStdString();//Get the file name.
        _image = file.readAll();
        return true;
    }

    return false;
}

void AddComputer::setImageButtonAsImage()
{
    QPixmap pixmap = QPixmap();
    pixmap.loadFromData( _image );
    QIcon buttonIcon(pixmap);
    ui->pushButton_imageComputer->setIcon(buttonIcon);
}

void AddComputer::on_tableWidget_AddComputer_selectScientistForComputer_doubleClicked(const QModelIndex &index)
{
    _csMoreInfo.setComputerScientist(_personToSend);
    _csMoreInfo.setModal(true);
    _csMoreInfo.exec();
}

CSPerson AddComputer::getPersonFromID(int id)
{
    for(unsigned int i = 0; i < _listOfScientists.size(); i++)
    {
        if (_listOfScientists[i].getID() == id)
        {
            return _listOfScientists[i];
        }
    }
}

void AddComputer::on_tableWidget_AddComputer_selectScientistForComputer_cellClicked(int row, int column)
{
    _personToSend = getPersonFromID(_idForMoreInfo = ui->tableWidget_AddComputer_selectScientistForComputer->item(row,2)->text().toInt());
    _row = row;
}
