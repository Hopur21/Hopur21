#ifndef ADDCOMPUTERSCIENTIST_H
#define ADDCOMPUTERSCIENTIST_H
#include "models/csperson.h"
#include "models/computer.h"

/*
#include <QIntValidator>
#include <QPixmap>
#include <QFileDialog>
#include <QLabel>
*/

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
    void setComputersList(vector<Computer> allComputers);
    void clearFields();

private slots:
    void on_checkBox_Addscientist_isPersonAlive_toggled(bool checked);
    void on_pushButton_browse_clicked();
    void on_pushButton_Addscientist_clearFields_clicked();
    void on_pushButton_Addscientist_save_clicked();
private:
    //Ui::AddComputerScientist *ui;
    CSPerson _newPerson;
    // The computers the newly created scientist is connected to
    vector <int> _computersConnected;
    QIntValidator *yearValidator;
    CSPerson getPerson() {return _newPerson;}
    int getCurrentYear();
    void initValidationData();
    void saveComputersIDs();
    QString getGender();

};

#endif // ADDCOMPUTERSCIENTIST_H
