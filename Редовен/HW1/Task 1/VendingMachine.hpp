#pragma once
#include "drink.hpp"
class VendingMachine {
private:
	// Add whatever you deem needed here
	Drink* drinks;
	double income;
	//variables for add_drink
	int capacity;
	int memberCount = 0;
	//variable for buy_drink
	int index;
public:
	VendingMachine();
	VendingMachine(const VendingMachine& from);
	VendingMachine& operator=(const VendingMachine& from);

	bool add_drink(const Drink& to_add);
	int buy_drink(const char* drink_name, const double money);

	double get_income() const;

	// Add whatever you deem needed here
	bool isConsist(const char* drink_name);
	void erase_drink(const char* drink_name);
	~VendingMachine();


};

