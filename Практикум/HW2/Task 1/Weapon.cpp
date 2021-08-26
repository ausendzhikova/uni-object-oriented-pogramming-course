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

#include "Weapon.hpp"

Weapon::Weapon(const Weapon& other) {
	this->type = other.type;
	this->kind = other.kind;
	this->effects = other.effects;
	this->hit_damage = other.hit_damage;
}

Weapon::Weapon(WeaponType type, WeaponKind kind, std::vector<std::pair<std::string, double>> effects, std::pair<double, double> hit_damage) {
	this->type = type;
	this->kind = kind;
	this->effects = effects;
	this->hit_damage = hit_damage;
}

Weapon& Weapon::operator=(const Weapon& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		this->kind = rhs.kind;
		this->effects = rhs.effects;
		this->hit_damage = rhs.hit_damage;
	}
	return *this;
}

WeaponType Weapon::getType() const {
	return type;
}

WeaponKind Weapon::getKind() const {
	return kind;
}

unsigned int Weapon::getSlots() const {
	unsigned int slots = 0;
	if (this->type == WeaponType::OneHanded) {
		slots += 1;
	}
	else  if (this->type == WeaponType::TwoHanded) {
		slots += 2;
	}
	return slots;
	
}

double Weapon::getScore() const {
	double  WeaponScore = (hit_damage.first + hit_damage.second) / 2;
	for (size_t i = 0; i < effects.size(); i++) {
		WeaponScore += effects[i].second;
	}
	if (type == WeaponType::OneHanded) {
		WeaponScore *= 0.75;
	}
	if (type == WeaponType::TwoHanded) {
		WeaponScore *= 1.5;
	}

	return WeaponScore;

}

void Weapon::set_type(WeaponType new_type) {
	switch (this->kind) {
	case WeaponKind::staff:
		if (new_type == WeaponType::OneHanded) {
			std::cout << "This type is not allowed for this kind of weapon!\n";
			return;
		}
	case WeaponKind::dagger:
		if (new_type == WeaponType::TwoHanded) {
			std::cout << "This type is not allowed for this kind of weapon!\n";
			return;
		}
	}
	type = new_type;
	return;

}

void Weapon::set_kind(WeaponKind new_kind) {
	switch (new_kind) {
	case WeaponKind::staff:
		set_type(WeaponType::TwoHanded);
		break;
	case WeaponKind::dagger:
		set_type(WeaponType::OneHanded);
		break;
	}
	kind = new_kind;
}

void Weapon::add_effect(std::pair<std::string,double> new_effect) {
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == new_effect.first) {
			effects[i].second = new_effect.second;
			return;
		}
	}
	effects.push_back(new_effect);
}

void Weapon::erase_effect(std::string name) {
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == name) {
			effects.erase(effects.begin() + i);
			return;
		}
	}
}

void Weapon::set_power(std::string name ,double power) {
	if (power < 0) {
		power*= -1;
	}
	for (size_t i = 0; i < effects.size(); i++) {
		if (effects[i].first == name) {
			effects[i].second = power;
			return;
		}
	}
}

bool Weapon::operator==(Weapon& other) {
	if (getScore() == other.getScore()) {
		return true;
	}
	return false;
}

bool Weapon::operator!=(Weapon& other) {
	if (getScore() != other.getScore()) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& o, const Weapon& to_print) {
	o << "WeaponType: " << (int)to_print.type << " Weapon Kind: " << (int)to_print.kind << " Weapon hit_damage: " << 
		to_print.hit_damage.first << " and " << to_print.hit_damage.second << std::endl;
	o << " Weapon effects: " << std::endl;
	for (size_t i = 0; i < to_print.effects.size(); i++) {
		o <<i+1<<") "<< "Effect name: " << to_print.effects[i].first << " Effect power: " << to_print.effects[i].second << std::endl;
	}
	return o;
}
