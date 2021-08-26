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
#pragma once
#include <string>
#include <vector>
#include <utility>
#include <iostream>

enum class ArmorType {
	cloth,
	leather,
	mail,
};
class Armor {
	ArmorType type;
	unsigned int defense;
	 std::vector<std::pair<std::string, double>> effects;

public:
	Armor() = default;
	Armor(const Armor&);
	Armor(ArmorType, unsigned int, std::vector<std::pair<std::string, double>>);
	Armor& operator=(const Armor&);
	ArmorType getType() const;
	unsigned int getDefense() const;
	double getScore() const;
	unsigned int getSlots() const;
	void set_type(ArmorType new_type);
	void set_power(std::string name, double power);
	void add_effect(std::pair<std::string, double> new_effect);
	void erase_effect(std::string name);

	bool operator==(Armor&);
	bool operator!=(Armor&);
	friend std::ostream& operator<<(std::ostream&,const Armor&);
};