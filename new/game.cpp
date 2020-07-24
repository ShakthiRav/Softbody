#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <shape.hpp>
#include <point.hpp>
#include <shape.hpp>
#include <spring.hpp>
void update (double dt) {
  double minTimeStep = 0.0005, timeStep;
  while (1) {
    timeStep = dt;
    if (dt > minTimeStep) {
      timeStep = minTimeStep;
    }
    dt -= timeStep;
    // update using timeStep
    
    if (dt <= 0) break;
  }
}

void render (sf::RenderWindow &) {
    
    
}

int main()
{

    
    std::vector<Point> points;
    Point p1 = Point(Vector(500,50), Vector(0,0));
    Point p2 =Point(Vector(500,250), Vector(-0,0));
    points.push_back(p1);
    points.push_back(p2);
    
    
    
    Shape obj = Shape(points);
    Spring spring = Spring(obj.points[0] ,obj.points[1], 1e10,0);

    obj.springs.push_back(spring);
  // Init
  int width = 1200;
  int height = 9 * width / 16;
  sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(width, height), "Softbody sim");
  double cycles =10000;
  while (window.isOpen())
  {
    double elapsed = clock.restart().asSeconds();
    double deltaTime = 1e-6;

    
    // Handle events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
      
      for(int i =0 ; i <cycles;i++){
          obj.update(deltaTime);
      }

      obj.render(window);
    window.display();
  }

  return 0;
}
