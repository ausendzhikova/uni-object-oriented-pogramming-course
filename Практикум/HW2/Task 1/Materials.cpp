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

#include "Materials.hpp"

Materials::Materials(MaterialType type, unsigned int quantity) {
	this->type = type;
	this->quantity = quantity;
}

Materials::Materials(const Materials& other) {
	this->type = other.type;
	this->quantity = other.quantity;
}

Materials& Materials::operator=(const Materials& rhs) {
	if (this != &rhs) {
		this-> type = rhs.type;
		this-> quantity = rhs.quantity;
	}
	return *this;
}

unsigned int Materials::getSlots() const {
	unsigned int slots = 0;
	switch (this->type) {
	case MaterialType::herbs:
	case MaterialType::ores:
	case MaterialType::cloth:
		slots += (quantity / 20) + (quantity % 20 == 0 ? 0 : 1);
		return slots;
	case MaterialType::essence:
		slots += (quantity / 10) + (quantity % 10 == 0 ? 0 : 1);
		return slots;

	}
}

MaterialType Materials::getType() const {
	return type;
}

void Materials::addMaterial(unsigned int quantity) {
	this->quantity += quantity;
}

std::ostream& operator<<(std::ostream& o, const Materials& to_print) {
	o << "MaterialType: " << (int)to_print.type << " Quantity: " << to_print.quantity << std::endl;
	return o;
}
