#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Repository {
	std::vector<Subscriber*> subscribers;
public:
	Repository() = default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	void add(Averager*);
	void add(MovingAverager*);
	void add(PeriodicSampler*);
	Subscriber* get(const std::string& id);
	~Repository();
};