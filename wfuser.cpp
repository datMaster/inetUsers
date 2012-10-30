#include "wfuser.hpp"

wfUser::wfUser()
{
    for(int i = 0; i < 32; ++ i)
        fName[i] = lName[i] = skype[i] = tel[i] = '\0';
    for(int i = 0; i < 13; ++ i)
        mac1[i] = mac2[i] = mac3[i] = mac4[i] = mac5[i] = '\0';
    for(int i = 0; i < 10; ++ i)
        icq[i] = '\0';
    room = 0;
    date.setDate(0, 0, 0);
}

wfUser::~wfUser()
{

}

bool wfUser::operator ==(const wfUser &secondObj)
{
    if(!strcmp(this->fName, secondObj.fName) && !strcmp(this->lName, secondObj.lName)
      && !strcmp(this->mac1, secondObj.mac1) && !strcmp(this->mac2, secondObj.mac2)
      && !strcmp(this->mac3, secondObj.mac3) && !strcmp(this->mac4, secondObj.mac4)
      && !strcmp(this->mac5, secondObj.mac5) && !strcmp(this->skype, secondObj.skype)
      && !strcmp(this->icq, secondObj.icq)   && (this->room == secondObj.room)
      && (this->date == secondObj.date)      && !strcmp(this->tel, secondObj.tel))
        return true;
    return false;
}
