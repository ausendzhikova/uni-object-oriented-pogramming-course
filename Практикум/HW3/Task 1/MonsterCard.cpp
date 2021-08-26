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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int attackPoint, unsigned int defencePoints) : Card(name,effect) {
	this->attackPoints = attackPoint;
	this->defencePoints = defencePoints;
}

MonsterCard::MonsterCard(const MonsterCard& other) : Card(other) {
	this->attackPoints = other.attackPoints;
	this->defencePoints = other.defencePoints;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs) {
	if (this != &rhs) {
		Card:: operator=(rhs);
		this->attackPoints = rhs.attackPoints;
		this->defencePoints = rhs.defencePoints;
	}
	return *this;
}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

unsigned int MonsterCard::getDefencePoints() const {
	return this->defencePoints;
}

void MonsterCard::setAttackPoints(unsigned int attackPoints) {
	this->attackPoints = attackPoints;
}

void MonsterCard::setDefencePoints(unsigned int defencePoints) {
	this->defencePoints = defencePoints;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& obj) {
	out << obj.name << '|' << obj.effect << '|' << obj.attackPoints << '|' << obj.defencePoints << '\n';
		return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& obj) {
	char c;
	getline(in, obj.name, '|');
	getline(in, obj.effect, '|');
	in >> obj.attackPoints >> c >> obj.defencePoints;
	in.ignore(1,'\n');
	return in;
}
