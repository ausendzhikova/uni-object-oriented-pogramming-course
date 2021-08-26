#pragma once
#include "Subscriber.hpp"

class MovingAverager :public Subscriber {
public:
	const size_t windowSize;
	MovingAverager(const std::string& initialID = " ", size_t initialWindowSize = 0);
	int read() const override;
	void signal(Message) override;
	Subscriber* clone() const override;
};