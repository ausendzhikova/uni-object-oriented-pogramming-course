#include "Counter.hpp"

Counter::Counter(const Counter& other) {
	this->initial = other.initial;
	this->step = other.step;
}


Counter::Counter(int initial, unsigned step) {
	this->initial = initial;
	this->step = step;
}

void Counter::increment() {
	this->initial += step;
}

int Counter::getTotal() const {
	return this->initial;
}

unsigned Counter::getStep() const {
	return this->step;
}

