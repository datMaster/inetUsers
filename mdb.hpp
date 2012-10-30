#ifndef MDB_HPP
#define MDB_HPP

#include <QString>
#include <fstream>
#include <cstring>
#include <iostream>
#include <QMessageBox>
#include <vector>

#include "wfuser.hpp"

using namespace std;

class mDB
{    
private :    
    void delElement();
    int serchElement(const wfUser &sElement);
    bool openDBreadOnly();
    bool DBFileIsOpen();
    bool openDBwrite();
    bool openDB_w_app();
    void printError(const char *mess);        
    fstream dbFile;
public:
    void listAllUsers(vector<wfUser> &uList);
    void getElementByName(const QString &fName, const QString &lName, wfUser &wfU);
    void createElement(const wfUser &wUs);
    mDB();
    ~mDB();
};

#endif // MDB_HPP
