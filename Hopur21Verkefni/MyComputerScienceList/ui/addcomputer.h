#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "models/csperson.h"
#include "models/computer.h"
#include <QtAlgorithms> // for qSort
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
    void setComputersList(vector<Computer> allComputers);
    void setComputerScientistList(vector<CSPerson> allScientists);
private slots:

    void on_pushButton_AddComputer_saveComputer_clicked();
    void on_checkBox_AddComputer_wasComputerBuilt_toggled(bool checked);
    void on_pushButton_AddComputer_clearFields_clicked();

private:
    Ui::AddComputer *ui;
    QIntValidator *yearValidator;
    // ComboBox set
    void setComputerTypesComboBox(vector<Computer> allComputers);
};

#endif // ADDCOMPUTER_H
