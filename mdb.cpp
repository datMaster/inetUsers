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
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("WIFIUsers");
//    db.setUserName("root");
//    db.setPassword("vfnfy pkj");
//    bool op = db.open();
//    if(!op)
//    {
//        QMessageBox mbz;
//        mbz.setText("db !open.");
//        mbz.exec();
//    }


    ofstream dbFile;
    dbFile.open("dbusers.bs", ios_base::app |ios_base::binary);
    if(!dbFile.is_open())
    {
        QMessageBox mbz;
        mbz.setText("db !open.");
        mbz.exec();
    }
    else
    {
        strcpy(userok.fName, (char*)fName.toStdString().c_str());
        strcpy(userok.fName, (char*)fName.toStdString().c_str());
        strcpy(userok.lName, (char*)lName.toStdString().c_str());
        strcpy(userok.mac1, (char*)mac1.toStdString().c_str());
        strcpy(userok.mac2, (char*)mac2.toStdString().c_str());
        strcpy(userok.mac3, (char*)mac3.toStdString().c_str());
        strcpy(userok.mac4, (char*)mac4.toStdString().c_str());
        strcpy(userok.mac5, (char*)mac5.toStdString().c_str());
        strcpy(userok.icq, (char*)icq.toStdString().c_str());
        strcpy(userok.skype, (char*)skype.toStdString().c_str());
        userok.room = room.toInt(0, 10);
        strcpy(userok.tel, (char*)tel.toStdString().c_str());

        cout << "userok : " << userok.fName << endl;

        dbFile.write((char *)&userok, sizeof(wfUser));
        dbFile.close();
    }

}

int mDB::serchElement(wfUser)
{
    return 0;
}

void mDB::getElementByName(const QString &fName, const QString &lName, wfUser &wfU)
{
    fstream dbFile;
    dbFile.open("dbusers.bs", ios_base::in|ios_base::binary);
    if(!dbFile.is_open())
    {
        QMessageBox mbz;
        mbz.setText("db !open.");
        mbz.exec();
    }
    else
    {
        while(dbFile.read((char *)&wfU, sizeof(wfUser)))
        {
            if((fName.contains(wfU.fName, Qt::CaseSensitive)) && (lName.contains(wfU.lName, Qt::CaseSensitive)))
                break;
        }

        dbFile.close();
    }

}

void mDB::addElement(wfUser)
{
}

void mDB::delElement()
{
}
