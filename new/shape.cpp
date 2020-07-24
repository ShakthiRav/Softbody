#include <SFML/Graphics.hpp>
#include "spring.hpp"
#include "point.hpp"
#include "shape.hpp"

Shape::Shape () { }

Shape::Shape (const std::vector<Point> & points) :
  points(points) { }

void Shape::update (double dt) {
  for (Point & p : points) {
    p.resetAcceleration();
  }
    
    //springs[0].applyForce();
  for (Spring & s : springs) {
    s.applyForce();
  }

  for (Point & p : points) {
    p.update(dt);
  }
  // need to get all
    
}

void Shape::render (sf::RenderWindow & window) {
    sf::Color background(0xfaf4edff);
    sf::Color foreground(0x0d0c0cff);
    window.clear(background);
    sf::VertexArray va(sf::LineStrip, 2);

    va[0].position = sf::Vector2f(points[0].position.x, points[0].position.y);
    va[1].position = sf::Vector2f(points[1].position.x, points[1].position.y);

    va[0].color = foreground;
    va[1].color = foreground;

    
    window.draw(va);

  
}
