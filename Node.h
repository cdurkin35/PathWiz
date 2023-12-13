#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib> // for rand and srand
#include <ctime> // for time
#include <iostream>
#include <vector>
const int windowWidth = 8000;
const int windowHeight = 5000;
const int gridSizeX = 400;
const int gridSizeY = 250;
const int cellSize = 20;

class Node
{
  public:
  sf::RectangleShape shape;
  sf::Vector2f position;

  bool isWall;

  Node(const sf::Vector2f& pos)
    : position(pos)
    , isWall(false)
  {
    shape.setSize(sf::Vector2f(cellSize, cellSize));
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(5);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(pos);
  }

  void draw(sf::RenderWindow& window)
  {
    window.draw(shape);
  }

  void makeWall()
  {
    isWall = true;
    shape.setFillColor(sf::Color::Black);
  }

  void makeStart()
  {
    shape.setFillColor(sf::Color::Green);
  }

  void makeEnd()
  {
    shape.setFillColor(sf::Color::Red);
  }

  void clear()
  {
    if (!isWall) {
      shape.setFillColor(sf::Color::White);
    }
  }
};
