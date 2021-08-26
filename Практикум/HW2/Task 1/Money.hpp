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
class Money {
	int silver;
	int gold;
public:
	Money() = default;
	Money(int, int);
	Money(const Money&);
	Money& operator=(const Money&);
	int getSilver()const;
	int getGold()const;
	unsigned int getSlots() const;
	void set_money();

	void addMoney(int, int);
	friend std::ostream& operator<<(std::ostream&, const Money&);
};

