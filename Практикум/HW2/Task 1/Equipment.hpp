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
#include<vector>
#include <iostream>
template <typename T> class Equipment;
template <typename T> std::ostream& operator<<(std::ostream&, const Equipment<T>&);

template<typename T>
class Equipment {
	std::vector<T> equipments;
	unsigned int slots;

public:
	Equipment() = default;
	Equipment(std::vector<T>, unsigned int);
	Equipment(const Equipment&);
	Equipment<T>& operator=(const Equipment<T>&);
	
	double getScore() const;
	unsigned int getSlots() const;
	void setSlots();
	bool isEmpty();
	bool isFull();
	void clearEquipment();
	void addInEquipment(T);
	void eraseFromEquipment(int);
	T theBestEquipment();
	bool operator==(Equipment&);
	bool operator!=(Equipment&);
 
	friend std::ostream& operator<< <T>(std::ostream&, const Equipment<T>&);
 };

template<typename T>
inline Equipment<T>::Equipment(std::vector<T> equipments, unsigned int slots) {
	this->equipments = equipments;
	this->slots = slots;
}

template<typename T>
inline Equipment<T>::Equipment(const Equipment& other) {
	this->equipments = other.equipments;
	this->slots = other.slots;
}

template<typename T>
inline Equipment<T>& Equipment<T>::operator=(const Equipment<T>& rhs) {
	if (this != &rhs) {
		this->equipments = rhs.equipments;
		this->slots = rhs.slots;
	}
	return *this;
}

template<typename T>
inline double Equipment<T>::getScore() const {
	double sumScore = 0;
	for (size_t i = 0; i < equipments.size(); i++) {
		sumScore += equipments[i].getScore();
	}
	return sumScore;
}

template<typename T>
inline unsigned int Equipment<T>::getSlots() const {
	return slots;
}

template<typename T>
inline void Equipment<T>::setSlots() {
	slots = 0;
	for (size_t i = 0; i < equipments.size(); i++) {
		slots += equipments[i].getSlots();
	}
}

template<typename T>
inline bool Equipment<T>::isEmpty() {
	if (slots == 0) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Equipment<T>::isFull() {
	if (slots == 24) {
		return true;
	}
	return false;
}

template<typename T>
inline void Equipment<T>::clearEquipment() {
	equipments.clear();
	slots = 0;
}

template<typename T>
inline void Equipment<T>::addInEquipment(T equipment) {
	if (isFull()) {
		std::cout << "Equipment is full!\n";
	}
	equipments.push_back(equipment);
	setSlots();
}

template<typename T>
inline void Equipment<T>::eraseFromEquipment(int index) {
	for (size_t i = 0; i < equipments.size(); i++) {
		if (i == index) {
			equipments.erase(equipments.begin() + i);
			setSlots();
			return;
		}
	}
}

template<typename T>
inline T Equipment<T>::theBestEquipment() {
	double score = equipments[0].getScore();
	double max = score;
	int index = 0;
	for (size_t i = 1; i < equipments.size(); i++) {
		score = equipments[i].getScore();
		if (max < score) {
			max = score;
			index = i;
		}
	}
	return T(equipments[index]);
}

template<typename T>
inline bool Equipment<T>::operator==(Equipment& rhs) {
	if (getScore() == rhs.getScore()) {
		return true;
	}
	return false;
}

template<typename T>
inline bool Equipment<T>::operator!=(Equipment& rhs){
	if (getScore() != rhs.getScore()) {
		return true;
	}
	return false;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Equipment<T>& to_print) {
	if (to_print.slots==0) {
		o << "Equipment is empty! " << std::endl;
		return o;
	}
	o << "This equipment has: " << to_print.slots << " slots." << std::endl;
	for (size_t i = 0; i < to_print.equipments.size(); i++) {
		o << to_print.equipments[i] << std::endl;
	}
	return o;
} 
