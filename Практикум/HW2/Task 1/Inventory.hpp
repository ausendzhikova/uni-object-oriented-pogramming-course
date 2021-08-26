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
#include<iostream>
template <typename T> class Inventory;
template <typename T> std::ostream& operator<<(std::ostream&, const Inventory<T>&);

template<typename T>
class Inventory {
	T inventory;
public:
	Inventory() = default;
	Inventory(T);
	Inventory(const Inventory&);
	Inventory<T>& operator=(const Inventory<T>&);
	unsigned int getSlots() const;

	
	bool operator==(Inventory&);
	bool operator!=(Inventory&);
	friend std::ostream& operator<< <T>(std::ostream&, const Inventory<T>&);
	
};

template<typename T>
inline Inventory<T>::Inventory(T inventory) {
	this->inventory = inventory;
}
	

template<typename T>
inline Inventory<T>::Inventory(const Inventory& other) {
	this->inevntory = other.inventory;
}

template<typename T>
inline Inventory<T>& Inventory<T>::operator=(const Inventory<T>& rhs) {
	if (this != &rhs) {
		this->inventory = rhs.inventory;
	}
	return *this;
}

template<typename T>
inline unsigned int Inventory<T>::getSlots() const {
	return inventory.getSlots();
}

template<typename T>
inline bool Inventory<T>::operator==(Inventory& rhs) {
	if ( inventory.getSlots()== rhs.getSlots()) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Inventory<T>::operator!=(Inventory&) {
	if (inventory.getSlots() != inventory.getSlots()) {
		return true;
	}
	return false;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Inventory<T>& to_print) {
	o << "Inventory: " << std::endl;
	o << to_print.inventory << std::endl;
	return o;
}

