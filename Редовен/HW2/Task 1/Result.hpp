#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
private:
	Optional<T> result;
	Optional<Error> error;
public:
	Result();
	Result(const T& result);
	Result(const std::string& error_message);

	Optional<T> get_result() const;
	Optional<Error> get_error() const;

	bool operator==(T&);
	bool operator==(Error&);

};

template<typename T>
inline Result<T>::Result() {
	this->result = nullptr;
}

template<typename T>
inline Result<T>::Result(const T& result) {
	this->result = result;
}

template<typename T>
inline Result<T>::Result(const std::string& error_message) {
	this->error = Optional<Error>(Error(error_message));
}

template<typename T>
inline Optional<T> Result<T>::get_result() const {
	return result;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const {
	return error;
}

template<typename T>
inline bool Result<T>::operator==(T& obj) {
	return get_error().is_none();
}

template<typename T>
inline bool Result<T>::operator==(Error& otherError) {
	return !get_error().is_none();
}



