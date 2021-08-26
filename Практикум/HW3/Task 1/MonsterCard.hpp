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

#pragma once
#include "Card.hpp"
class MonsterCard: virtual public Card {
protected:
	unsigned int attackPoints;
	unsigned int defencePoints;
public:
	MonsterCard(std::string name= "",std::string effect="",unsigned int attackPoint = 0, unsigned int defencePoints = 0);
	MonsterCard(const MonsterCard& other);
	MonsterCard& operator=(const MonsterCard& rhs);
	unsigned int getAttackPoints() const;
	unsigned int getDefencePoints() const;
	void setAttackPoints(unsigned int attackPoints);
	void setDefencePoints(unsigned int defencePoints);
	friend std::ostream& operator<<(std::ostream& out, const MonsterCard& obj);
	friend std::istream& operator>>(std::istream& in, MonsterCard& obj);
};

