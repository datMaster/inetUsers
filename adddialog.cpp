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
    delete dataBase;
}

void addDialog::on_pushButton_clicked()
{
    wfUser wu;

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
    wu.room = (int)ui->spinBox_room->value();
    wu.date = ui->calendarWidget->selectedDate();

    dataBase->createElement(wu);
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
