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
#include <utility>
#include <vector>
#include<iostream>

enum class WeaponType {
	OneHanded,
	TwoHanded,
};

enum class WeaponKind {
	axe,
	sword,
	dagger,
	mace,
	staff,
};
class Weapon {
	WeaponType type;
	WeaponKind kind;
	std::vector<std::pair<std::string, double>> effects;
	std::pair<double, double> hit_damage;

public:
	Weapon() = default;
	Weapon(const Weapon&);
	Weapon(WeaponType, WeaponKind, std::vector<std::pair<std::string, double>>, std::pair<double, double>);
	Weapon& operator=(const Weapon&);
	WeaponType getType() const;
	WeaponKind getKind() const;
	unsigned int getSlots() const;
	double getScore() const;
	void set_type(WeaponType);
	void set_kind(WeaponKind);
	void add_effect(std::pair<std::string,double>);
	void erase_effect(std::string);
	void set_power(std::string,double);

	bool operator==(Weapon&);
	bool operator!=(Weapon&);
	friend std::ostream& operator<<(std::ostream&, const Weapon&);
};

