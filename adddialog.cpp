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
    wfUser wu;
    //strcpy(wu.fName, "0000000000000000000000000000000");
    //strcpy(wu.lName, "0000000000000000000000000000000");
    strcpy(wu.fName, ui->lineEdit_fname->text().toStdString().c_str());
    strcpy(wu.lName, ui->lineEdit_lName->text().toStdString().c_str());
    strcpy(wu.mac1, ui->lineEdit_mac_1->text().toStdString().c_str());
    strcpy(wu.mac2, ui->lineEdit_mac_2->text().toStdString().c_str());
    strcpy(wu.mac3, ui->lineEdit_mac_3->text().toStdString().c_str());
    strcpy(wu.mac4, ui->lineEdit_mac_4->text().toStdString().c_str());
    strcpy(wu.mac5, ui->lineEdit_mac_5->text().toStdString().c_str());
    strcpy(wu.icq, ui->lineEdit_icq->text().toStdString().c_str());
    strcpy(wu.skype, ui->lineEdit_skype->text().toStdString().c_str());
    strcpy(wu.tel, ui->lineEdit_tel->text().toStdString().c_str());
//    copy(*wu.fName, ui->lineEdit_fname->text());
//    copy(*wu.lName, ui->lineEdit_lName->text());
//    copy(*wu.mac1, ui->lineEdit_mac_1->text());
//    copy(*wu.mac2, ui->lineEdit_mac_2->text());
//    copy(*wu.mac3, ui->lineEdit_mac_3->text());
//    copy(*wu.mac4, ui->lineEdit_mac_4->text());
//    copy(*wu.mac5, ui->lineEdit_mac_5->text());
//    copy(*wu.tel, ui->lineEdit_tel->text());
//    copy(*wu.icq, ui->lineEdit_icq->text());
//    copy(*wu.skype, ui->lineEdit_skype->text());
    wu.room = (int)ui->spinBox_room->value();
    wu.date = ui->calendarWidget->selectedDate();

    dataBase->createElement(wu);

//    dataBase->createElement(ui->lineEdit_fname->text().data(), ui->lineEdit_lName->text().data(), ui->lineEdit_mac_1->text().data(),
//                           ui->lineEdit_mac_2->text().data(), ui->lineEdit_mac_3->text().data(), ui->lineEdit_mac_4->text().data(),
//                           ui->lineEdit_mac_5->text().data(), ui->lineEdit_icq->text().data(), ui->lineEdit_skype->text().data(),
//                           (int)ui->spinBox_room->value(), ui->lineEdit_tel->text().data(), ui->calendarWidget->selectedDate());
}

void addDialog::on_pushButton_2_clicked()
{
    wfUser wwf;
    dataBase->getElementByName(ui->lineEdit_fname->text(), ui->lineEdit_lName->text(), wwf);
    ui->textEdit->append("fName : ");
    ui->textEdit->append(wwf.fName);
    ui->textEdit->append("lName : ");
    ui->textEdit->append(wwf.lName);
    ui->textEdit->append("mac1 : ");
    ui->textEdit->append(wwf.mac1);
}
