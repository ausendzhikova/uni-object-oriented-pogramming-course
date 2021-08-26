#pragma once
#include "Serializable.hpp"
#include "Comparable.hpp"
#include "Debug.hpp"
class Object : public Debug, public Comparable, public Serializable {
protected:
	std::string name;
	std::string location;
	std::string extension;

public:
	Object(const std::string& name, const std::string& location, const std::string& extension);

	std::string get_name() const;
	std::string get_location() const;
	std::string get_extension() const;
	std::string get_fullpath() const;

	std::string to_string() const override;
	void from_string(const std::string&) override;

	virtual Object* clone() const = 0;
};