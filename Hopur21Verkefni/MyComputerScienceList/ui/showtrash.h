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
    void listTrashCan();
    void setComputerScientistTrashList(vector<CSPerson> compScientist);

    ~ShowTrash();

private:

    Ui::ShowTrash *ui;
};

#endif // SHOWTRASH_H
