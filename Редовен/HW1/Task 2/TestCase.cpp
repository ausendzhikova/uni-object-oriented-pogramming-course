#include "TestCase.hpp"


TestCase::TestCase(const std::string& name, const Error& error) {
	this->name = name;
	if (error.getType() != ErrorType::None) {
		this->error = error;
	}
}


std::string TestCase::getName() const {

	return name;
}

bool TestCase::isPassing() const {
	if (ErrorType::None == error.getType() || error.getType() == ErrorType::Warning) {
		return true;
	}
	return false;
}

bool TestCase::hasError() const {
	if (error.getType() != ErrorType::None) {
		return true;
	}
	return false;
}

ErrorType TestCase::getErrorType() const {
	if (hasError()) {
		return error.getType();
	}
	return ErrorType::None;
}

std::string TestCase::getErrorMessage() const {
	if (hasError()) {

		return error.getMessage();
	}
	return "";
}
