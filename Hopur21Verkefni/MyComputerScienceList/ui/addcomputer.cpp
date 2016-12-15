#include "addcomputer.h"
#include "ui_addcomputer.h"
#include <QTextEdit>

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);

    // getCurrent year   (year is the current year)
    // therefore in the year 2016 the variable year becomes 2016
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;

    // Validation for year of design and year of build
    // the parameters are (lowest number, highest number)
    yearValidator = new QIntValidator(1,year);
    // here the validation is set to both: yearofdesign and yearofbuild fields
    // more info on this in the extra features document
    ui->lineEdit_AddComputer_designYear->setValidator(yearValidator);
    ui->lineEdit_AddComputer_buildYear->setValidator(yearValidator);
}

AddComputer::~AddComputer()
{
    delete yearValidator;
    delete ui;
}

void AddComputer::on_pushButton_AddComputer_saveComputer_clicked()
{
    // clear the error messages
    ui->AddComputer_ErrorMessage->clear();
    ui->AddComputer_InvalidBuildYear->clear();

    // If validation fails these are used
    bool nameFail = false;
    bool designYearFail = false;
    bool buildYearFail = false;

    // invalid build year in context with design year
    bool buildYearInvalid = false;

    // If validation fails this is set as false
    bool canCreateComputer = true;

    QString name = "";
    QString comment = "";
    QString designYear = "";
    QString buildYear = "";

    // isBuilt is connected to the checkbox
    bool isBuilt;

    name = ui->lineEdit_AddComputer_nameComputer->text();
    designYear = ui->lineEdit_AddComputer_designYear->text();
    comment = ui->plainTextEdit_AddComputer_commentsComputer->toPlainText();
    isBuilt = ui->checkBox_AddComputer_wasComputerBuilt->isChecked();

    if(isBuilt == false)
    {
        // If the computer was never built then buildYear is set to 0
        buildYear = "0";
    }
    else if(isBuilt == true)
    {
        buildYear = ui->lineEdit_AddComputer_buildYear->text();
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

    // If canCreatePerson is true, the person can be created
    if(canCreateComputer == true)
    {

        //Computer createdComputer;
        //_newPerson = createdPerson;
        //setResult(QDialog::Accepted);
    }
    else
    {

    }
}
// This function creates the error string for: on_pushButton_Addscientist_save_clicked()
QString AddComputer::validateUserInput(bool nameFail, bool designYearFail, bool buildYearFail)
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
    if(buildYearFail == true)
    {
        errorString += "* Build year *";
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
    else
    {
        ui->checkBox_AddComputer_wasComputerBuilt->setChecked(constants::DISABLED);
        ui->label_buildYear->setDisabled(constants::ENABLED);
        ui->lineEdit_AddComputer_buildYear->setDisabled(constants::ENABLED);
    }
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
    ui->plainTextEdit_AddComputer_commentsComputer->clear();
    ui->tableWidget_AddComputer_selectScientistForComputer->clearSelection();
}

void AddComputer::on_pushButton_AddComputer_clearFields_clicked()
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
    ui->plainTextEdit_AddComputer_commentsComputer->clear();
    ui->tableWidget_AddComputer_selectScientistForComputer->clearSelection();
}
