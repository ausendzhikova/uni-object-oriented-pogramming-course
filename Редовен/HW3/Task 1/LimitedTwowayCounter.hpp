#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"
class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter {
protected:
	int min;
public:
	LimitedTwowayCounter(const LimitedTwowayCounter& other);
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);
	void increment();
	void decrement();
	int getMin() const;
	int getMax() const;

};

