/**
* Solution to homework assignment 4
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
	monsterCardsCount = magicCardsCount = pendulumCardsCount = totalCardsCount = 0;
}

Deck::Deck(std::string name, std::vector<Card*> cards, unsigned int magicCardsCount, unsigned int monsterCardsCount,
	unsigned int pendulumCardsCount, unsigned int totalCardsCount) {
	this->name = name;
	this->magicCardsCount = magicCardsCount;
	this->monsterCardsCount = monsterCardsCount;
	this->pendulumCardsCount = pendulumCardsCount;
	this->totalCardsCount = totalCardsCount;

	for (auto x : cards) {
		this->cards.push_back(x->clone());
	}
}

Deck::Deck(const Deck& other) {
	this->name = other.name;
	this->monsterCardsCount = other.monsterCardsCount;
	this->magicCardsCount = other.magicCardsCount;
	this->pendulumCardsCount = other.pendulumCardsCount;
	this->totalCardsCount = other.totalCardsCount;

	for (auto x : other.cards) {
		cards.push_back(x->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->magicCardsCount = rhs.magicCardsCount;
		this->monsterCardsCount = rhs.monsterCardsCount;
		this->pendulumCardsCount = rhs.pendulumCardsCount;
		this->totalCardsCount = rhs.totalCardsCount;
		for (auto x : cards) {
			delete x;
		}
		cards.clear();
		for (auto x : rhs.cards) {
			cards.push_back(x->clone());
		}
	}
	return *this;
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

unsigned int Deck::getTotalCardsCount() const {
	return totalCardsCount;
}

void Deck::setDeckname(std::string name) {
	this->name = name;
}

void Deck::addCard(Card* new_card) {

	PendulumCard* pendulum_card_ptr = dynamic_cast<PendulumCard*>(new_card);
	if (pendulum_card_ptr) {
		cards.push_back(pendulum_card_ptr->clone());
		pendulumCardsCount++;
		totalCardsCount++;
		return;
	}
	MonsterCard* monster_card_ptr = dynamic_cast<MonsterCard*>(new_card);
	if (monster_card_ptr) {
		monsterCardsCount++;
		totalCardsCount++;
		cards.push_back(monster_card_ptr->clone());
		return;
	}
	MagicCard* magic_card_ptr = dynamic_cast<MagicCard*>(new_card);
	if (magic_card_ptr) {
		magicCardsCount++;
		totalCardsCount++;
		cards.push_back(magic_card_ptr->clone());
	}
}

void Deck::changeCard(int index, Card* card) {
	if (index < 0) {
		return;
	}
	if ((unsigned)index > cards.size()-1) {
		addCard(card);
		return;
	}
	for (size_t i = 0; i < cards.size(); i++) {
		if (i == index) {
			PendulumCard* pendulum_card_ptr = dynamic_cast<PendulumCard*>(card);
			PendulumCard* pendulum_ptr = dynamic_cast<PendulumCard*>(cards[i]);
			MonsterCard* monster_card_ptr = dynamic_cast<MonsterCard*>(card);
			MonsterCard* monster_ptr = dynamic_cast<MonsterCard*>(cards[i]);
			MagicCard* magic_card_ptr = dynamic_cast<MagicCard*>(card);
			MagicCard* magic_ptr = dynamic_cast<MagicCard*>(cards[i]);

			if (monster_card_ptr && monster_ptr && !pendulum_ptr && !pendulum_card_ptr) {
				delete cards[i];
				cards[i] = card->clone();
				return;
			}
			if (magic_card_ptr && magic_ptr && !pendulum_ptr && !pendulum_card_ptr) {
				delete cards[i];
				cards[i] = card->clone();
				return;
			}

			if (pendulum_card_ptr && pendulum_ptr) {
				delete cards[i];
				cards[i] = card->clone();
				return;
			}
		}
	}
}

void Deck::clearDeck() {
	for (auto x : cards) {
		delete x;
	}
	cards.clear();
	magicCardsCount = monsterCardsCount = pendulumCardsCount = totalCardsCount = 0;
	name = " ";
}

void Deck::shuffle() {
	std::random_shuffle(cards.begin(), cards.end());
}

std::string Deck::getName() const {
	return this->name;
}

std::vector<Card*> Deck::getCards() const {
	return this->cards;
}

std::ostream& operator<<(std::ostream& out, const Deck& obj) {
	out << obj.name << '|' << obj.totalCardsCount << '|' << obj.monsterCardsCount << '|' << obj.magicCardsCount << '|';
	out << obj.pendulumCardsCount << '\n';

	for (size_t i = 0; i < obj.cards.size(); i++) {
		PendulumCard* pendulum_ptr = dynamic_cast<PendulumCard*>(obj.cards[i]);
		MonsterCard* monster_ptr = dynamic_cast<MonsterCard*>(obj.cards[i]);

		if (monster_ptr && !pendulum_ptr) {
			out << *monster_ptr;
		}

	}
	for (size_t i = 0; i < obj.cards.size(); i++) {
		PendulumCard* pendulum_ptr = dynamic_cast<PendulumCard*>(obj.cards[i]);
		MagicCard* magic_ptr = dynamic_cast<MagicCard*>(obj.cards[i]);

		if (magic_ptr && !pendulum_ptr) {
			out << *magic_ptr;
		}
	}
	for (size_t i = 0; i < obj.cards.size(); i++) {
		PendulumCard* pendulum_ptr = dynamic_cast<PendulumCard*>(obj.cards[i]);

		if (pendulum_ptr) {
			out << *pendulum_ptr;
		}
	}
	return out;
}

std::istream& operator>>(std::istream& in, Deck& obj) {
	char c;
	obj.clearDeck();
	getline(in, obj.name, '|');
	in >> obj.totalCardsCount >> c >> obj.monsterCardsCount >> c >> obj.magicCardsCount >> c >> obj.pendulumCardsCount;
	in.ignore(1, '\n');
	MonsterCard monster;
	MagicCard magic;
	PendulumCard pendulum;
	for (size_t i = 0; i < obj.monsterCardsCount; i++) {
		in >> monster;
		obj.cards.push_back(monster.clone());
	}
	for (size_t i = obj.monsterCardsCount; i < obj.magicCardsCount + obj.monsterCardsCount; i++) {
		in >> magic;
		obj.cards.push_back(magic.clone());
	}
	for (size_t i = obj.monsterCardsCount + obj.magicCardsCount; i < obj.totalCardsCount; i++) {
		in >> pendulum;
		obj.cards.push_back(pendulum.clone());
	}
	return in;
}

Deck::~Deck() {
	for (auto x : cards) {
		delete x;
	}
}

