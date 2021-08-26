/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 1
* @compiler VC
*/

#include "Money.hpp"

Money::Money(int silver, int gold) {
	this->silver = silver;
	this->gold = gold;
	set_money();
}

Money::Money(const Money& other) {
	this->silver = other.silver;
	this->gold = other.gold;
}

Money& Money::operator=(const Money& rhs) {
	if (this != &rhs) {
		this->silver = rhs.silver;
		this->gold = rhs.gold;
	}
	return *this;
}

int Money::getSilver() const {
	return silver;
}

int Money::getGold() const {
	return gold;
}

unsigned int Money::getSlots() const {
	return 0;
}

void Money::set_money() {
	gold += silver / 100;
	silver = silver % 100;
	return;
}

void Money::addMoney(int silver, int gold) {
	this->silver += silver;
	this->gold += gold;
	set_money();
}

std::ostream& operator<<(std::ostream& o, const Money& to_print) {
	o << "Gold: " << to_print.gold << " Silver: " << to_print.silver << std::endl;
	return o;
}
