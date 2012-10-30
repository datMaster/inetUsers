#include "mainwifiusers.hpp"
#include "ui_mainwifiusers.h"

mainWifiUsers::mainWifiUsers(QWidget *parent) : QMainWindow(parent),  ui(new Ui::mainWifiUsers)
{
    ui->setupUi(this);
    setCentralWidget(ui->tableWidget_main);
    on_actionList_all_triggered();
}

mainWifiUsers::~mainWifiUsers()
{
    delete ui;
}

void mainWifiUsers::on_actionADD_triggered()
{
    addDlg.show();
}

void mainWifiUsers::on_actionList_all_triggered()
{
    vector<wfUser> users;
    mDB db;
    db.listAllUsers(users);

    clearTable();

    for(unsigned int i = 0; i < users.size(); ++ i)
    {
        ui->tableWidget_main->insertRow(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(wfUser(users[i]).fName);
        ui->tableWidget_main->setItem(i, 0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(wfUser(users[i]).lName);
        ui->tableWidget_main->setItem(i, 1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(wfUser(users[i]).room));
        ui->tableWidget_main->setItem(i, 2, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(wfUser(users[i]).date.toString("dd.MM.yyyy"));
        if(wfUser(users[i]).date <= QDate::currentDate())
            item4->setBackground(Qt::red);                    
        else                    
            item4->setBackground(Qt::green);        

        ui->tableWidget_main->setItem(i, 3, item4);

        QTableWidgetItem *item5 = new QTableWidgetItem(wfUser(users[i]).skype);
        ui->tableWidget_main->setItem(i, 4, item5);

        QTableWidgetItem *item6 = new QTableWidgetItem(wfUser(users[i]).icq);
        ui->tableWidget_main->setItem(i, 5, item6);

        QTableWidgetItem *item7 = new QTableWidgetItem(wfUser(users[i]).mac1);
        ui->tableWidget_main->setItem(i, 6, item7);

        QTableWidgetItem *item8 = new QTableWidgetItem(wfUser(users[i]).mac2);
        ui->tableWidget_main->setItem(i, 7, item8);

        QTableWidgetItem *item9 = new QTableWidgetItem(wfUser(users[i]).mac3);
        ui->tableWidget_main->setItem(i, 8, item9);

        QTableWidgetItem *item10 = new QTableWidgetItem(wfUser(users[i]).mac4);
        ui->tableWidget_main->setItem(i, 9, item10);

        QTableWidgetItem *item11 = new QTableWidgetItem(wfUser(users[i]).mac5);
        ui->tableWidget_main->setItem(i, 10, item11);
    }
}

void mainWifiUsers::clearTable()
{
    for(int i = ui->tableWidget_main->rowCount() - 1; i >= 0; -- i)
        ui->tableWidget_main->removeRow(i);
}

