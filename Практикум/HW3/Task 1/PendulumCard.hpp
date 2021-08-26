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
#include "MagicCard.hpp"
#include "MonsterCard.hpp"

class PendulumCard: public MonsterCard, public MagicCard {
	unsigned int pendulumScale;
public:
	PendulumCard();
	PendulumCard(std::string name, std::string effect, unsigned int attackPoints, unsigned int defencePoints, unsigned int pendulumScale, CardType type);
	PendulumCard(const PendulumCard& other);
	PendulumCard& operator=(const PendulumCard& rhs);
	unsigned int getPendulumScale() const;
	void setPendulumScale(unsigned int pendulumScale);
	friend std::ostream& operator<<(std::ostream& out, const PendulumCard& obj);
	friend std::istream& operator>>(std::istream& in, PendulumCard& obj);
};

