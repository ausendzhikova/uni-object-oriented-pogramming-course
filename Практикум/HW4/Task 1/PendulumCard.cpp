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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard(std::string name, std::string effect, unsigned int rarity, unsigned int attackPoints, unsigned int defencePoints,
	unsigned int pendulumScale, CardType type) : MonsterCard(name, effect, rarity, attackPoints, defencePoints), MagicCard(name, effect, rarity, type), Card(name, effect, rarity) {
	this->pendulumScale = pendulumScale;
}

PendulumCard::PendulumCard(const PendulumCard& other) : MagicCard(other), MonsterCard(other), Card(other) {
	this->pendulumScale = other.pendulumScale;
}

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs) {
	if (this != &rhs) {
		MagicCard::operator=(rhs);
		MonsterCard::operator=(rhs);
		Card::operator=(rhs);
		this->pendulumScale = rhs.pendulumScale;
	}
	return *this;
}

unsigned int PendulumCard::getPendulumScale() const {
	return this->pendulumScale;
}

void PendulumCard::setPendulumScale(unsigned int pendulumScale) {
	if (pendulumScale >= 1 && pendulumScale <= 13) {
		this->pendulumScale = pendulumScale;
	}
}

Card* PendulumCard::clone() const {
	return new PendulumCard(*this);
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& obj) {
	out << obj.name << '|' << obj.effect << '|' << obj.rarity << '|' << obj.attackPoints << '|' << obj.defencePoints << '|';
	out << obj.pendulumScale << '|' << obj.type << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& obj) {
	char c;
	getline(in, obj.name, '|');
	getline(in, obj.effect, '|');
	in >> obj.rarity >> c >> obj.attackPoints >> c >> obj.defencePoints >> c >> obj.pendulumScale >> c >> obj.type;
	in.ignore(1, '\n');
	return in;
}
