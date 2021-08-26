#include "VendingMachine.hpp"
#include <cstring>

VendingMachine::VendingMachine() {
	capacity = 1;
	index = 0;
	drinks = new Drink[capacity];
	income = 0.0;
}

VendingMachine::VendingMachine(const VendingMachine& from) {
	drinks = new Drink[from.memberCount];
	for (int i = 0; i < memberCount; i++) {
		drinks[i] = from.drinks[i];
	}
	income = from.income;
	memberCount = from.memberCount;
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		delete[]drinks;
		drinks = new Drink[from.memberCount];
		for (int i = 0; i < memberCount; i++) {
			drinks[i] = from.drinks[i];
		}
		income = from.income;
		memberCount = from.memberCount;
	}
	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add) {
	if (!isConsist(to_add.get_name())) {
		Drink* newDrinks = new Drink[capacity += 1];
		for (size_t i = 0; i < memberCount; i++) {
			newDrinks[i] = drinks[i];
		}
		delete[] drinks;
		drinks = newDrinks;
		capacity += 1;
		drinks[memberCount] = to_add;
		memberCount += 1;
		return true;

	}

	return false;
}

int VendingMachine::buy_drink(const char* drink_name, const double money) {
	if (isConsist(drink_name) && money >= drinks[index].get_price()) {
		income += money;
		erase_drink(drink_name);
		return 0;
	}
	if (isConsist(drink_name) && money != drinks[index].get_price()) {
		income += money;
		return 1;
	}
	return 2;
}

double VendingMachine::get_income() const {
	return income;
}

bool VendingMachine::isConsist(const char* drink_name) {
	for (size_t i = 0; i < memberCount; i++) {
		if (strcmp(drinks[i].get_name(), drink_name) == 0) {
			index = i;
			return true;
		}
	}
	return false;
}

void VendingMachine::erase_drink(const char* drink_name) {
	Drink* newDrinks = new Drink[capacity -= 1];
	for (size_t i = 0, j = 0; i < memberCount; i++) {
		if (strcmp(drinks[i].get_name(), drink_name) == 0) {
			continue;
		}
		newDrinks[j] = drinks[i];
		j++;
	}
	delete[]drinks;
	drinks = newDrinks;
	capacity -= 1;
	memberCount -= 1;
	return;
}

VendingMachine::~VendingMachine() {
	delete[]drinks;
}

