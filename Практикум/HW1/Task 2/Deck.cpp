/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 2
* @compiler VC
*/

#include "Deck.hpp"


int Deck::countOfMagicCards() {
    int counter = MagicCard::totalObject();
    return counter;
}

int Deck::countOfMonsterCards() {
    int counter = MonsterCard::totalObject();
    return counter;
}

void Deck::createDeck() {
    for (int i = 0; i < 20; i++) {
        magicCards[i] = MagicCard();
        monsterCards[i] = MonsterCard();
    }
    return;
}

Deck& Deck::operator=(const Deck& rhs) {
    for (int i = 0; i < 20; i++) {
        this->monsterCards[i] = rhs.monsterCards[i];
        this->magicCards[i] = rhs.magicCards[i];
}
    return *this;
}


void Deck::addMagicCard(MagicCard x) {
    for (int i = 0; i < 20; i++) {
        if (magicCards[i].getName() ==nullptr && magicCards[i].getEffect()==nullptr && magicCards[i].getType()==nullptr) {
            magicCards[i] = x;
            return;
        }
    }
}

void Deck::addMonsterCard(MonsterCard x) {
    for (int i = 0; i < 20; i++) {
        if (monsterCards[i].getName()==nullptr && monsterCards[i].getAttackPoints()==0 && monsterCards[i].getSecutityPoints()==0) {
            monsterCards[i] = x;
            return;
        }
   }

}


void Deck::changeMagicCard(int index, MagicCard x) {
    for (int i = 0; i < 20; i++) {
        if (i == index) {
            magicCards[i] = x;
            return;
        }
    }
}

void Deck::changeMonsterCard(int index, MonsterCard x) {
    for (int i = 0; i < 20; i++) {
        if (i == index) {
            monsterCards[i] = x;
            return;
        }
    }
}
