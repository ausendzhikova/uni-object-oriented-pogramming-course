#pragma once
#include "Object.hpp"
#include <vector>
#include <stdexcept>
#include <sstream>
class Document : public Object {
	std::vector<std::string> lines;
	unsigned count = 1;
public:
	Document(const std::string& name, const std::string& location, const std::string& extension);

	void write_line(const std::string& line);

	std::string read_line();
	std::string read_line(const unsigned line);
	bool operator==(const Comparable*) const override;
	bool operator!=(const Comparable*)const override;
	std::string to_string() const override;
	void from_string(const std::string&) override;
	std::string debug_print() const override;
	Object* clone() const override;
};