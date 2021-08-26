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
#include <string>
#include<iostream>

class Card {
protected:
	std::string name;
	std::string effect;
public:
	Card(const Card& other);
	Card(std::string name = "", std::string effect = "");
	Card& operator=(const Card& rhs);
	std::string getName() const;
	std::string getEffect() const;
	void setName(std::string name);
	void setEffect(std::string effect);
};

