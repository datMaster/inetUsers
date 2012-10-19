#ifndef MDB_HPP
#define MDB_HPP

#include <QString>
#include <fstream>
#include <QMessageBox>
#include <QSqlDatabase>

using namespace std;

class wfUser
{
public :
    wfUser()
    {
        fName.clear();
        lName.clear();
        mac1.clear();
        mac2.clear();
        mac3.clear();
        mac4.clear();
        mac5.clear();
        icq.clear();
        skype.clear();
        tel.clear();
        room = 0;
    }

    QString fName,
        lName,
        mac1,
        mac2,
        mac3,
        mac4,
        mac5,
        icq,
        skype,
        tel;
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
    void createElement(const QString &fName, const QString &lName, const QString &mac1,
                       const QString &mac2, const QString &mac3, const QString &mac4,
                       const QString &mac5, const QString &icq, const QString &skype, const QString &room, const QString &tel);
    mDB();
    ~mDB();
};

#endif // MDB_HPP
