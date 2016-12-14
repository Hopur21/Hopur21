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

    ~ShowList();

private:
    Ui::ShowList *ui;
};

#endif // SHOWLIST_H
