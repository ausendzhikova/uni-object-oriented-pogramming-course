#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& initialID, size_t initialWindowSize) :Subscriber(initialID), windowSize(initialWindowSize) {
}


int MovingAverager::read() const {
	if (messages.empty()) {
		return 0;
	}
	int sum = 0;
	for (auto x : messages) {
		sum += x;
	}
	if (messages.size() < windowSize) {
		return sum / messages.size();
	}
	return sum / windowSize;
}

void MovingAverager::signal(Message newMessage) {
	if (messages.size() == windowSize) {
		messages.erase(messages.begin());
	}
	messages.push_back(newMessage.data);
}

Subscriber* MovingAverager::clone() const {
	return new MovingAverager(*this);
}
