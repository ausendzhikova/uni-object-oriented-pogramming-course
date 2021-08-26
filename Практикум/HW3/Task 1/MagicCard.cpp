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

#include "MagicCard.hpp"

MagicCard::MagicCard() : Card(){
	this->type = CardType::UNKNOWN;
}

MagicCard::MagicCard(std::string name, std::string effect, CardType type): Card(name,effect) {
	this->type = type;
}

MagicCard::MagicCard(const MagicCard& other): Card(other) {
	this->type = other.type;
}

MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		Card:: operator=(rhs);
		this->type = rhs.type;
	}
	return *this;
}

CardType MagicCard::getType() const {
	return this->type;
}

void MagicCard::setType(CardType type) {
	this->type = type;
}

std::ostream& operator<<(std::ostream& out, const MagicCard& obj) {
	out << obj.name << '|' << obj.effect << '|' << obj.type << '\n';
	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& obj) {
	getline(in, obj.name, '|');
	getline(in, obj.effect, '|');
	in >> obj.type;
	in.ignore(1,'\n');
	return in;
}

std::ostream& operator<<(std::ostream& out, const CardType& obj) {
	switch (obj) {
	case CardType::BUFF:
		out << "BUFF";
		return out;
	case CardType::SPELL:
		out << "SPELL";
		return out;
	case CardType::TRAP:
		out << "TRAP";
		return out;
	default:
		return out;
	}
}

std::istream& operator>>(std::istream& in, CardType& obj) {
	std::string type;
    in>>type;
	if (type == "BUFF") {
		obj = CardType::BUFF;
		return in;
	}
	if (type == "SPELL") {
		obj= CardType::SPELL;
		return in;
	}
	if (type == "TRAP") {
		obj = CardType::TRAP;
		return in;
	}

}