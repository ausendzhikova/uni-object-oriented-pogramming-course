#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string name, double salary) : Developer(name, salary) {
	this->teamLead_ptr = this;
}

std::vector<Developer*> TeamLead::getTeam() const {
	return this->developers;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		developer->getTeamLead() = this;
		developers.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
	size_t j = 0;
	bool flag = false;
	for (size_t i = 0; i < developers.size(); i++) {
		if (developers[i]->getName() == name) {
			j = i;
			flag = true;
		}
	}
	if (flag) {
		developers[j]->getTeamLead() = nullptr;
		developers.erase(developers.begin() + j);
	}
}

void TeamLead::increaseTeamSalariesBy(double amount) {
	for (size_t i = 0; i < developers.size(); i++) {
		developers[i]->getSalary() += amount;
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
	for (size_t i = 0; i < developers.size(); i++) {
		developers[i]->getSalary() -= amount;
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
	leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
	promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
	for (size_t i = 0; i < leavingRequests.size(); i++) {
		for (size_t j = 0; j < developers.size(); j++) {
			if (leavingRequests[i].getSender() == developers[j]->getName()) {
				developers[j]->getTeamLead() = nullptr;
				developers.erase(developers.begin() + j);
				break;
			}
		}
	}
	leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests() {
	for (size_t i = 0; i < promotionRequests.size(); i++) {
		for (size_t j = 0; j < developers.size(); j++) {
			if (promotionRequests[i].getSender() == developers[j]->getName()) {
				developers[j]->getSalary() += promotionRequests[i].getAmount();
				break;
			}
		}
	}
	promotionRequests.clear();
}
