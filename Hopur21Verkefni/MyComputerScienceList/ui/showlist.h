#ifndef SHOWLIST_H
#define SHOWLIST_H

#include <QDialog>

namespace Ui {
class ShowList;
}

class ShowList : public QDialog
{
    Q_OBJECT

public:
    explicit ShowList(QWidget *parent = 0);
    ~ShowList();

private:
    Ui::ShowList *ui;
};

#endif // SHOWLIST_H