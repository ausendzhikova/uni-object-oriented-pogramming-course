#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& initialID, size_t initialPeriod) :Subscriber(initialID), period(initialPeriod) {
}

int PeriodicSampler::read() const {
	if (messages.empty()) {
		return 0;
	}
	return messages[messages.size() - 1];
}

void PeriodicSampler::signal(Message newMessage) {
	if (messages.empty()) {
		messages.push_back(newMessage.data);
		return;
	}
	++n;
	if (n % period == 0) {
		messages.push_back(newMessage.data);
	}
}

Subscriber* PeriodicSampler::clone() const {
	return new PeriodicSampler(*this);
}
