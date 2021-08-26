#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const LimitedTwowayCounter& other) : Counter(other), TwowayCounter(other), LimitedCounter(other) {
	this->min = other.min;
}


LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : Counter(), TwowayCounter(), LimitedCounter(max) {
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) : Counter(initial), TwowayCounter(initial), LimitedCounter(max, initial) {
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step) : Counter(initial, step),
TwowayCounter(initial, step), LimitedCounter(max, initial, step) {
	this->min = min;
}

void LimitedTwowayCounter::increment() {
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
	int temp = initial - step;
	if (temp < min) {
		return;
	}
	initial -= step;
}

int LimitedTwowayCounter::getMin() const {
	return this->min;
}

int LimitedTwowayCounter::getMax() const {
	return LimitedCounter::getMax();
}





