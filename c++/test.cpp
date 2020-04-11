#include <iostream>
#include "vector.hpp"
#include "point.hpp"

int main () {
    Vector x, y(1, 2);
    Vector z = x + y;
    Point a (x, y);
    a.update(0);
    a.addForce(z);
    a.resetForce();
    return 0;
}
