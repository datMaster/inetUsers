#ifndef WFUSER_HPP
#define WFUSER_HPP

#include <QDate>

class wfUser
{    
public:
    wfUser();
    ~wfUser();

    bool operator == (const wfUser &secondObj);

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

#endif // WFUSER_HPP
