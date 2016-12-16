#ifndef ADDCOMPUTERSCIENTIST_H
#define ADDCOMPUTERSCIENTIST_H
#include "models/csperson.h"
#include "models/computer.h"
#include "models/computerscientisttocomputer.h"

namespace Ui {
class AddComputerScientist;
}

class AddComputerScientist : public QDialog
{
    Q_OBJECT

    public:
        explicit AddComputerScientist(QWidget *parent = 0);
        ~AddComputerScientist();
        Ui::AddComputerScientist *ui;
        QString validateUserInput(bool nameFail, bool genderFail, bool birthYearFail, bool deathYearFail);
        void setComputersList(vector<Computer> allComputers, vector<ComputerScientistToComputer> computerCSconnection);
        void clearFields();
        void resetAllData();
        //Gets
        CSPerson getPerson() {return _newPerson;}
        vector<int> getComputersConnected(){return _computersConnected;}
        QByteArray getImage(){return _image;}
        string getImageName(){return _imageName;}

    private slots:
        void on_checkBox_Addscientist_isPersonAlive_toggled(bool checked);
        void on_pushButton_browse_clicked();
        void on_pushButton_Addscientist_clearFields_clicked();
        void on_pushButton_Addscientist_save_clicked();
        void on_AddScientist_pushButton_image_clicked();

    private:
        CSPerson _newPerson;
        // The computers the newly created scientist is connected to
        vector <int> _computersConnected;
        vector<ComputerScientistToComputer> _computerCSconnection;
        QIntValidator *yearValidator;
        QByteArray _image;
        string _imageName;
        int getCurrentYear();
        void initValidationData();
        void saveComputersIDs();
        void setImageButtonAsImage();
        bool comvertAndSaveFile();
        QString browseForFile();
        QString getGender();
};

#endif // ADDCOMPUTERSCIENTIST_H
