#include "Averager.hpp"

Averager::Averager(const std::string& initialID) : Subscriber(initialID) {
}

int Averager::read()const {
	if (messages.empty()) {
		return 0;
	}
	int sum = 0;
	for (auto x : messages) {
		sum += x;
	}
	return sum / messages.size();
}

void Averager::signal(Message newMessage) {
	messages.push_back(newMessage.data);
}

Subscriber* Averager::clone() const {
	return new Averager(*this);
}


