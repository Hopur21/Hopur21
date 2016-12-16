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
    ui->computer_type_input->setText(QString::fromStdString(_myComputer.getType()));
    ui->year_of_design_input->setText(QString::number(_myComputer.getDesignYear()));
    ui->year_of_build_input->setText(QString::number(_myComputer.getBuildYear()));
    ui->computer_name_input->setText(QString::fromStdString(_myComputer.getName()));

    loadImage();
}
void compmoreinfo::showCreatorsofComputer()
{
    std::string output;
    for(unsigned int i = 0; i < _myCreators.size(); i++)
    {
        output += _myCreators[i].getName();
        if(i+1 < _myCreators.size())
        {
            output = output + ",  ";
        }
    }
    ui->associated_input->setText(QString::fromStdString(output));
}

void compmoreinfo::loadImage()
{
    QPixmap pixmap = QPixmap();
    pixmap.loadFromData( _myComputer.getImage() );
    QIcon buttonIcon(pixmap);
    ui->computer_image_input->setIcon(buttonIcon);
}

void compmoreinfo::setComputer(Computer myComputer)
{
    _myComputer = myComputer;
    setDataInBoxes();
}
void compmoreinfo::setComputerCreators(vector<CSPerson> myCreators)
{
    _myCreators = myCreators;
    showCreatorsofComputer();
}

void compmoreinfo::on_pushButton_clicked()
{
    this->close();
}
