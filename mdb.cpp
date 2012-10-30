#include "mdb.hpp"

mDB::mDB()
{
}

mDB::~mDB()
{
}

void mDB::listAllUsers(vector<wfUser> &uList)
{
    if(openDBreadOnly())
    {
        while(true)
        {
            wfUser wfU;            
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
    if(serchElement(wUs) == -1)
    {
        if(openDB_w_app())
        {
            dbFile.write((char *)&wUs, sizeof(wfUser));
            dbFile.close();
        }
    }
    else
        printError("Already exist.");
}

int mDB::serchElement(const wfUser &sElement)
{
    if(openDBreadOnly())
    {
        wfUser wfU;
        while(dbFile.read((char *)&wfU, sizeof(wfUser)))
        {
            if(wfU == sElement)
                return dbFile.tellp();
        }
        dbFile.close();
    }
    return -1;
}

bool mDB::openDBreadOnly()
{
    dbFile.open("dbusers.bs", ios_base::in | ios_base::binary);
    return DBFileIsOpen();
}

bool mDB::DBFileIsOpen()
{
    if(dbFile.is_open())
        return true;
    printError("DB-file not open.");
    return false;
}

bool mDB::openDBwrite()
{
    dbFile.open("dbusers.bs", ios_base::out | ios_base::binary);
    return DBFileIsOpen();
}


bool mDB::openDB_w_app()
{
    dbFile.open("dbusers.bs", ios_base::out | ios_base::app | ios_base::binary);
    return DBFileIsOpen();
}

void mDB::printError(const char *mess)
{
    QMessageBox mbz;
    mbz.setWindowTitle("Error");
    mbz.setText(mess);
    mbz.exec();
}

void mDB::getElementByName(const QString &fName, const QString &lName, wfUser &wfU)
{
    if(openDBreadOnly())
    {
        while(dbFile.read((char *)&wfU, sizeof(wfUser)))
        {
            if((fName.contains(wfU.fName, Qt::CaseSensitive)) && (lName.contains(wfU.lName, Qt::CaseSensitive)))
                break;
        }
        dbFile.close();
    }
}

void mDB::delElement()
{
}
