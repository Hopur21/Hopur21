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
    void displayScientists();
    void displayScientists(std::vector<CSPerson> CSPersons);


    ~ShowList();

private:
    Ui::ShowList *ui;
};

#endif // SHOWLIST_H
