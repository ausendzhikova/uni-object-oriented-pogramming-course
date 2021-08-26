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

#pragma once
#include "PendulumCard.hpp"
#include <vector>

class Deck {
	std::string name;
	std::vector<MagicCard> magicCards;
	std::vector<MonsterCard> monsterCards;
	std::vector<PendulumCard> pendulumCards;

	unsigned int magicCardsCount;
	unsigned int monsterCardsCount;
	unsigned int pendulumCardsCount;

public:
	Deck();
	Deck(const Deck& other);
	Deck& operator=(const Deck& rhs);
	Deck(std::string, std::vector<MagicCard>, std::vector<MonsterCard>, std::vector<PendulumCard>, unsigned int, unsigned int,unsigned int);
	unsigned int getMonsterCardsCount() const;
	unsigned int getMagicCardsCount() const;
	unsigned int getPendulumCardsCount() const;
	std::string getName() const;
	void setDeckname(std::string name);
	void addMonsterCard(MonsterCard& new_card);
	void addMagicCard(MagicCard& new_card);
	void addPendulumCard(PendulumCard& new_card);
	void changeMonsterCard(int index, MonsterCard& card);
	void changeMagicCard(int index, MagicCard& card);
	void changePendulumCard(int index, PendulumCard& card);
	void clearDeck();

	friend std::ostream& operator<<(std::ostream& out, const Deck& obj);
	friend std::istream& operator>>(std::istream& in, Deck& obj);
};

