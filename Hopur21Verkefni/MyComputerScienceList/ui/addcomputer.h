#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "models/csperson.h"
#include "models/computer.h"
#include "models/computertype.h"
#include <QDialog>

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
    void clearFields();
    // ComboBox set
    void setComputerTypesComboBox(vector<ComputerType> allComputerTypes);
    void setComputerScientistList(vector<CSPerson> allScientists);
    void resetData();
private slots:

    void on_pushButton_AddComputer_saveComputer_clicked();
    void on_checkBox_AddComputer_wasComputerBuilt_toggled(bool checked);
    void on_pushButton_AddComputer_clearFields_clicked();


    void on_comboBox_AddComputer_selectTypeOfComputer_highlighted(int index);

private:
    Ui::AddComputer *ui;
    QIntValidator *yearValidator;
    vector<ComputerType> _listOfComputerTypeIDs;
    vector<int> _scientistsConnected;
    int getCurrentYear();
    void initValidationData(int year);
    void saveComputerScientistIDs();
    QString validateUserInput(bool nameFail, bool designYearFail, bool buildYearFail, bool computerTypeFail, bool buildYearInvalid);


};

#endif // ADDCOMPUTER_H
