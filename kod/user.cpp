//
// Created by Yavuz on 12/31/2017.
//

#include "user.h"

void user::LoadBalance(card *c, int b) {
    c->setBalance(c->getBalance() + b);
}

void user::ReadCard(card *c) {
    int gecis = 0;
    if(c->getCardType() == 2){
        gecis = 1;
    } else if(c->getCardType() == 0 && c->getBalance() >= 2000) {
        c->setBalance(c->getBalance()-2000);
        gecis = 1;
    } else if (c->getCardType() == 1 && c->getBalance() >= 1000){
        c->setBalance(c->getBalance()-1000);
        gecis = 1;
    } else {
        gecis = 0;
    }

    if(gecis == 1) {
         cout<<"Kalan bakiye: " << c->getBalance();
    } else {
        cout<<"Yetersiz bakiye: " << c->getBalance();
    }

}

void user::ShowCardState() {
    cout<< "Karttaki bakiye: "<<UserCard1.getBalance()<<endl;
    cout<< "Kart tipi: "<< CardType (UserCard1.getCardType())<<endl;
    cout<< "Karttaki bakiye: "<<UserCard2.getBalance()<<endl;
    cout<< "Kart tipi: "<<CardType (UserCard2.getCardType())<<endl;

}

void user::setCard1(card *c1) {
    UserCard1 = *c1;
}
void user::setCard2(card *c2) {
    UserCard2 = *c2;
}

card* user::getCard1() {
    return &UserCard1;
}

card* user::getCard2() {
    return &UserCard2;
}
