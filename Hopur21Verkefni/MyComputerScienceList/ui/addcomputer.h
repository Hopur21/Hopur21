#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "models/csperson.h"
#include "models/computer.h"

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

private slots:
    void on_pushButton_saveComputer_clicked();

    void on_checkBox_wasComputerBuilt_clicked(bool checked);

private:
    Ui::AddComputer *ui;
};

#endif // ADDCOMPUTER_H
