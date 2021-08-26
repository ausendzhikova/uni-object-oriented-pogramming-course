#include "Document.hpp"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif
Document::Document(const std::string& name, const std::string& location, const std::string& extension) :Object(name, location, extension) {
}

void Document::write_line(const std::string& line) {
	lines.push_back(line);
}

std::string Document::read_line() {
	if (count - 1 >= lines.size()) {
		throw std::out_of_range("out_of_range");
	}
	count++;
	return lines[count - 2];
}

std::string Document::read_line(const unsigned line) {
	if (line - 1 >= lines.size()) {
		throw std::out_of_range("out_of_range");
	}
	count = line + 1;
	return lines[line - 1];
}

bool Document::operator==(const Comparable* other) const {
	Document* document_ptr = dynamic_cast<Document*>(const_cast<Comparable*>(other));
	if (!document_ptr) {
		return false;
	}
	if (this->lines.size() != document_ptr->lines.size()) {
		return false;
	}
	for (size_t i = 0; i < lines.size(); i++) {
		if (lines[i] != document_ptr->lines[i]) {
			return false;
		}
	}
	return true;
}

bool Document::operator!=(const Comparable* other) const {
	if (this == other) {
		return false;
	}
	return true;
}

std::string Document::to_string() const {
	std::string str;
	str = Object::to_string();
	for (size_t i = 0; i < lines.size(); i++) {
		str += lines[i] + '\n';
	}
	return str;
}

void Document::from_string(const std::string& str) {
	unsigned position = 0;
	unsigned len = 0;
	unsigned index = 0;
	Object::from_string(str);
	index = name.size() + location.size() + extension.size() + 2;
	position = ++index;
	len = 0;
	while (index < str.size()) {
		while (str[index] != '\n') {
			len++;
			index++;
		}
		lines.push_back(str.substr(position, len));
		position = ++index;
		len = 0;
	}
}

std::string Document::debug_print() const {
	std::string str;
	int lineNumber = 1;
	std::string lineStr;
	std::stringstream ss;
	ss << lineNumber;
	lineStr = ss.str();
	ss.str("");
	for (size_t i = 0; i < lines.size(); i++) {
		str += "Line " + lineStr + ":" + lines[i] + "\n";
		++lineNumber;
		ss << lineNumber;
		lineStr = ss.str();
		ss.str("");
	}
	return str;
}

Object* Document::clone() const {
	return new Document(*this);
}
