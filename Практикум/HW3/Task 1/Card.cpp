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

#include "Card.hpp"
Card::Card(const Card& other) {
	this->name = other.name;
	this->effect = other.effect;
}

Card::Card(std::string name, std::string effect) {
	this->name = name;
	this->effect = effect;
}

Card& Card::operator=(const Card& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
	}
	return *this;
}

std::string Card::getName() const {
	return this->name;
}

std::string Card::getEffect() const {
	return this->effect;
}

void Card::setName(std::string name) {
	this->name = name;
}

void Card::setEffect(std::string effect) {
	this->effect = effect;
}

