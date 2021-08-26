#include "Request.hpp"


Request::Request(const std::string& message, const std::string& sender) {
	counter++;
	this->message = message;
	this->sender = sender;
	this->ID = counter;
}

std::string Request::getMessage() const {
	return this->message;
}

std::string Request::getSender() const {
	return this->sender;
}


unsigned int Request::getCount() {
	return counter;
}


int Request::getID() const {
	return this->ID;
}
unsigned int Request::counter = 0;
