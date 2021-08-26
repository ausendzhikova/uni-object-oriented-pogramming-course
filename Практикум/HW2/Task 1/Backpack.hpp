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
#include<vector>
#include <typeinfo>
#include "Money.hpp"
#include "Materials.hpp"
template <typename T> class Backpack;
template <typename T> std::ostream& operator<<(std::ostream&, const Backpack<T>&);

template<typename T>
class Backpack {
	std::vector<T> bag;
	unsigned int slots;
public:
	Backpack() = default;
	Backpack(std::vector<T>, unsigned int);
	Backpack(const Backpack&);
	Backpack<T>& operator=(const Backpack<T>&);

	unsigned int getSlots()const;
	void setSlots();
	bool isEmpty();
	bool isFull();
	void clearBackpack();
	void addInBackpack(T);
	void eraseFromBackpack(int);
	friend std::ostream& operator<< <T>(std::ostream&, const Backpack<T>&);
};

template<typename T>
inline Backpack<T>::Backpack(std::vector<T> bag, unsigned int slots) {
	this > bag = bag;
	this->slots = slots;
}

template<typename T>
inline Backpack<T>::Backpack(const Backpack& other) {
	this->bag = other.bag;
	this->slots = other.slots;
}

template<typename T>
inline Backpack<T>& Backpack<T>::operator=(const Backpack<T>& rhs) {
	if (this != &rhs) {
		this->bag = rhs.bag;
		this->slots = rhs.slots;
	}
	return *this;
}

template<typename T>
inline unsigned int Backpack<T>::getSlots() const {
	return slots;
}


template<typename T>
inline void Backpack<T>::setSlots() {
	if (typeid(T) == typeid(Money)) {
		slots = 1;
		return;
	}
	if (typeid(T) == typeid(Materials)) {
		slots = 0;
		for (size_t i = 0; i < bag.size(); i++) {
			slots += bag[i].getSlots();
		}
		return;
	}
}



template<typename T>
inline bool Backpack<T>::isEmpty() {
	if (slots == 0) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Backpack<T>::isFull() {
	if (slots == 16) {
		return true;
	}
	return false;
}

template<typename T>
inline void Backpack<T>::clearBackpack() {
	bag.clear();
	slots = 0;
}

template<typename T>
inline void Backpack<T>::addInBackpack(T bagThing) {
	if (isFull()) {
		std::cout << "Backpack is full!\n";
		return;
	}

	bag.push_back(bagThing);
	setSlots();
}

template<typename T>
inline void Backpack<T>::eraseFromBackpack(int index) {
	for (size_t i = 0; i < bag.size(); i++) {
		if (i == index) {
			bag.erase(bag.begin() + i);
			setSlots();
			return;
		}
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Backpack<T>& to_print) {
	if (to_print.slots == 0) {
		o << "Backpack is empty! " << std::endl;
		return o;
	}
	o << "This backpack has: " << to_print.slots << " slots." << std::endl;
	for (size_t i = 0; i < to_print.bag.size(); i++) {
		o << to_print.bag[i];
	}
	return o;
}