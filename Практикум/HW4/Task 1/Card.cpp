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

#include "Card.hpp"

Card::Card(std::string name, std::string effect,unsigned int rarity) {
	this->name = name;
	this->effect = effect;
	this->rarity = rarity;
}

Card::Card(const Card& other) {
	this->name = other.name;
	this->effect = other.effect;
	this->rarity = other.rarity;
}

Card& Card::operator=(const Card& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
	}
	return *this;
}

std::string Card::getName() const {
	return this->name;
}

std::string Card::getEffect() const {
	return this->effect;
}

unsigned int Card::getRarity() const {
	return this->rarity;
}

void Card::setName(std::string name) {
	this->name = name;
}

void Card::setEffect(std::string effect) {
	this->effect = effect;
}

void Card::setRarity(unsigned int rarity) {
	this->rarity = rarity;
}

bool Card::operator>(const Card& other) const {
	if (this->rarity > other.rarity) {
		return true;
	}
	return false;
}

bool Card::operator<(const Card& other) const {
	if (this->rarity < other.rarity) {
		return true;
	}
	return false;
}

Card::~Card() {
}




