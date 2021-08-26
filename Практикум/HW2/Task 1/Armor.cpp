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

#include "Armor.hpp"

Armor::Armor(const Armor& other) {
	this->type = other.type;
	this->defense = other.defense;
	this->effects = other.effects;
}

Armor::Armor(ArmorType type, unsigned int defense, std::vector<std::pair<std::string, double>> effects) {
	this->type = type;
	this->defense = defense;
	this->effects = effects;
}

Armor& Armor::operator=(const Armor& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		this->defense = rhs.defense;
		this->effects = rhs.effects;
	}
	return *this;
}

ArmorType Armor::getType() const {
	return type;
}

unsigned int Armor::getDefense() const {
	return defense;
}

double Armor::getScore() const {
	double Gearscore = 0;
	for (size_t i = 0; i < effects.size(); i++) {
		Gearscore += effects[i].second;
	}
	return Gearscore;

}

unsigned int Armor::getSlots() const {
	return 1;
}

void Armor::set_type(ArmorType new_type) {
	type = new_type;
}

void Armor::set_power(std::string name, double power) {
	if (power < 0) {
		power *= -1;
	}
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == name) {
			effects[i].second = power;
			return;
		}
	}
}

void Armor::add_effect(std::pair<std::string, double> new_effect) {
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == new_effect.first) {
			effects[i] = new_effect;
			return;
		}
	}
	effects.push_back(new_effect);
}

void Armor::erase_effect(std::string name) {
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == name) {
			effects.erase(effects.begin() + i);
			return;
		}
	}
}

bool Armor::operator==(Armor& other) {
	if (getScore() == other.getScore()) {
		return true;
	}
	return false;
}

bool Armor::operator!=(Armor& other) {
	if (getScore() != other.getScore()) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& o, const Armor& to_print) {
	o << "ArmorType:" << (int)to_print.type << " Armor defense:" << to_print.defense << std::endl;
	o << "Armor effects: " << std::endl;
	for (size_t i = 0; i < to_print.effects.size(); i++) {
		o <<i+1<<") " << "Effect name: " << to_print.effects[i].first << " Effect power: " << to_print.effects[i].second << std::endl;
	}
	return o;
}
