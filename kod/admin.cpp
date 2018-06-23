//
// Created by Yavuz on 12/31/2017.
//

#include "admin.h"

void admin::ShowUserState(user *user1) {
    cout<< user1->getName()<<endl;
    cout<< user1->getSurname()<<endl;
    cout<< user1->getTc()<<endl;
    user1->ShowCardState();
}

void admin::DeleteUser(int tc, person *dizi[10]) {
    for (int i = 0; i <10 ; i++) {
        if(tc == dizi[i]->getTc()){
            dizi[i]->setTc(0);
            dizi[i]->setPersonType(0);
            dizi[i]->setSurname("");
            dizi[i]->setName("");
            cout<< "Silme islemi basarili."<<endl;
        } else {
            cout<< "Silme islemi hatali."<<endl;
        }
    }
}

void admin::CreateUser(string ad, string soyad, int tc, person *dizi[10]) {
    user *user1 = new user();
    user1->setName(ad);
    user1->setSurname(soyad);
    user1->setPersonType(0);
    user1->setTc(tc);
    for (int i = 0; i <10 ; i++) {
        if(dizi[i]->getTc() == 0) {
            dizi[i] = user1;
        }
    }
    cout<<"Kullanici basarili bir sekilde olusturuldu."<<endl;
}

void admin::ShowPersonState(person *person1) {
    cout<< person1->getName()<<endl;
    cout<< person1->getSurname()<<endl;
    cout<< person1->getTc()<<endl;
    cout<< person1->getPersonType()<<endl;
}

user* admin::FindUser(int tc,person *dizi[10]) {
    user *u1 = new user;
    int boolean = 0;
    for (int i = 0; i < 10; i++) {
        if(tc == dizi[i]->getTc()){
            u1 = ((user *)(dizi[i]));
            boolean = 1;
        }
    }

    if(boolean == 0) {
        cout<< "Aranan kullanici bulunamadi."<<endl;
    }
    return u1;
}

void admin::CombineUserCards(user *user1) {
    card *card2 = user1->getCard2();
    card c2 = *card2;
    card *card1 = user1->getCard1();
    card c1 = *card1;
    *card1 = c1 + c2;
    card2->setBalance(0);
    user1->setCard1(card1);
    user1->setCard2(card2);
}