#pragma once
#include<string>
#include <vector>
#include "Message.hpp"
class Subscriber {
protected:
	std::vector<int> messages;
public:
	const std::string id;
	Subscriber(const std::string& initialID = "");
	virtual void signal(Message) = 0;
	virtual int read() const = 0;
	std::vector<int> getMessages() const;
	virtual Subscriber* clone() const = 0;
	virtual ~Subscriber() = 0;
};

