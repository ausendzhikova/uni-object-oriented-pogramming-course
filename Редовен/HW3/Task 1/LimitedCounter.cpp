#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const LimitedCounter& other) : Counter(other) {
	this->max = other.max;
}

LimitedCounter::LimitedCounter(int max) : Counter() {
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial) {
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step) : Counter(initial, step) {
	this->max = max;
}

void LimitedCounter::increment() {
	int temp = initial + step;
	if (temp > max) {
		return;
	}
	initial += step;
}

int LimitedCounter::getMax() const {
	return this->max;
}
