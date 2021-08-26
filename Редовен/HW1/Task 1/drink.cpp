#include "drink.hpp"
#include <cstring>

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	calories = init_calories;
	quantity = init_quantity;
	price = init_price;
	int nameLen = strlen(init_name);
	name = new char[nameLen + 1];
	strcpy_s(name, nameLen + 1, init_name);

}

Drink::Drink(const Drink& copyFrom) {
	int nameLen = strlen(copyFrom.name);
	name = new char[nameLen + 1];
	strcpy_s(name, nameLen + 1, copyFrom.name);
	calories = copyFrom.calories;
	quantity = copyFrom.quantity;
	price = copyFrom.price;

}

Drink& Drink::operator=(const Drink& rhs) {
	if (this != &rhs) {
		set_name(rhs.name);
		quantity = rhs.quantity;
		calories = rhs.calories;
		price = rhs.price;
	}
	return *this;
}

const char* Drink::get_name() const {
	return name;
}

int Drink::get_calories() const {
	return calories;
}

double Drink::get_quantity() const {
	return quantity;
}

double Drink::get_price() const
{
	return price;
}

void Drink::set_name(const char* new_name) {
	int nameLen = strlen(new_name);
	delete[]name;
	name = new char[nameLen + 1];
	strcpy_s(name, nameLen + 1, new_name);

}

Drink::Drink() {
	name = nullptr;
	calories = 0;
	price = 0.0;
	quantity = 0.0;
}




Drink::~Drink() {
	delete[] name;
}
