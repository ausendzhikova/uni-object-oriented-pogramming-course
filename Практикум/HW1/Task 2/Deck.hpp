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

#pragma once
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
class Deck {
public:
	MonsterCard monsterCards[20];
	MagicCard magicCards[20];
public:
	int countOfMagicCards();
	int countOfMonsterCards();
	void createDeck();
	Deck& operator=(const Deck& rhs);
	void addMagicCard(MagicCard x);
	void addMonsterCard(MonsterCard x);
	void changeMagicCard(int index, MagicCard x);
	void changeMonsterCard(int index, MonsterCard x);


	friend class MagicCard;
};




