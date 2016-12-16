#ifndef SHOWLIST_H
#define SHOWLIST_H
#include "models/csperson.h"
#include "services/service.h"

#include <QDialog>

namespace Ui {
class ShowList;
}

class ShowList : public QDialog
{
    Q_OBJECT

public:
    explicit ShowList(QWidget *parent = 0);
    void setList(vector<CSPerson> computerScientistlist, vector<Computer> computerList);
    int getIdToRemove(){return _idToRemove;}
    bool getIfToRemoveComputer(){return _removeComputerOrScientist;}

    ~ShowList();

private slots:
    void on_Button_Delete_clicked();
    void on_tabWidget_scientist_currentChanged(int index);
    void on_table_Computer_cellClicked(int row);
    void on_table_ComputerScientist_cellClicked(int row);

private:
    vector<Computer> _computerList;
    vector<CSPerson> _CSlist;
    bool _removeComputerOrScientist;
    int _row;
    int _idToRemove;
    void printComputerList();
    void printComputerScientistList();
    Ui::ShowList *ui;
};

#endif // SHOWLIST_H
