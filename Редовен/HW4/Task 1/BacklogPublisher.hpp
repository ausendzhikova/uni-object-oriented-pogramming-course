#pragma once
#include "Publisher.hpp"

class BacklogPublisher :public Publisher {
public:
	BacklogPublisher() = default;
	void subscribe(Averager*);
	void subscribe(MovingAverager*);
	void subscribe(PeriodicSampler*);
};