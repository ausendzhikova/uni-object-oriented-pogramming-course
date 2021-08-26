#include "Object.hpp"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
Object::Object(const std::string& name, const std::string& location, const std::string& extension) {
	this->name = name;
	this->location = location;
	this->extension = extension;
}

std::string Object::get_name() const {
	return this->name;
}

std::string Object::get_location() const {
	return this->location;
}

std::string Object::get_extension() const {
	return this->extension;
}

std::string Object::get_fullpath() const {
	std::string fullpath = location + "/" + name + "." + extension;
	return fullpath;
}

std::string Object::to_string() const {
	std::string str;
	str = name + '\n' + location + '\n' + extension + '\n';
	return str;
}

void Object::from_string(const std::string& str) {
	unsigned position = 0;
	unsigned len = 0;
	unsigned index = 0;
	while (str[index] != '\n') {
		len++;
		index++;
	}
	name = str.substr(position, len);
	position = ++index;
	len = 0;
	while (str[index] != '\n') {
		len++;
		index++;
	}
	location = str.substr(position, len);
	position = ++index;
	len = 0;
	while (str[index] != '\n') {
		len++;
		index++;
	}
	extension = str.substr(position, len);
}


