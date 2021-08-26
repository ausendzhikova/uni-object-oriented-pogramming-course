#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* avg_ptr) {
	if (avg_ptr != nullptr) {
		subscribers.push_back(avg_ptr);
		for (size_t i = 0; i < messages.size(); i++) {
			subscribers[subscribers.size() - 1]->signal(messages[i]);
		}
	}
}

void BacklogPublisher::subscribe(MovingAverager* mavg_ptr) {
	if (mavg_ptr != nullptr) {
		subscribers.push_back(mavg_ptr);
		for (size_t i = 0; i < messages.size(); i++) {
			subscribers[subscribers.size() - 1]->signal(messages[i]);
		}
	}
}

void BacklogPublisher::subscribe(PeriodicSampler* ps_ptr) {
	if (ps_ptr != nullptr) {
		subscribers.push_back(ps_ptr);
		for (size_t i = 0; i < messages.size(); i++) {
			subscribers[subscribers.size() - 1]->signal(messages[i]);
		}
	}
}
