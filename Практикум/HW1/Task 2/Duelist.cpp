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

#include "Duelist.hpp"
#include <cstring>

Duelist::Duelist():deck(this->deck){
	player=nullptr;
}

Duelist::Duelist(char* player) {
	int playerLen = strlen(player);
	this->player = new char[playerLen + 1];
	for (int i = 0;player[i]!='\0'; i++) {
		this->player[i] = player[i];
	}
	
}


void Duelist::addMagicInDeck(MagicCard &x) {
	deck.addMagicCard(x);
	return;
}

void Duelist::addMonsterInDeck(MonsterCard &x) {
	deck.addMonsterCard(x);

	return;
}

void Duelist::changeMagicInDeck(int index, MagicCard x) {
	deck.changeMagicCard(index,x);

	return;
}

void Duelist::changeMonsterInDeck(int index, MonsterCard x) {
	deck.changeMonsterCard(index,x);

	return;
}

Duelist::~Duelist() {
	delete[] player;
}
