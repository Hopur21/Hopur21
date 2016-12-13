#ifndef SHOWTRASH_H
#define SHOWTRASH_H

#include <QDialog>

namespace Ui {
class ShowTrash;
}

class ShowTrash : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTrash(QWidget *parent = 0);
    ~ShowTrash();

private:
    Ui::ShowTrash *ui;
};

#endif // SHOWTRASH_H
