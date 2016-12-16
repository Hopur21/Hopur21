#include "compmoreinfo.h"
#include "ui_compmoreinfo.h"

//Was accidentally created with only lowercase, we got many conflicts trying to fix it.

compmoreinfo::compmoreinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compmoreinfo)
{
    ui->setupUi(this);
}

compmoreinfo::~compmoreinfo()
{
    delete ui;
}

void compmoreinfo::setDataInBoxes()
{
    /*
    ui->more_info_input->setText(QString::fromStdString(_myPerson.getComments()));
    ui->name_input->setText(QString::fromStdString(_myPerson.getName()));
    ui->age_input->setText(QString::number(_myPerson.getAge()) );
    ui->label_yearOfDeath->setText(QString::number(_myPerson.getPassedAwayYear()));
    ui->yearOfBirth_input->setText(QString::number(_myPerson.getBirthYear()));
    ui->yearOfDeath_input->setText(QString::number(_myPerson.getPassedAwayYear()));
    loadImage();
    */

}
void compmoreinfo::loadImage()
{
    QPixmap pixmap = QPixmap();
    pixmap.loadFromData( _myComputer.getImage() );
    QIcon buttonIcon(pixmap);
    //ui->image->setIcon(buttonIcon);
}

void compmoreinfo::setComputer(Computer myComputer)
{
    _myComputer = myComputer;
    setDataInBoxes();
}
