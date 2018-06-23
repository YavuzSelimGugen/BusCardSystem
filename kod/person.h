//
// Created by Yavuz on 12/31/2017.
//

#ifndef ODEV3_PERSON_H
#define ODEV3_PERSON_H

#include <iostream>
using namespace std;

enum PersonType {User,Admin};

class person {

public:
    void setName(string name);
    string getName();
    void setSurname (string surname);
    string getSurname();
    void setTc(int tc);
    int getTc();
    void setPersonType(int type);
    PersonType getPersonType();
protected:
    int Tc;
    string Name,Surname;
    PersonType  Ptype;
};


#endif //ODEV3_PERSON_H
