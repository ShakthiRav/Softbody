#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "vector.hpp"

class Point {
  private:
    double mass = 1;
    double mu = 0.3;
    double g = 9.8;

    Vector totalAcceleration = Vector(0, g);

  public:
    Vector position;
    Vector prevPosition;

    Point (const Vector & position, const Vector & velocity);
    void update (double dt);
    void addForce (const Vector & force);
    void resetAcceleration ();
    void handleWallCollisions();
    void handleFloorCollisions();
};

#endif /* end of include guard: __POINT_HPP__ */
