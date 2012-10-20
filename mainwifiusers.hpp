#ifndef MAINWIFIUSERS_HPP
#define MAINWIFIUSERS_HPP

#include <QMainWindow>
#include "adddialog.hpp"
#include "mdb.hpp"

namespace Ui {
class mainWifiUsers;
}

class mainWifiUsers : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit mainWifiUsers(QWidget *parent = 0);
    ~mainWifiUsers();
    
private slots:
    void on_actionADD_triggered();     
    void on_actionList_all_triggered();
    void clearTable();

private:
    Ui::mainWifiUsers *ui;
    addDialog addDlg;
};

#endif // MAINWIFIUSERS_HPP
