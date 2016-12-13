#ifndef SHOWLISTS_H
#define SHOWLISTS_H

#include <QDialog>

namespace Ui {
class ShowLists;
}

class ShowLists : public QDialog
{
    Q_OBJECT

public:
    explicit ShowLists(QWidget *parent = 0);
    ~ShowLists();

private:
    Ui::ShowLists *ui;
};

#endif // SHOWLISTS_H
