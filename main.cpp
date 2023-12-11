#include <SFML/Graphics.hpp>
#include <iostream>

const int windowWidth = 8000;
const int windowHeight = 5000;
const int gridSizeX = 400;
const int gridSizeY = 250;
const int cellSize = 20;

int main()
{
  // Create SFML window
  sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Grid");
  // Create view
  sf::View view(sf::FloatRect(0, 0, 1920, 1080));
  window.setView(view);
  // Get Mouse Positions
  sf::Vector2f oldPos;
  bool moving = false;
  // Zoom variable
  float zoom = 1;

  sf::Vector2i startMousePos;
  sf::Vector2i prevMousePos;
  // Timing variables
  sf::Clock clock;
  sf::Time elapsed;
  // Window loop
  while (window.isOpen()) {
    // Measure the time elapsed since the last frame
    sf::Time deltaTime = clock.restart();
    elapsed += deltaTime;
    // Event polling
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::MouseWheelScrolled && !moving) {
        if (event.mouseWheelScroll.delta <= -1) {
          zoom = std::min(4.f, zoom + .1f);
        } else if (event.mouseWheelScroll.delta >= 1) {
          zoom = std::max(.5f, zoom - .1f);
        }

        view.setSize(window.getDefaultView().getSize());
        view.zoom(zoom);
        window.setView(view);
      }
      // Handle mouse events
      if (event.type == sf::Event::MouseButtonPressed) {
        // Mouse button is pressed, get the position and set moving as active
        if (event.mouseButton.button == 0) {
          moving = true;
          oldPos = sf::Vector2f(sf::Mouse::getPosition(window));
        }
      }
      if (event.type == sf::Event::MouseButtonReleased) {
        // Mouse button is released, no longer move
        if (event.mouseButton.button == 0) {
          moving = false;
        }
      }
      if (event.type == sf::Event::MouseMoved && moving) {
        // Determine the new position in world coordinates
        const sf::Vector2f newPos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
        // Swap these to invert the movement direction
        sf::Vector2f deltaPos = (oldPos - newPos) * zoom;
        // Applying zoom "reduction" (or "augmentation")

        // Move our view accordingly and update the window
        view.move(deltaPos);
        window.setView(view);

        // Save the new position as the old one
        // We're recalculating this, since we've changed the view
        oldPos = newPos;
      }
    }

    if (elapsed >= sf::seconds(1.0f / 60.0f)) {
      window.clear(sf::Color::Black);
      // Draw the Graph
      sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
      cell.setOutlineColor(sf::Color::Black);
      cell.setOutlineThickness(5);

      for (int x = 0; x < gridSizeX; ++x) {
        for (int y = 0; y < gridSizeY; ++y) {
          cell.setPosition(x * cellSize, y * cellSize);
          window.draw(cell);
        }
      }
      window.display();
      // Subtract the fixed time step from the elapsed time
      elapsed -= sf::seconds(1.0f / 60.0f);
    }
  }
  return 0;
}
