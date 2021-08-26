#include "Publisher.hpp"

Publisher::~Publisher() {
}

void Publisher::unsubscribe(Averager* avg_ptr) {
	if (avg_ptr != nullptr) {
		int index = -1;
		for (size_t i = 0; i < subscribers.size(); i++) {
			if (subscribers[i]->id == avg_ptr->id) {
				Averager* avg = dynamic_cast<Averager*>(subscribers[i]);
				if (avg) {
					index = i;
					break;
				}
			}
		}
		if (index != -1) {
			subscribers.erase(subscribers.begin() + index);
		}
	}
}

void Publisher::unsubscribe(MovingAverager* mavg_ptr) {
	if (mavg_ptr != nullptr) {
		int index = -1;
		for (size_t i = 0; i < subscribers.size(); i++) {
			if (subscribers[i]->id == mavg_ptr->id) {
				MovingAverager* mavg = dynamic_cast<MovingAverager*>(subscribers[i]);
				if (mavg) {
					index = i;
					break;
				}
			}
		}
		if (index != -1) {
			subscribers.erase(subscribers.begin() + index);
		}
	}
}

void Publisher::unsubscribe(PeriodicSampler* ps_ptr) {
	if (ps_ptr != nullptr) {
		int index = -1;
		for (size_t i = 0; i < subscribers.size(); i++) {
			if (subscribers[i]->id == ps_ptr->id) {
				PeriodicSampler* ps = dynamic_cast<PeriodicSampler*>(subscribers[i]);
				if (ps) {
					index = i;
					break;
				}
			}
		}
		if (index != -1) {
			subscribers.erase(subscribers.begin() + index);
		}
	}
}

void Publisher::signal(Message newMessage) {
	messages.push_back(newMessage);
	for (auto x : subscribers) {
		x->signal(newMessage);
	}
}
