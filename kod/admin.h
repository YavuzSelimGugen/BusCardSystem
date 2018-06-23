//
// Created by Yavuz on 12/31/2017.
//

#ifndef ODEV3_ADMIN_H
#define ODEV3_ADMIN_H


#include "person.h"
#include "user.h"

class admin :public person {
public:
    void CreateUser(string ad,string soyad, int tc,person *dizi[10]);
    void DeleteUser(int tc,person *dizi[10]);
    void ShowPersonState(person*);
    void ShowUserState(user*);
    user* FindUser(int,person *dizi[10]);
    void CombineUserCards(user*);
};


#endif //ODEV3_ADMIN_H
