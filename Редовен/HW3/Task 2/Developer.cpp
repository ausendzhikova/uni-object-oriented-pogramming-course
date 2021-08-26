#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string name, double salary) {
	this->name = name;
	this->salary = salary;
	this->teamLead_ptr = nullptr;
}

Developer::Developer(const std::string name) : salary(0.0), teamLead_ptr(nullptr) {
	this->name = name;
}

std::string Developer::getName() const {
	return this.name;
}

double Developer::getSalary() const {
	return this->salary;
}

TeamLead* Developer::getTeamLead() const {
	return this->teamLead_ptr;
}


void Developer::setInitialSalary(double amount) {
	if (isEqual(salary, 0)) {
		this->salary += amount;
	}
}

void Developer::sendLeavingRequest() {
	if (teamLead_ptr != nullptr) {
		LeavingRequest leavingRequest(this->name);
		teamLead_ptr->addLeavingRequest(leavingRequest);
	}
}

void Developer::sendPromotionRequest(double amount) {
	if (teamLead_ptr != nullptr) {
		PromotionRequest promotionRequest(this->name, amount);
		teamLead_ptr->addPromotionRequest(promotionRequest);
	}
}


bool isEqual(double x, double y) {
	if (x - y < std::numeric_limits<double>::epsilon()) {
		return true;
	}
	return false;
}



