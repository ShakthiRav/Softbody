#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <vector>

namespace sf {
  class RenderWindow;
}

class Point;
class Spring;

class Shape {
  public:
    double k = 2500000 / 2;

    std::vector<Point> points;
    std::vector<Spring> springs;

    Shape ();
    Shape (const std::vector<Point> & points);

    void update (double dt);
    void render (sf::RenderWindow & window);
};

#endif /* end of include guard: __SHAPE_HPP__ */
