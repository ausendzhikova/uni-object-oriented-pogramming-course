#pragma once
#include "Publisher.hpp"

class SimplePublisher :public Publisher {
public:
	SimplePublisher() = default;
	void subscribe(Averager*) override;
	void subscribe(MovingAverager*)override;
	void subscribe(PeriodicSampler*)override;
};