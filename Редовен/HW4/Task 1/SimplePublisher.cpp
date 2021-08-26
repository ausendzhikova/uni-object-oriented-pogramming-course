#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* avg_ptr) {
	if (avg_ptr != nullptr) {
		subscribers.push_back(avg_ptr);
	}
}

void SimplePublisher::subscribe(MovingAverager* mavg_ptr) {
	if (mavg_ptr != nullptr) {
		subscribers.push_back(mavg_ptr);
	}
}

void SimplePublisher::subscribe(PeriodicSampler* ps_ptr) {
	if (ps_ptr != nullptr) {
		subscribers.push_back(ps_ptr);
	}
}
