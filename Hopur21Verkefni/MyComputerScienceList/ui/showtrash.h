#ifndef SHOWTRASH_H
#define SHOWTRASH_H
#include "models/computer.h"
#include "models/csperson.h"

#include <QTableWidget>

#include <QDialog>

namespace Ui {
class ShowTrash;
}

class ShowTrash : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTrash(QWidget *parent = 0);
    void setTrashList(vector<CSPerson> compScientist, vector<Computer> computerTrashList);
    ~ShowTrash();

private slots:
    void on_lineEdit_searchScientistInTrashListView_textEdited(const QString &arg1);

private:
    vector<Computer> _computerList;
    vector<CSPerson> _CSList;
    void printComputerTrash();
    void printComputerScientistTrash();
    Ui::ShowTrash *ui;
};

#endif // SHOWTRASH_H
