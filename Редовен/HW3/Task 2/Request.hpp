#pragma once
#include <string>
class Request {
protected:
	std::string message;
	std::string sender;
	int ID = counter;
	static unsigned int counter;
public:

	Request(const std::string& message, const std::string& sender);
	std::string getMessage() const;
	std::string getSender() const;
	static unsigned int getCount();
	int getID() const;

};

