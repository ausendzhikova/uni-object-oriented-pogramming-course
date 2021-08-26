#pragma once
#include<limits>
#include <cmath>
#include <iostream>
// Add all other required methods and fields of the class.

class Vector4D {

public:
    Vector4D() = default;
    Vector4D(const Vector4D& other);
    Vector4D(double, double, double, double);
    Vector4D& operator=(const Vector4D& rhs);
    double& operator[](int);
    Vector4D operator+(const Vector4D& other) const;
    Vector4D& operator+=(const Vector4D& other);
    Vector4D operator-(const Vector4D& other) const;
    Vector4D& operator-=(const Vector4D& other);
    Vector4D operator*(const Vector4D& other) const;
    Vector4D& operator*=(const Vector4D& other);
    Vector4D operator*(const double& x) const;
    Vector4D& operator*=(const double& x);
    Vector4D operator/(const Vector4D& other) const;
    Vector4D& operator/=(const Vector4D& other);
    bool operator==(const Vector4D& other) const;
    bool operator!=(const Vector4D& other) const;
    bool operator<(const Vector4D& other) const;
    bool operator>(const Vector4D& other) const;
    bool operator<=(const Vector4D& other) const;
    bool operator>=(const Vector4D& other) const;
    bool operator!() const;
    Vector4D operator-() const;

    //for test
    void print();

private:
    double values[4];
};

bool isEqual(double x, double y);

