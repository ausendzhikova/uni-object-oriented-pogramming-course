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

#pragma once
#include "Card.hpp"

enum class CardType {
	TRAP,
	BUFF,
	SPELL,
	UNKNOWN
};

class MagicCard : virtual public Card {
protected:
	CardType type;
public:
	MagicCard(std::string name="", std::string effect="",unsigned int rarity=0, CardType type=CardType::UNKNOWN);
	MagicCard(const MagicCard& other);
	MagicCard& operator=(const MagicCard& rhs);
	CardType getType() const;
	void setType(CardType type);
	friend std::ostream& operator<<(std::ostream& out, const MagicCard& obj);
	friend std::istream& operator>>(std::istream& in, MagicCard& obj);
	Card* clone() const;
};

std::ostream& operator<<(std::ostream& out, const CardType& obj);
std::istream& operator>>(std::istream& in, CardType& obj);