#include "point.hpp"

Point::Point (const Vector & position, const Vector & velocity) :
  position(position) {
    prevPosition = position - velocity;
}

void Point::update (double dt) {

}

void Point::addForce (const Vector & f) {
  totalForce += f;
}

void Point::resetForce() {
  totalForce = Vector(0, 0);
}
  
