#include "addcomputerscientist.h"
#include "ui_addcomputerscientist.h"

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
    QIntValidator *yearValidator = new QIntValidator(0,year);
    ui->lineEdit_Addscientist_yearofbirth->setValidator(yearValidator);
    ui->lineEdit_Addscientist_deathYear->setValidator(yearValidator);

}

AddComputerScientist::~AddComputerScientist()
{
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

    // Gender options
    bool male = false;
    bool female = false;
    bool other = false;

    QString name = "";
    QString comment = "";
    QString birthYear = "";
    QString deathYear = "";
    QString gender = "";

    // isAlive is connected to the checkbox
    bool isAlive;


    // Taka inn mynd

    name = ui->lineEdit_Addscientist_name->text();
    birthYear = ui->lineEdit_Addscientist_yearofbirth->text();
    comment = ui->lineEdit_Addscientist_comment->text();
    isAlive = ui->checkBox_Addscientist_isPersonAlive->isChecked();

    if(isAlive == true)
    {
        qDebug() << "This person is still alive";
    }
    else if(isAlive == false)
    {
        deathYear = ui->lineEdit_Addscientist_deathYear->text();
    }

    if(ui->radioButton_Addscientist_male->isChecked())
    {
        gender = "Male";
        qDebug() << "Gender selected Male";
    }
    if(ui->radioButton_Addscientist_female->isChecked())
    {
        gender = "Female";
        qDebug() << "Gender selected Female";
    }
    if(ui->radioButton_Addscientist_otherGender->isChecked())
    {
        gender = "Other";
        qDebug() << "Gender selected Other";
    }

    // Validations

    if(name == "" || birthYear == "")
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


    // 1 denotes success 0 denotes failure
    if(canCreatePerson == true)
    {
        CSPerson createdPerson;
        _newPerson = createdPerson;
        //setResult(QDialog::Accepted);
    }
    else
    {
        //setResult(QDialog::Rejected);
    }


}
