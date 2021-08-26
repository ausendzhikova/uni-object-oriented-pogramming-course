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
#include "Deck.hpp"
class Duelist {
private:
	char* player;
	Deck deck;
public:
	Duelist();
	Duelist(char* name);
	void addMagicInDeck(MagicCard &x);
	void addMonsterInDeck(MonsterCard &x);
	void changeMagicInDeck(int index, MagicCard x);
	void changeMonsterInDeck(int index, MonsterCard x);
	~Duelist();
};

