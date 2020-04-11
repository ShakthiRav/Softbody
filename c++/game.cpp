#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

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
  // Init
  int width = 1200;
  int height = 9 * width / 16;
  sf::RenderWindow window(sf::VideoMode(width, height), "Softbody sim");
  auto lastTime = std::chrono::system_clock::now();

  while (window.isOpen())
  {
    auto now = std::chrono::system_clock::now();
    double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastTime).count();
    deltaTime /= 1e6;
    lastTime = now;
    
    // Handle events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Update
    update(deltaTime);

    // Render
    sf::Color background(0xfaf4edff);
    sf::Color foreground(0x0d0c0cff);
    window.clear(background);
    sf::VertexArray va(sf::LineStrip, 3);
    va[0].position = sf::Vector2f(10, 10);
    va[1].position = sf::Vector2f(10, 100);
    va[2].position = sf::Vector2f(100, 10);
    va[0].color = foreground;
    va[1].color = foreground;
    va[2].color = foreground;
    window.draw(va);
    render(window);
    window.display();
  }

  return 0;
}
