#include <cmath>
#include "vector.hpp"

Vector::Vector () : Vector (0, 0) {}

Vector::Vector (double x, double y) :
  x(x), y(y) {}

  Vector Vector::operator+ () const {
    return Vector(x, y);
  }

Vector Vector::operator- () const {
  return Vector(-x, -y);
}

Vector Vector::operator+ (const Vector & rhs) const {
  return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator- (const Vector & rhs) const {
  return Vector(x - rhs.x, y + rhs.y);
}

Vector Vector::operator* (double a) const {
  return Vector(a * x, a * y);
}

Vector Vector::operator/ (double a) const {
  return Vector(x / a, y / a);
}

Vector& Vector::operator+= (const Vector & rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Vector& Vector::operator-= (const Vector & rhs) {
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

Vector& Vector::operator*= (double a) {
  x *= a;
  y *= a;
  return *this;
}

Vector& Vector::operator/= (double a) {
  x /= a;
  y /= a;
  return *this;
}

double Vector::dot (const Vector & rhs) const {
  return x * rhs.x + y * rhs.y;
}

double Vector::norm () const {
  return std::sqrt(x*x + y*y);
}

Vector operator* (double a, const Vector & v) {
  return v * a;
}

