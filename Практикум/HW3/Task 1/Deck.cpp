/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 1
* @compiler VC
*/

#include "Deck.hpp"

Deck::Deck() {
	name = "";
	monsterCardsCount = magicCardsCount = pendulumCardsCount = 0;
}

Deck::Deck(const Deck& other) {
	this->name = other.name;
	this->magicCards = other.magicCards;
	this->monsterCards = other.monsterCards;
	this->pendulumCards = other.pendulumCards;
	this->monsterCardsCount = other.monsterCardsCount;
	this->magicCardsCount = other.magicCardsCount;
	this->pendulumCardsCount = other.pendulumCardsCount;
}
Deck& Deck::operator=(const Deck& rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->magicCards = rhs.magicCards;
        this->monsterCards = rhs.monsterCards;
        this->pendulumCards = rhs.pendulumCards;
        this->magicCardsCount = rhs.magicCardsCount;
        this->monsterCardsCount = rhs.monsterCardsCount;
        this->pendulumCardsCount = rhs.pendulumCardsCount;
    }
    return *this;
}

Deck::Deck(std::string name, std::vector<MagicCard> magicCards, std::vector<MonsterCard> monsterCards, std::vector<PendulumCard> pendulumCards,
    unsigned int magicCardsCount,unsigned int monsterCardsCount, unsigned int pendulumCardsCount) {
    this->name = name;
    this->magicCards = magicCards;
    this->monsterCards = monsterCards;
    this->pendulumCards = pendulumCards;
    this->magicCardsCount = magicCardsCount;
    this->monsterCardsCount = monsterCardsCount;
    this->pendulumCardsCount = pendulumCardsCount;
}

unsigned int Deck::getMonsterCardsCount() const {
    return monsterCardsCount;
}

unsigned int Deck::getMagicCardsCount() const {
    return magicCardsCount;
}

unsigned int Deck::getPendulumCardsCount() const {
    return pendulumCardsCount;
}

void Deck::setDeckname(std::string name) {
    this->name = name;
}

void Deck::addMonsterCard(MonsterCard& new_card) {
    monsterCards.push_back(new_card);
    monsterCardsCount++;
}

void Deck::addMagicCard(MagicCard& new_card) {
    magicCards.push_back(new_card);
    magicCardsCount++;
}

void Deck::addPendulumCard(PendulumCard& new_card) {
    pendulumCards.push_back(new_card);
    pendulumCardsCount++;

}

void Deck::changeMonsterCard(int index, MonsterCard& card) {
    for (size_t i = 0; i < monsterCards.size(); i++) {
        if (i == index) {
            monsterCards[i] = card;
            return;
        }
    }
    monsterCards.push_back(card);
    monsterCardsCount++;
}

void Deck::changeMagicCard(int index, MagicCard& card) {
    for (size_t i = 0; i < magicCards.size(); i++) {
        if (i == index) {
            magicCards[i] = card;
            return;
        }
    }
    magicCards.push_back(card);
    magicCardsCount++;
}

void Deck::changePendulumCard(int index, PendulumCard& card) {
    for (size_t i = 0; i < pendulumCards.size(); i++) {
        if (index == i) {
            pendulumCards[i] = card;
            return;
        }
    }
    pendulumCards.push_back(card);
    pendulumCardsCount++;
}

void Deck::clearDeck() {
    magicCards.clear();
    monsterCards.clear();
    pendulumCards.clear();
    magicCardsCount = monsterCardsCount = pendulumCardsCount = 0;
    name = " ";
}

std::string Deck::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& out, const Deck& obj) {
    out << obj.name << '|' << obj.monsterCardsCount << '|' << obj.magicCardsCount << '|' << obj.pendulumCardsCount << '\n';
    for (size_t i = 0; i < obj.monsterCards.size(); i++) {
        out << obj.monsterCards[i];
    }
    for (size_t i = 0; i < obj.magicCards.size(); i++) {
        out << obj.magicCards[i];
    }
    for (size_t i = 0; i < obj.pendulumCards.size(); i++) {
        out << obj.pendulumCards[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, Deck& obj) {
    char c;
    obj.clearDeck();
    getline(in, obj.name,'|');
    in >> obj.monsterCardsCount >> c >> obj.magicCardsCount >> c >> obj.pendulumCardsCount;
    in.ignore(1,'\n');
   MonsterCard monster;
    MagicCard magic;
    PendulumCard pendulum;
    for (size_t i = 0; i <obj.monsterCardsCount; i++) {
        in >> monster;
        obj.monsterCards.push_back(monster);
    }
    for (size_t i = 0; i < obj.magicCardsCount; i++) {
        in >> magic;
        obj.magicCards.push_back(magic);
    }
    for (size_t i = 0; i < obj.pendulumCardsCount; i++) {
        in >> pendulum;
        obj.pendulumCards.push_back(pendulum);
    }
    return in;
}
