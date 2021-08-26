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
#include <string>
#include<iostream>

class Card {
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;

public:
	Card(std::string name = "", std::string effect = "", unsigned int rarity = 0);
	Card(const Card& other);
	Card& operator=(const Card& rhs);
	std::string getName() const;
	std::string getEffect() const;
	unsigned int getRarity() const;
	void setName(std::string name);
	void setEffect(std::string effect);
    void setRarity(unsigned int rarity);
	bool operator>(const Card& other) const;
	bool operator<(const Card& other) const;
	virtual Card* clone() const = 0;
	virtual ~Card();
};

 