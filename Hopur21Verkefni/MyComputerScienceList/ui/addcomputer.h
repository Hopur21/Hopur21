#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "models/csperson.h"
#include "models/computer.h"
#include "models/computertype.h"
#include "ui/csmoreinfo.h"

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    QString validateUserInput(bool nameFail, bool designYearFail, bool buildYearFail);
    ~AddComputer();
    //Sets
    void setComputerType(vector<ComputerType> computerTypes);
    void clearFields();
    //Gets
    //Gets
    Computer getComputer() {return _newComputer;}
    vector<int> getCSconntedToComp(){return _scientistsConnected;}
    QByteArray getImage(){return _image;}
    string getImageName(){return _imageName;}
    // ComboBox set
    void setComputerTypesComboBox();
    void setComputerScientistList(vector<CSPerson> allScientists);
    void resetData();

private slots:

    void on_pushButton_AddComputer_saveComputer_clicked();
    void on_checkBox_AddComputer_wasComputerBuilt_toggled(bool checked);
    void on_pushButton_AddComputer_clearFields_clicked();
    void on_comboBox_AddComputer_selectTypeOfComputer_highlighted(int index);
    void on_pushButton_AddComputer_browseComputer_clicked();
    void on_pushButton_imageComputer_clicked();
    void on_tableWidget_AddComputer_selectScientistForComputer_doubleClicked(const QModelIndex &index);

    void on_tableWidget_AddComputer_selectScientistForComputer_cellClicked(int row, int column);

private:
    Ui::AddComputer *ui;
    QIntValidator *yearValidator;
    CSMoreInfo _csMoreInfo;
    Computer _newComputer;
    vector<ComputerType> _listOfComputerTypes;
    vector<int> _scientistsConnected;
    // vector for more info
    vector<CSPerson> _listOfScientists;
    CSPerson _personToSend;
    QByteArray _image;
    string _imageName;
    int getCurrentYear();
    int _row;
    int _idForMoreInfo;
    void initValidationData(int year);
    CSPerson getPersonFromID(int id);
    void saveComputerScientistIDs();
    void clearErrorMessages();
    QString browseForFile();
    bool comvertAndSaveFile();
    void setImageButtonAsImage();
    QString validateUserInput(bool nameFail, bool designYearFail, bool buildYearFail, bool computerTypeFail, bool buildYearInvalid);

};

#endif // ADDCOMPUTER_H
