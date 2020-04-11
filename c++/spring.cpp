#include "point.hpp"
#include "vector.hpp"
#include "spring.hpp"

Spring::Spring (Point & start, Point & end, double k, double lambda) :
  start(&start), end(&end), k(k), lambda(lambda) {
  Vector ds = start.position - end.position;
  prevLen = natLen = ds.norm();
}

void Spring::applyForce () {
  Vector ds = start->position - end->position;
  double d = ds.norm();
  double e = (d - natLen) / natLen;

  Vector force = -(e * k / d) * ds;
  start->addForce(force);
  end->addForce(-force);
}
