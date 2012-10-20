#ifndef MDB_HPP
#define MDB_HPP

#include <QString>
#include <fstream>
#include <cstring>
#include <iostream>
#include <QMessageBox>
#include <QDate>
#include <vector>

using namespace std;

struct wfUser
{

    char fName[32],
    lName[32],
    mac1[13],
    mac2[13],
    mac3[13],
    mac4[13],
    mac5[13],
    icq[10],
    skype[32],
    tel[32];
    QDate date;
    int room;
};

class mDB
{    
    void addElement(wfUser);
    void delElement();
    int serchElement(wfUser);        
    wfUser createUser();

    wfUser userok;
public:
    void listAllUsers(vector<wfUser> &uList);
    void getElementByName(const QString &fName, const QString &lName, wfUser &wfU);
    void createElement(const wfUser &wUs);
    mDB();
    ~mDB();
};

#endif // MDB_HPP
