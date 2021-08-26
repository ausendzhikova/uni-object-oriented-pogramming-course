/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Aylin Usendzhikova
* @idnumber 62582
* @task 2
* @compiler VC
*/


#include "MagicCard.hpp"
#include<cstring>

MagicCard::MagicCard() {
	name = nullptr;
	effect = nullptr;
	type = nullptr;

}

MagicCard::MagicCard(char* name, char* effect, char* type) {
	int nameSize = strlen(name);
	for (int i = 0; i < nameSize; i++) {
		this->name[i] = name[i];
	}
	int effectSize = strlen(effect);
	for (int i = 0; i < effectSize; i++) {
		this->effect[i] = effect[i];
	}
	int typeSize = strlen(type);
	for (int i = 0; i < typeSize; i++) {
		this->type[i] = type[i];
	}
	count++;

}
const char* MagicCard::getName()const {
	return name;
}
const char* MagicCard::getEffect() const {
	return effect;
}
const char* MagicCard::getType() const
{
	return type;
}

void MagicCard::setName(char* name) {
	delete[]this->name;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
	return;
}

void MagicCard::setEffect(char* effect) {
	delete[]this->effect;
	int len = strlen(effect);
	this->effect = new char[len + 1];
	strcpy_s(this->effect, len + 1, effect);
	return;
}

void MagicCard::setType(char* type) {
	delete[]this->type;
	int len = strlen(type);
	this->type = new char[len + 1];
	strcpy_s(this->type, len + 1, type);
	return;
}

MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		delete[]this->name;
		delete[]this->effect;
		delete[]this->type;
		int nameLen = strlen(rhs.name);
		this->name = new char[nameLen+1];
		for (int i = 0; i < nameLen+1; ++i) {
			this->name[i] = rhs.name[i];
		}
		int effectLen = strlen(rhs.effect);
		this->effect = new char[effectLen+1];
		for (int i = 0; i < effectLen+1; i++) {
			this->effect[i] = rhs.effect[i];
		}
		int typeLen = strlen(rhs.type);
		this->type = new char[typeLen+1];
		for (int i = 0; i < typeLen+1; i++) {
			this->type[i] = rhs.type[i];
		}
	}
	return *this;
}


MagicCard::MagicCard(const MagicCard& rhs) {
	int nameLen = strlen(rhs.name);
	this->name = new char[nameLen+1];
	for (int i = 0; i < nameLen+1; ++i) {
		this->name[i] = rhs.name[i];
	}
	int effectLen = strlen(rhs.effect);
	this->effect = new char[effectLen+1];
	for (int i = 0; i < effectLen+1; i++) {
		this->effect[i] = rhs.effect[i];
	}
	int typeLen = strlen(rhs.type);
	this->type = new char[typeLen+1];
	for (int i = 0; i < typeLen+1; i++) {
		this->type[i] = rhs.type[i];
	}
}
MagicCard::~MagicCard() {
	delete[] name;
	delete[] effect;
	delete[] type;
}
int MagicCard::totalObject(void) {

	return count;
}

int MagicCard::count = 0;
