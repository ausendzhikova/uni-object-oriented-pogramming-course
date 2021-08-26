#include "Repository.hpp"

Repository::Repository(const Repository& other) {
	for (auto x : other.subscribers) {
		subscribers.push_back(x->clone());
	}
}

Repository& Repository::operator=(const Repository& rhs) {
	if (this != &rhs) {
		for (auto x : subscribers) {
			delete x;
		}
		subscribers.clear();
		for (auto x : rhs.subscribers) {
			subscribers.push_back(x->clone());
		}
	}
	return *this;
}

void Repository::add(Averager* ptr) {
	if (ptr) {
		subscribers.push_back(ptr->clone());
	}
}

void Repository::add(MovingAverager* ptr) {
	if (ptr) {
		subscribers.push_back(ptr->clone());
	}
}

void Repository::add(PeriodicSampler* ptr) {
	if (ptr) {
		subscribers.push_back(ptr->clone());
	}
}

Subscriber* Repository::get(const std::string& id) {
	int index = -1;
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == id) {
			index = i;
			break;
		}
	}
	if (index != -1) {
		Averager* avg = dynamic_cast<Averager*>(subscribers[index]);
		if (avg) {
			return avg;
		}
		MovingAverager* mavg = dynamic_cast<MovingAverager*>(subscribers[index]);
		if (mavg) {
			return mavg;
		}
		PeriodicSampler* psmp = dynamic_cast<PeriodicSampler*>(subscribers[index]);
		if (psmp) {
			return psmp;
		}

	}
	return nullptr;
}

Repository::~Repository() {
	for (auto x : subscribers) {
		delete x;
	}
}
