#pragma once
#include "Subscriber.hpp"

class PeriodicSampler :public Subscriber {
private:
	unsigned n = 0;
	size_t period;
public:
	PeriodicSampler(const std::string& initilID, size_t initialPeriod);
	int read() const override;
	void signal(Message) override;
	Subscriber* clone() const override;
};

