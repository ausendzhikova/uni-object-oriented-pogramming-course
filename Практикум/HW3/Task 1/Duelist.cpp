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

#include "Duelist.hpp"

Duelist::Duelist() {
	name = "";
	deck = Deck();
}

Duelist::Duelist(std::string name) {
	this->name = name;
}

Duelist::Duelist(std::string name, Deck deck) {
	this->name = name;
	this->deck = deck;
}

Duelist::Duelist(const Duelist& other) {
	this->name = other.name;
	this->deck = other.deck;
}

Duelist& Duelist::operator=(const Duelist& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->deck = rhs.deck;
	}
	return *this;
}

Deck& Duelist::getDeck() const {
	Deck* ptr = (Deck*)&deck;
	return *ptr;
}

std::string Duelist::getName() const {
	return this->name;
}

void Duelist::setName(std::string name) {
	this->name = name;
}

bool Duelist::saveDeck(const char* filename) const {
	std::ofstream file(filename);
	if (!file.is_open()) {
		return false;
	}
	file << this->deck;
	if (file.bad() || file.fail()) {
		file.close();
		return false;
	}
	file.close();
	return true;
}

bool Duelist::loadDeck(const char* filename) const {
	std::ifstream file(filename);
	if (!file.is_open()) {
		return false;
	}

	file >> getDeck();
	if (file.fail() || file.bad()) {
		file.close();
		return false;
	}
	file.close();
	return true;
}
