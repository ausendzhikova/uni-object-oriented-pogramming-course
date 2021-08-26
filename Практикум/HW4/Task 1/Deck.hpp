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

#pragma once
#include "PendulumCard.hpp"
#include <vector>
#include <algorithm>

class Deck {
	std::string name;
	std::vector<Card*> cards;

	unsigned int magicCardsCount;
	unsigned int monsterCardsCount;
	unsigned int pendulumCardsCount;
	unsigned int totalCardsCount;

public:
	Deck();
	Deck(std::string, std::vector<Card*>, unsigned int, unsigned int, unsigned int, unsigned int);
	Deck(const Deck& other);
	Deck& operator=(const Deck& rhs);
	unsigned int getMonsterCardsCount() const;
	unsigned int getMagicCardsCount() const;
	unsigned int getPendulumCardsCount() const;
	unsigned int getTotalCardsCount() const;
	std::string getName() const;
	std::vector<Card*> getCards() const;
	void setDeckname(std::string name);
	void addCard(Card* new_card);
	void changeCard(int index, Card* card);
	void clearDeck();
	void shuffle();
	friend std::ostream& operator<<(std::ostream& out, const Deck& obj);
	friend std::istream& operator>>(std::istream& in, Deck& obj);
	~Deck();
};

