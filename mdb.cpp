#include "mdb.hpp"

mDB::mDB()
{    
}

mDB::~mDB()
{
}

wfUser mDB::createUser()
{

    return userok;
}

void mDB::createElement(const QString &fName, const QString &lName, const QString &mac1,
                        const QString &mac2, const QString &mac3, const QString &mac4,
                        const QString &mac5, const QString &icq, const QString &skype,
                        const QString &room, const QString &tel)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("WIFIUsers");
    db.setUserName("root");
    db.setPassword("vfnfy pkj");
    bool op = db.open();
    if(!op)
    {
        QMessageBox mbz;
        mbz.setText("db !open.");
        mbz.exec();
    }


    userok.fName.push_back(fName);
    userok.lName.push_back(lName);
    userok.mac1.push_back(mac1);
    userok.mac2.push_back(mac2);
    userok.mac3.push_back(mac3);
    userok.mac4.push_back(mac4);
    userok.mac5.push_back(mac5);
    userok.icq.push_back(icq);
    userok.skype.push_back(skype);
    userok.room = room.toInt(0, 10);
    userok.tel.push_back(tel);

}

int mDB::serchElement(wfUser)
{
    return 0;
}

void mDB::addElement(wfUser)
{
}

void mDB::delElement()
{
}
