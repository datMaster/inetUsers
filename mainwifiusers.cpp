#include "mainwifiusers.hpp"
#include "ui_mainwifiusers.h"

mainWifiUsers::mainWifiUsers(QWidget *parent) : QMainWindow(parent),  ui(new Ui::mainWifiUsers)
{
    ui->setupUi(this);    
}

mainWifiUsers::~mainWifiUsers()
{
    delete ui;
}

void mainWifiUsers::on_actionADD_triggered()
{
    addDlg.show();
}
