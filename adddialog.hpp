#ifndef ADDDIALOG_HPP
#define ADDDIALOG_HPP

#include <QDialog>
#include "mdb.hpp"

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::addDialog *ui;
    mDB *dataBase;
};

#endif // ADDDIALOG_HPP
