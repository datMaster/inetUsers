#include "adddialog.hpp"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) : QDialog(parent), ui(new Ui::addDialog)
{
    ui->setupUi(this);
    dataBase = new mDB();
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::on_pushButton_clicked()
{
    dataBase->createElement(ui->lineEdit_fname->text(), ui->lineEdit_lName->text(), ui->lineEdit_mac_1->text(),
                           ui->lineEdit_mac_2->text(), ui->lineEdit_mac_3->text(), ui->lineEdit_mac_4->text(),
                           ui->lineEdit_mac_5->text(), ui->lineEdit_icq->text(), ui->lineEdit_skype->text(),
                           ui->lineEdit_room->text(), ui->lineEdit_tel->text());
}
