#include "addcomputerscientist.h"
#include "ui_addcomputerscientist.h"
#include <QFileDialog>


AddComputerScientist::AddComputerScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerScientist)
{
    ui->setupUi(this);

    // getCurrent year   (year is the currentyear)
    time_t timeNow = time(0);
    tm *ltm = localtime(&timeNow);
    int year = ltm->tm_year + 1900;

    // Validation for year of birth & year of death
    // the parameters are (lowest number, highest number)
    yearValidator = new QIntValidator(1,year);
    // here the validation is set to both: yearofbirth and deathyear fields
    // more info in extra features document
    ui->lineEdit_Addscientist_yearofbirth->setValidator(yearValidator);
    ui->lineEdit_Addscientist_deathYear->setValidator(yearValidator);

}

AddComputerScientist::~AddComputerScientist()
{
    delete yearValidator;
    delete ui;
}

void AddComputerScientist::on_pushButton_Addscientist_save_clicked()
{
    // If validation fails these are used
    bool nameFail = false;
    bool genderFail = false;
    bool birthYearFail = false;
    bool deathYearFail = false;

    // If validation fails this is set as false
    bool canCreatePerson = true;

    QString name = "";
    QString comment = "";
    QString birthYear = "";
    QString deathYear = "";
    QString gender = "";

    // isAlive is connected to the checkbox
    bool isAlive;

    // TODO Taka inn mynd

    name = ui->lineEdit_Addscientist_name->text();
    birthYear = ui->lineEdit_Addscientist_yearofbirth->text();
    comment = ui->lineEdit_Addscientist_comment->text();
    isAlive = ui->checkBox_Addscientist_isPersonAlive->isChecked();

    if(isAlive == true)
    {
        // If the person is still alive deathYear is set to 0
        deathYear = "0";
    }
    else if(isAlive == false)
    {
        deathYear = ui->lineEdit_Addscientist_deathYear->text();
    }

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

    if(gender == "")
    {
        canCreatePerson = false;
        genderFail = true;
    }

    // If canCreatePerson is true, the person can be created
    if(canCreatePerson == true)
    {
        CSPerson createdPerson;
        _newPerson = createdPerson;
        //setResult(QDialog::Accepted);
    }
    else
    {
        QString initial = "The following fields are missing: ";
        QString errorMessage = "";
        errorMessage = validateUserInput(nameFail, genderFail, birthYearFail, deathYearFail);
        ui->Add_Scientist_error_field->clear();
        ui->Add_Scientist_error_field->setText(initial + "<span style = 'color : red'>" + errorMessage + "</span>");

        //setResult(QDialog::Rejected);
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
        ui->label_deathYear->setDisabled(constants::DISABLED);
        ui->lineEdit_Addscientist_deathYear->setDisabled(constants::DISABLED);
    }
    else
    {
        ui->label_deathYear->setEnabled(constants::ENABLED);
        ui->lineEdit_Addscientist_deathYear->setEnabled(constants::ENABLED);
    }
}

void AddComputerScientist::on_pushButton_browse_clicked()
{
    /*QString filePath = QFileDialog::getOpenFileName(this, "Search for images", "", "Image files (*.png *.jpg)").toStdString();
    if(filePath.length())
    {
        // Here user has selected a file
        QPixmap pixmap(QString::fromStdString(filePath));
        ui->AddScientist_pushButton_image->setPi




    }*/




}

void AddComputerScientist::on_pushButton_Addscientist_clearFields_clicked()
{
    ui->lineEdit_Addscientist_name->clear();
    ui->lineEdit_Addscientist_yearofbirth->clear();
    ui->lineEdit_Addscientist_comment->clear();
    ui->lineEdit_Addscientist_deathYear->clear();
}
