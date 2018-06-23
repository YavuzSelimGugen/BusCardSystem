//
// Created by Yavuz on 12/31/2017.
//

#include "card.h"
int card::getBalance() {
    return Balance;
}

CardType card::getCardType() {
    return cardType;
}

void card::setBalance(int balance) {
    Balance = balance;
}

void card::setCardType(int i) {
    cardType = CardType(i);
}
card card::operator+(card& other) {
    int result = this->getBalance() + other.getBalance();
    this->setBalance(result);
    return *this;
}