#include "addcomputerscientist.h"
#include "ui_addcomputerscientist.h"


AddComputerScientist::AddComputerScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerScientist)
{
    ui->setupUi(this);
    initValidationData();
    //okButton->setAutoDefault(false);


    //connect(ui, SIGNAL(clicked()), this, SLOT(checkValues()));
}
AddComputerScientist::~AddComputerScientist()
{
    delete yearValidator;
    delete ui;
}
void AddComputerScientist::setComputersList(vector<Computer> allComputers)
{
    ui->tableWidget_Addscientist_selectComputerForScientist->setRowCount(allComputers.size());
    ui->tableWidget_Addscientist_selectComputerForScientist->setColumnCount(3);
    for(size_t i = 0; i < allComputers.size(); i++)
    {
        ui->tableWidget_Addscientist_selectComputerForScientist->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(allComputers[i].getName())));
        ui->tableWidget_Addscientist_selectComputerForScientist->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(allComputers[i].getType())));
        ui->tableWidget_Addscientist_selectComputerForScientist->setItem(i, 2, new QTableWidgetItem(QString::number(allComputers[i].getID())));
        ui->tableWidget_Addscientist_selectComputerForScientist->setColumnHidden(2,true);//Hide our ID column
    }
}
int AddComputerScientist::getCurrentYear()
{
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;
    return year;
}
void AddComputerScientist::initValidationData()
{
    // Validation for year of birth & year of death
    // the parameters are (lowest number, highest number)
    yearValidator = new QIntValidator(1,getCurrentYear());
    // here the validation is set to both: yearofbirth and deathyear fields
    // more info on this in the extra features document
    ui->lineEdit_Addscientist_yearofbirth->setValidator(yearValidator);
    ui->lineEdit_Addscientist_deathYear->setValidator(yearValidator);
}

void AddComputerScientist::saveComputersIDs()
{
    // This clears the computer vector
    _computersConnected.clear();
    QItemSelectionModel *select = ui->tableWidget_Addscientist_selectComputerForScientist->selectionModel();

    for(int i = 0; i < select->selectedRows(2).count(); i++)//SelectedRows(2) = the ID column
    {
        int computerID = select->selectedRows(2).value(i).data().toInt();
        _computersConnected.push_back(computerID);
    }
}
QString AddComputerScientist::getGender()
{
    QString gender;
    if(ui->radioButton_Addscientist_male->isChecked())
    {
        gender = "Male";
    }
    if(ui->radioButton_Addscientist_female->isChecked())
    {
        gender = "Female";
    }
    if(ui->radioButton_Addscientist_otherGender->isChecked())
    {
        gender = "Other";
    }
    return gender;
}
void AddComputerScientist::on_pushButton_Addscientist_save_clicked()
{

    // Clear the error messages
    ui->Add_Scientist_error_field->clear();
    ui->label_addScientist_invalidDeathYear->clear();

    //Save selected computers that are connected to the computer scientist.
    saveComputersIDs();

    // If validation fails these are used
    bool nameFail = false;
    bool genderFail = false;
    bool birthYearFail = false;
    bool deathYearFail = false;

    // Invalid year of death in context with year of birth
    bool deathYearInvalid = false;

    // If validation fails this is set as false
    bool canCreatePerson = true;

    // TODO Taka inn mynd

    QString name = ui->lineEdit_Addscientist_name->text();
    QString birthYear = ui->lineEdit_Addscientist_yearofbirth->text();
    QString comment = ui->lineEdit_Addscientist_comment->toPlainText();
    QString gender = getGender();
    QString deathYear;
    bool isAlive = ui->checkBox_Addscientist_isPersonAlive->isChecked();

    if(isAlive)
    {
        // If the person is still alive deathYear is set to 0
        deathYear = "0";
    }
    else
    {
        deathYear = ui->lineEdit_Addscientist_deathYear->text();
    }

    // Validations
    if(name == "")
    {
        canCreatePerson = false;
        nameFail = true;
    }

    if(birthYear == "")
    {
        canCreatePerson = false;
        birthYearFail = true;
    }

    if(isAlive == false && deathYear == "")
    {
        canCreatePerson = false;
        deathYearFail = true;
    }

    if(birthYear >= deathYear && isAlive == false)
    {
        canCreatePerson = false;
        deathYearInvalid = true;
    }

    if(gender == "")
    {
        canCreatePerson = false;
        genderFail = true;
    }

    // If canCreatePerson is true, the person can be created
    if(canCreatePerson)
    {
        CSPerson newPerson;
        _newPerson = newPerson;
        //on_pushButton_Addscientist_clearFields_clicked;
        _newPerson.setName(name.toStdString());
        _newPerson.setGender(gender.toStdString());
        _newPerson.setBirthYear(birthYear.toInt());
        _newPerson.setComment(comment.toStdString());
        _newPerson.setIsAlive(isAlive);
        _newPerson.setPassedAwayYear(deathYear.toInt());

        //TODO save image.
        this->setResult(QDialog::Accepted);
        clearFields();
    }
    else
    {
        QString initial = "The following fields are missing: ";
        QString errorMessage = validateUserInput(nameFail, genderFail, birthYearFail, deathYearFail);
        ui->Add_Scientist_error_field->setText(initial + "<span style = 'color : red'>" + errorMessage + "</span>");

        if(deathYearInvalid)
        {
            QString message = "Invalid year of death";
            ui->label_addScientist_invalidDeathYear->setText("<span style = 'color : red'>" + message + "</span>");

        }
        this->setResult(QDialog::Rejected);
    }
}

// This function creates the error string for: on_pushButton_Addscientist_save_clicked()
QString AddComputerScientist::validateUserInput(bool nameFail, bool genderFail, bool birthYearFail, bool deathYearFail)
{
    QString errorString = "";

    if(nameFail == true)
    {
        errorString += "* Name *";
    }
    if(genderFail == true)
    {
        errorString += "* Gender *";
    }
    if(birthYearFail == true)
    {
        errorString += "* Year of birth *";
    }
    if(deathYearFail == true)
    {
        errorString += "* Year of death *";
    }

    return errorString;
}


void AddComputerScientist::on_checkBox_Addscientist_isPersonAlive_toggled(bool checked)
{
    // If checkbox is checked then it is not possible to edit the year of death field
    if(checked)
    {
        ui->label_deathYear->setDisabled(constants::ENABLED);
        ui->lineEdit_Addscientist_deathYear->setDisabled(constants::ENABLED);
    }
    else
    {
        ui->label_deathYear->setEnabled(constants::ENABLED);
        ui->lineEdit_Addscientist_deathYear->setEnabled(constants::ENABLED);
    }
}

void AddComputerScientist::on_pushButton_browse_clicked()
{
    /*QByteArray inByteArray;
    QFile file("test.jpg");
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "nadi að opna file";
        inByteArray = file.readAll();
    }*/

         //Here user has selected a file
        //QPixmap pixmap(QString::fromStdString(filePath));
        //ui->AddScientist_pushButton_image->setPixmap(pixmap);


    /*vector<CSPerson> tempList;
    tempList = _service.getComputerScientistList();
    _csMoreInfo.setModal(true);
    _csMoreInfo.setComputerScientist(tempList[0]);
    _csMoreInfo.exec();

    QByteArray inByteArray = myPerson.getImage();*/

    /*QPixmap outPixmap = QPixmap();
    outPixmap.loadFromData( inByteArray );*/


    // NEXT TWO LINES DO NOT WORK ON MAC???? DON'T KNOW WHY
    //ui->TESTEST->setPixmap(outPixmap);
    //ui->TESTEST->setScaledContents(true);
    //ui->AddScientist_pushButton_image->show();
}

void AddComputerScientist::on_pushButton_Addscientist_clearFields_clicked()
{
    // Clear the input fields
    ui->lineEdit_Addscientist_name->clear();
    ui->lineEdit_Addscientist_yearofbirth->clear();
    ui->lineEdit_Addscientist_comment->clear();
    ui->lineEdit_Addscientist_deathYear->clear();

    // Is alive checkbox is checked by default
    ui->checkBox_Addscientist_isPersonAlive->setChecked(true);
    // Table selection clear
    ui->tableWidget_Addscientist_selectComputerForScientist->clearSelection();

    // Radio buttons clear
    ui->radioButton_Addscientist_female->setAutoExclusive(false);
    ui->radioButton_Addscientist_male->setAutoExclusive(false);
    ui->radioButton_Addscientist_otherGender->setAutoExclusive(false);
    ui->radioButton_Addscientist_female->setChecked(false);
    ui->radioButton_Addscientist_male->setChecked(false);
    ui->radioButton_Addscientist_otherGender->setChecked(false);
    ui->radioButton_Addscientist_female->setAutoExclusive(true);
    ui->radioButton_Addscientist_male->setAutoExclusive(true);
    ui->radioButton_Addscientist_otherGender->setAutoExclusive(true);

}

void AddComputerScientist::clearFields()
{
    // Clear the input fields
    ui->lineEdit_Addscientist_name->clear();
    ui->lineEdit_Addscientist_yearofbirth->clear();
    ui->lineEdit_Addscientist_comment->clear();
    ui->lineEdit_Addscientist_deathYear->clear();

    // Is alive checkbox is checked by default
    ui->checkBox_Addscientist_isPersonAlive->setChecked(true);
    // Table selection clear
    ui->tableWidget_Addscientist_selectComputerForScientist->clearSelection();

    // Radio buttons clear
    ui->radioButton_Addscientist_female->setAutoExclusive(false);
    ui->radioButton_Addscientist_male->setAutoExclusive(false);
    ui->radioButton_Addscientist_otherGender->setAutoExclusive(false);
    ui->radioButton_Addscientist_female->setChecked(false);
    ui->radioButton_Addscientist_male->setChecked(false);
    ui->radioButton_Addscientist_otherGender->setChecked(false);
    ui->radioButton_Addscientist_female->setAutoExclusive(true);
    ui->radioButton_Addscientist_male->setAutoExclusive(true);
    ui->radioButton_Addscientist_otherGender->setAutoExclusive(true);
}



