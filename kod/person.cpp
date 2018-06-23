//
// Created by Yavuz on 12/31/2017.
//

#include "person.h"
PersonType person::getPersonType() {
    return Ptype;
}
int person::getTc() {
    return Tc;
}
void person::setTc(int tc) {
    Tc = tc;
}
void person::setSurname(string surname) {
    Surname = surname;
}
void person::setName(string name) {
    Name = name;
}
string person::getName() {
    return Name;
}
string person::getSurname() {
    return Surname;
}
void person::setPersonType(int type) {
    Ptype = PersonType (type);
}