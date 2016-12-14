#include "addcomputer.h"
#include "ui_addcomputer.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);

}

AddComputer::~AddComputer()
{
    delete ui;
}

void AddComputer::on_pushButton_saveComputer_clicked()
{
    // clear the error messages
    //ui->Add_Scientist_error_field->clear();
    //ui->label_addScientist_invalidDeathYear->clear();

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

    name = ui->lineEdit_nameComputer->text();
    designYear = ui->lineEdit_designYear->text();
    comment = ui->lineEdit_commentsComputer->text();
    isBuilt = ui->checkBox_wasComputerBuilt->isChecked();

    if(isBuilt == true)
    {
        // If the computer was never built then buildYear is set to 0
        buildYear = "0";
    }
    else if(isBuilt == false)
    {
        buildYear = ui->lineEdit_buildYear->text();
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

    if(isBuilt == false && designYear == "")
    {
        canCreateComputer = false;
        buildYearFail = true;
    }

    if(designYear >= buildYear && isBuilt == false)
    {
        canCreateComputer = false;
        buildYearInvalid = true;
    }

    // If canCreatePerson is true, the person can be created
    if(canCreateComputer == true)
    {

        //CSPerson createdPerson;
        //_newPerson = createdPerson;
        //setResult(QDialog::Accepted);
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

void AddComputer::on_checkBox_wasComputerBuilt_clicked(bool checked)
{
    // If checkbox is checked then it is not possible to edit the year of death field
    if(checked)
    {
        ui->label_buildYear->setDisabled(constants::DISABLED);
        ui->lineEdit_buildYear->setDisabled(constants::DISABLED);
    }
    else
    {
        ui->label_buildYear->setEnabled(constants::ENABLED);
        ui->lineEdit_buildYear->setEnabled(constants::ENABLED);
    }
}
