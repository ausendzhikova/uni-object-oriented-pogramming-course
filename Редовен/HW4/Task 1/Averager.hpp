#pragma once
#include "Subscriber.hpp"

class Averager :public Subscriber {
public:
	Averager(const std::string& initialID = "");
	int read()const override;
	void signal(Message) override;
	Subscriber* clone() const override;
};