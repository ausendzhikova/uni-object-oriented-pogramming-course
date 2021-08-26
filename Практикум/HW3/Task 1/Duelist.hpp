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
#include "Deck.hpp"
#include <fstream>
class Duelist {
	std::string name;
	Deck deck;
public:
	Duelist();
	Duelist(std::string name);
	Duelist(std::string name, Deck deck);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& rhs);
	Deck& getDeck() const;
	std::string getName() const;
	void setName(std::string name);
	bool saveDeck(const char* filename) const;
	bool loadDeck(const char* filename) const;
};


