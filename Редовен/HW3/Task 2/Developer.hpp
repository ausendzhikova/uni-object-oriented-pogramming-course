#pragma once
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <string>
#include <cmath>
#include <limits>
class TeamLead;
class Developer {
protected:
	std::string name;
	double salary;
	TeamLead* teamLead_ptr;

public:
	Developer(const std::string name, double salary);

	Developer(const std::string name);
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;
	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);


};

bool isEqual(double x, double y);


