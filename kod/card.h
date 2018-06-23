//
// Created by Yavuz on 12/31/2017.
//

#ifndef ODEV3_CARD_H
#define ODEV3_CARD_H

enum CardType {Normal,Student,Retired};

class card {
private:
    int Balance;
    CardType cardType;
public:
    void setCardType(int i);
    void setBalance(int);
    CardType getCardType();
    int getBalance();
    card operator+(card& other);
};


#endif //ODEV3_CARD_H
