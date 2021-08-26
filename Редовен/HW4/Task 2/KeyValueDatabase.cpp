#include "KeyValueDatabase.hpp"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension) : Object(name, location, extension) {
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
	for (size_t i = 0; i < key_value.size(); i++) {
		if (key_value[i].first == entry.first) {
			throw std::invalid_argument("invalid_argument");
		}
	}
	key_value.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const {
	for (size_t i = 0; i < key_value.size(); i++) {
		if (key_value[i].first == key) {
			return key_value[i].second;
		}
	}
	throw std::invalid_argument("invalid_argument");
}

bool KeyValueDatabase::operator==(const Comparable* other) const {
	KeyValueDatabase* ptr = dynamic_cast<KeyValueDatabase*>(const_cast<Comparable*>(other));
	if (!ptr) {
		return false;
	}
	if (this->key_value.size() != ptr->key_value.size()) {
		return false;
	}
	for (size_t i = 0; i < key_value.size(); i++) {
		if (this->key_value[i] != ptr->key_value[i]) {
			return false;
		}
	}
	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* other) const {
	if (this == other) {
		return false;
	}
	return true;
}

std::string KeyValueDatabase::to_string() const {
	std::string str;
	str = Object::to_string();
	for (size_t i = 0; i < key_value.size(); i++) {
		str += key_value[i].first + ":";
		std::stringstream ss;
		std::string valueStr;
		ss << key_value[i].second;
		valueStr = ss.str();
		ss.str("");
		str += valueStr + "\n";
	}
	return str;
}

void KeyValueDatabase::from_string(const std::string& str) {
	unsigned position = 0;
	unsigned len = 0;
	unsigned index = 0;
	Object::from_string(str);
	index = name.size() + location.size() + extension.size() + 2;
	position = ++index;
	len = 0;
	while (index < str.size()) {
		while (str[index] != ':') {
			len++;
			index++;
		}
		std::string key = str.substr(position, len);
		position = ++index;
		len = 0;
		while (str[index] != '\n') {
			len++;
			index++;
		}
		int value = std::stoi(str.substr(position, len));
		position = ++index;
		len = 0;

		std::pair<std::string, int> toAdd;
		toAdd.first = key;
		toAdd.second = value;
		key_value.push_back(toAdd);
	}
}

std::string KeyValueDatabase::debug_print() const {
	std::string str = "";
	for (size_t i = 0; i < key_value.size(); i++) {
		str += "{" + key_value[i].first + ":";
		std::stringstream ss;
		std::string valueStr;
		ss << key_value[i].second;
		valueStr = ss.str();
		ss.str("");
		str += valueStr + "}\n";
	}
	return str;
}

Object* KeyValueDatabase::clone() const {
	return new KeyValueDatabase(*this);
}
