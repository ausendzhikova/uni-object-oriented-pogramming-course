#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
class Publisher {
protected:
public:
	std::vector<Subscriber*> subscribers;
	std::vector<Message> messages;
public:
	Publisher() = default;
	void unsubscribe(Averager*);
	void unsubscribe(MovingAverager*);
	void unsubscribe(PeriodicSampler*);
	void signal(Message);
	virtual void subscribe(Averager*) = 0;
	virtual void subscribe(MovingAverager*) = 0;
	virtual void subscribe(PeriodicSampler*) = 0;
	virtual ~Publisher() = 0;
};

