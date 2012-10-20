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

void mDB::listAllUsers(vector<wfUser> &uList)
{
    ifstream dbFile;
    dbFile.open("dbusers.bs", ios_base::in |ios_base::binary);
    if(!dbFile.is_open())
    {
        QMessageBox mbz;
        mbz.setText("db !open.");
        mbz.exec();
    }
    else
    {
        while(true)
        {
            wfUser wfU;
            for(int i = 0; i < 32; ++ i)
                wfU.fName[i] = 'x';
            if(!dbFile.read((char *)&wfU, sizeof(wfUser)))
                break;
            else
                uList.push_back(wfU);
        }
        dbFile.close();
    }
}

void mDB::createElement(const wfUser &wUs)
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
        dbFile.write((char *)&wUs, sizeof(wfUser));
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
