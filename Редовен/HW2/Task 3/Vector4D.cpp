#include "Vector4D.hpp"

Vector4D::Vector4D(const Vector4D& other) {
	for (size_t i = 0; i < 4; i++) {
		values[i] = other.values[i];
	}
}

Vector4D::Vector4D(double a, double b, double c, double d) {
	values[0] = a;
	values[1] = b;
	values[2] = c;
	values[3] = d;
}

Vector4D& Vector4D::operator=(const Vector4D& rhs) {
	if (this != &rhs) {
		for (size_t i = 0; i < 4; i++) {
			values[i] = rhs.values[i];
		}
	}
	return *this;
}

double& Vector4D::operator[](int index) {
	if (index == 0) {
		return values[0];
	}
	if (index == 1) {
		return values[1];
	}
	if (index == 2) {
		return values[2];
	}
	return values[3];
}

Vector4D Vector4D::operator+(const Vector4D& other) const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = values[i] + other.values[i];
	}
	return Vector4D(v);
}

Vector4D& Vector4D::operator+=(const Vector4D& other) {
	for (size_t i = 0; i < 4; i++) {
		values[i] += other.values[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other) const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = values[i] - other.values[i];
	}
	return v;
}

Vector4D& Vector4D::operator-=(const Vector4D& other) {
	for (size_t i = 0; i < 4; i++) {
		values[i] -= other.values[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = values[i] * other.values[i];
	}
	return v;
}

Vector4D& Vector4D::operator*=(const Vector4D& other) {
	for (size_t i = 0; i < 4; i++) {
		values[i] *= other.values[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const double& x) const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = x * values[i];
	}
	return v;
}

Vector4D& Vector4D::operator*=(const double& x) {
	for (size_t i = 0; i < 4; i++) {
		values[i] = x * values[i];
	}
	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = values[i] / other.values[i];
	}
	return v;
}

Vector4D& Vector4D::operator/=(const Vector4D& other) {
	for (size_t i = 0; i < 4; i++) {
		values[i] /= other.values[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (!isEqual(values[i], other.values[i])) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (!isEqual(values[i], other.values[i])) {
			return true;
		}
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (values[i] <other.values[i]) {
			return true;
		}
	}
	return false;
}

bool Vector4D::operator>(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (values[i] > other.values[i]) {
			return true;
		}
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (values[i] > other.values[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator>=(const Vector4D& other) const {
	for (size_t i = 0; i < 4; i++) {
		if (values[i] < other.values[i]) {
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!() const {
	for (size_t i = 0; i < 4; i++) {
		if (!isEqual(values[i], 0)) {
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator-() const {
	Vector4D v;
	for (size_t i = 0; i < 4; i++) {
		v.values[i] = -values[i];
	}
	return v;
}

void Vector4D::print() {
	std::cout << "Vector4D( ";
	for (size_t i = 0; i < 4; i++) {
		if (i != 3) {
			std::cout << values[i] << ", ";
		}
		else {
			std::cout << values[i] << " )" << std::endl;
		}
	}
	return;

}

bool isEqual(double x, double y) {
	if (x - y < std::numeric_limits<double>::epsilon()) {
		return true;
	}
	return false;
}
