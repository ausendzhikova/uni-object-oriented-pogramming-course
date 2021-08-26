#pragma once
#include "Counter.hpp"
class TwowayCounter : virtual public Counter {
public:
	TwowayCounter(const TwowayCounter& other);

	TwowayCounter();
	TwowayCounter(int initial);
	TwowayCounter(int initial, unsigned step);
	void decrement();
};

