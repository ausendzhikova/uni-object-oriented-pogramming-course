#include "Semaphore.hpp"

Semaphore::Semaphore(const Semaphore& other) : LimitedTwowayCounter(other) {
}

Semaphore::Semaphore() : LimitedTwowayCounter(0, 1, 0, 1) {
}

Semaphore::Semaphore(bool initial) : LimitedTwowayCounter(0, 1, 0, 1) {
	if (initial == true) {
		this->initial = 1;
	}
}

bool Semaphore::isAvailable() const {
	if (this->initial > 0) {
		return true;
	}
	return false;
}

void Semaphore::wait() {
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal() {
	LimitedTwowayCounter::increment();
}
