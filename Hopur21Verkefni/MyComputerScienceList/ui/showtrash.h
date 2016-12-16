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
        int getCSidToRestore(){return _computerScientistToRestore;}
        int getComputerIDToRestore(){return _computerToRestore;}
        bool getCompOrScientistToRestore(){return _computerOrScientistToRemove;}
        ~ShowTrash();

    private slots:
        void on_table_trashComputerScientist_cellClicked(int row);
        void on_Button_Restore_Computer_Scientist_clicked();
        void on_Button_Restore_Computer_clicked();
        void on_table_trashComputer_cellClicked(int row);

    private:
        vector<Computer> _computerList;
        vector<CSPerson> _CSList;
        int _compuerScientistRowSelected;
        int _computerScientistToRestore;
        int _compuerRowSelected;
        int _computerToRestore;
        bool _computerOrScientistToRemove;
        void printComputerTrash();
        void printComputerScientistTrash();
        void disableButtons();
        Ui::ShowTrash *ui;
};

#endif // SHOWTRASH_H
