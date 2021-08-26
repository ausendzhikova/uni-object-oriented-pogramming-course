#include "TestSuite.hpp"


TestSuite::TestSuite(std::string name) {
	this->name = name;
}

void TestSuite::add(const TestCase& newCase) {
	testCases.push_back(newCase);
}

std::vector<TestCase> TestSuite::filterPassing() const {
	std::vector<TestCase> passCases;
	for (int i = 0; i < testCases.size(); i++) {
		if (testCases[i].isPassing()) {
			passCases.push_back(testCases[i]);
		}
	}
	return passCases;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	std::vector<TestCase> failCases;
	for (int i = 0; i < testCases.size(); i++) {
		if (!testCases[i].isPassing()) {
			failCases.push_back(testCases[i]);
		}
	}
	return failCases;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const {
	std::vector<TestCase> casesByErrorType;
	for (int i = 0; i < testCases.size(); i++) {
		if (testCases[i].getErrorType() == errorType) {
			casesByErrorType.push_back(testCases[i]);
		}
	}
	return casesByErrorType;
}

void TestSuite::removeByErrorType(ErrorType errorType) {
	for (int i = 0; i < testCases.size(); i++) {
		if (testCases[i].getErrorType() == errorType) {
			testCases.erase(testCases.begin() + i);
		}
	}
}

std::string TestSuite::getName() const {
	return this->name;
}

void TestSuite::setName(const std::string& new_name) {
	this->name = new_name;
}

