//
// Created by Yavuz on 12/31/2017.
//

#ifndef ODEV3_USER_H
#define ODEV3_USER_H

#include "person.h"
#include "card.h"

class user : public person {
public:
    void LoadBalance(card*,int);
    void ReadCard(card*);
    void ShowCardState();
    void setCard1(card*);
    void setCard2(card*);
    card* getCard1();
    card* getCard2();
private:
    card UserCard1,UserCard2;
};


#endif //ODEV3_USER_H
