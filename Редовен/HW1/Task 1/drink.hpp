#pragma once
class Drink {
private:
	// Add whatever you deem needed here
	char* name;
	int calories;
	double quantity;
	double price;

public:
	Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
	Drink(const Drink&);
	Drink& operator=(const Drink&);

	const char* get_name() const;
	int get_calories() const;
	double get_quantity() const;
	double get_price() const;

	void set_name(const char* new_name);

	// Add whatever you deem needed here
	Drink();
	~Drink();



};

