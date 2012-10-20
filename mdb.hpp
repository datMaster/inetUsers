#ifndef MDB_HPP
#define MDB_HPP

#include <QString>
#include <fstream>
#include <cstring>
#include <iostream>
#include <QMessageBox>

using namespace std;

struct wfUser
{

    char fName[32],
    lName[13],
    mac1[13],
    mac2[13],
    mac3[13],
    mac4[13],
    mac5[13],
    icq[10],
    skype[32],
    tel[32];
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
    void getElementByName(const QString &fName, const QString &lName, wfUser &wfU);
    void createElement(const QString &fName, const QString &lName, const QString &mac1,
                       const QString &mac2, const QString &mac3, const QString &mac4,
                       const QString &mac5, const QString &icq, const QString &skype, const QString &room, const QString &tel);
    mDB();
    ~mDB();
};

#endif // MDB_HPP
