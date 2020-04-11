#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "vector.hpp"

class Point {
  private:
    double mass = 1;
    double mu = 0.3;
    double g = 9.8;

    Vector totalForce = Vector(0, g);

  public:
    Vector position;
    Vector prevPosition;

    Point (const Vector & position, const Vector & velocity);
    void update (double dt);
    void addForce (const Vector & force);
    void resetForce ();
};

#endif /* end of include guard: __POINT_HPP__ */
