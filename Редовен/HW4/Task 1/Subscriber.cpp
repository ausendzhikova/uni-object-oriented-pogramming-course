#include "Subscriber.hpp"

Subscriber::Subscriber(const std::string& initialID) : id(initialID) {
}

Subscriber::~Subscriber() {
}

std::vector< int> Subscriber::getMessages() const {
	return this->messages;
}
