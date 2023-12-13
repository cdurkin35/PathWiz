#pragma once
#include "Node.h"
#include <SFML/Graphics.hpp>
#include <cstdlib> // for rand and srand
#include <ctime> // for time
#include <iostream>
#include <vector>

class Button
{
  public:
  sf::RectangleShape shape;
  sf::Text label;
  sf::Vector2f position;

  Button(const std::string& buttonText, const sf::Font& font, const sf::Vector2f& position, const sf::Color& buttonColor)
    : shape(sf::Vector2f(100, 50))
    , label(buttonText, font, 20)
    , position(position)
  {
    shape.setFillColor(buttonColor);
    label.setFillColor(sf::Color::Black); // Change label color as needed
  }

  void draw(sf::RenderWindow& window, const sf::View& view)
  {
    sf::Vector2f viewTopLeft = view.getCenter() - view.getSize() / 2.0f;
    sf::Vector2f adjustedPosition = position + viewTopLeft;
    shape.setPosition(adjustedPosition);
    label.setPosition(adjustedPosition.x + 10, adjustedPosition.y + 10); // Adjust label position
    window.draw(shape);
    window.draw(label);
  }

  bool isMouseOver(const sf::RenderWindow& window, const sf::View& view) const
  {
    sf::Vector2f viewTopLeft = view.getCenter() - view.getSize() / 2.0f;
    sf::Vector2f adjustedPosition = position + viewTopLeft;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePosition, view); // Transform to global (world) coordinates

    return shape.getGlobalBounds().contains(mouseWorldPos);
  }
};
