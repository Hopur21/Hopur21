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
    setDataInBoxes();
    _myPerson = myPerson;
    qDebug() << "CHRISTMAS FUNCTION";

    //QString test = QString::fromStdString(myPerson.getName());
    //qDebug() << test;

    // Set the name of the person

    //ui->name_input->setText(test);

    //ui->name_input->setText(QString::fromStdString(myPerson.getName()));
    // Set the birth year of the person
    //ui->yearOfBirth_input->setText(QString::number(myPerson.getBirthYear()));
    // Set the year of death of the person
    //ui->yearOfDeath_input->setText(QString::number(myPerson.getPassedAwayYear()));
    // Set the age of the person
    //int age = myPerson.getAge();
    //if(age == constants::STILL_ALIVE)
    //{
     //  ui->age_input->setText("Still alive");
    //}
    //else
    //{
    //    ui->age_input->setText(QString::number(myPerson.getAge()));
    //}




    // Alternatively, load an image file directly into a QByteArray
    /*QFile file("test.jpg");
    if (file.open(QIODevice::ReadOnly))
    {
        qDebug() << "nadi að opna file";
    }
    QByteArray inByteArray = myPerson.getImage();

       QPixmap outPixmap = QPixmap();
       outPixmap.loadFromData( inByteArray );*/

       /*
       ui->showPicLabel->setPixmap(outPixmap);
       ui->showPicLabel->setScaledContents(true);
       ui->showPicLabel->show();
    */


       /* To read from files
      QFile file("test.jpg");
      if (file.open(QIODevice::ReadOnly))
      {
          qDebug() << "nadi að opna file";
          QByteArray inByteArray = file.readAll();

      }


      vector<CSPerson> tempList;
      tempList = _service.getComputerScientistList();
      _csMoreInfo.setModal(true);
      _csMoreInfo.setComputerScientist(tempList[0]);
      _csMoreInfo.exec();

      */

       /*
       ui->label_title->setText(QString("<h2>%1</h2>").arg(QString::fromStdString(car.toString())));
       QPixmap pixmap(QString::fromStdString(car.getImagePath()));
       ui->label_image->setPixmap(pixmap);
       ui->label_image->setScaledContents(true);
       */



}
