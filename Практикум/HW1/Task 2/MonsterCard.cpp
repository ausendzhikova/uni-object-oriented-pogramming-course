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

#include "MonsterCard.hpp"
#include <cstring>

MonsterCard::MonsterCard() {
	name = nullptr;
	attackPoints = 0;
	securityPoints = 0;
}

MonsterCard::MonsterCard(char* name, int attackPoints, int securityPoints) {
	int nameSize = strlen(name);
	for (int i = 0; i < nameSize; i++) {
		this->name[i] = name[i];
	}
	this->attackPoints = attackPoints;
	this->securityPoints = securityPoints;
	count++;
}

const char* MonsterCard::getName() const {
	return this->name;
}

const int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

const int MonsterCard::getSecutityPoints() const {
	return this->securityPoints;
}

void MonsterCard::setName(char* name) {
	delete[]this->name;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
	return;
}

void MonsterCard::setAttackPoints(int attackPoints) {
	this->attackPoints = attackPoints;
	return;
}

void MonsterCard::setSecurityPoints(int securityPoints) {
	this->securityPoints = securityPoints;
	return;
}



MonsterCard& MonsterCard::operator=(const MonsterCard& rhs) {
	if (this != &rhs) {
		delete[]this->name;
		this->attackPoints = rhs.attackPoints;
		this->securityPoints = rhs.securityPoints;

		int rhsLen = strlen(rhs.name);
		this->name = new char[rhsLen+1];
		for (int i = 0; i < rhsLen+1; ++i) {
			this->name[i] = rhs.name[i];
		}
	}

	return *this;
}


MonsterCard::MonsterCard(const MonsterCard& rhs) {
	int size = strlen(rhs.name);
	this->name = new char[size+1];
	for (int i = 0; i < size+1; ++i) {
		this->name[i] = rhs.name[i];
	}
	this->attackPoints = rhs.attackPoints;
	this->securityPoints = securityPoints;
}


MonsterCard::~MonsterCard() {
	delete[] name;
}

int MonsterCard::totalObject(void) {
	return count;
}

int MonsterCard::count = 0;


