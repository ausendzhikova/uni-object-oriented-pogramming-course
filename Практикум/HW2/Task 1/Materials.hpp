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
#include <iostream>
enum class MaterialType {
	herbs,
	ores,
	cloth,
	essence,
};

class Materials {
	MaterialType type;
	unsigned int quantity;
public:
	Materials() = default;
	Materials(MaterialType,unsigned int);
	Materials(const Materials&);
	Materials& operator=(const Materials&);

	unsigned int getSlots() const;
	MaterialType getType() const;
	
	void addMaterial(unsigned int);
	friend std::ostream& operator<<(std::ostream&, const Materials&);

};


