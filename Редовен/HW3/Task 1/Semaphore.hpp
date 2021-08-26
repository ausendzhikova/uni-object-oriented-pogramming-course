#pragma once
#include "LimitedTwowayCounter.hpp"
#include <iostream>
class Semaphore : LimitedTwowayCounter {
public:
	Semaphore(const Semaphore& other);

	Semaphore();
	Semaphore(bool initial);
	bool isAvailable() const;
	void wait();
	void signal();
};

