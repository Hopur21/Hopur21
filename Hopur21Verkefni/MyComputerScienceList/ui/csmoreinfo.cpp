#include "csmoreinfo.h"
#include "ui_csmoreinfo.h"

CSMoreInfo::CSMoreInfo( QWidget *parent) : QDialog(parent), ui(new Ui::CSMoreInfo)
{
    ui->setupUi(this);
}

CSMoreInfo::~CSMoreInfo()
{
    delete ui;
}

void CSMoreInfo::setDataInBoxes()
{

    ui->more_info_input->setText(QString::fromStdString(_myPerson.getComments()));
    ui->name_input->setText(QString::fromStdString(_myPerson.getName()));
    ui->age_input->setText(QString::number(_myPerson.getAge()) );
    ui->label_yearOfDeath->setText(QString::number(_myPerson.getPassedAwayYear()));
    ui->yearOfBirth_input->setText(QString::number(_myPerson.getBirthYear()));
    ui->yearOfDeath_input->setText(QString::number(_myPerson.getPassedAwayYear()));
    loadImage();
}
void CSMoreInfo::loadImage()
{
    QPixmap pixmap = QPixmap();
    pixmap.loadFromData( _myPerson.getImage() );
    QIcon buttonIcon(pixmap);
    ui->image_of_person_input->setIcon(buttonIcon);
}

void CSMoreInfo::setComputerScientist(CSPerson myPerson)
{
     _myPerson = myPerson;
    setDataInBoxes();
}
