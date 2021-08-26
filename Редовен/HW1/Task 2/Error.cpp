#include "Error.hpp"

Error& Error::operator=(const Error& rhs) {
	if (this != &rhs) {
		int len = strlen(rhs.message);
		delete[]message;
		message = new char[len + 1];
		strcpy_s(this->message, len + 1, rhs.message);
		this->type = rhs.type;
	}
	return *this;
}

Error::Error(const Error& rhs) {
	if (rhs.type == ErrorType::None) {
		message = nullptr;
	}
	else {
		int len = strlen(rhs.message);
		message = new char[len + 1];
		strcpy_s(this->message, len + 1, rhs.message);
	}

	this->type = rhs.type;
}


bool Error::hasMessage() const {
	if (getMessage() != nullptr) {
		return true;
	}
	return false;
}

const char* Error::getMessage() const {
	return this->message;
}

ErrorType Error::getType() const {
	return this->type;
}

Error Error::newNone() {
	Error errorNone;
	errorNone.type = ErrorType::None;
	return Error(errorNone);
}

Error Error::newBuildFailed(const char* message) {
	Error buildError;
	buildError.type = ErrorType::BuildFailed;
	int len = strlen(message);
	delete[] buildError.message;
	buildError.message = new char[len + 1];
	strcpy_s(buildError.message, len + 1, message);

	return Error(buildError);
}

Error Error::newWarning(const char* message) {
	Error warningError;
	warningError.type = ErrorType::Warning;
	int len = strlen(message);
	delete[]warningError.message;
	warningError.message = new char[len + 1];
	strcpy_s(warningError.message, len + 1, message);
	return Error(warningError);
}

Error Error::newFailedAssertion(const char* message) {
	Error failedError;
	failedError.type = ErrorType::FailedAssertion;
	int len = strlen(message);
	delete[]failedError.message;
	failedError.message = new char[len + 1];
	strcpy_s(failedError.message, len + 1, message);
	return Error(failedError);
}

Error::~Error() {
	delete[] message;
}
