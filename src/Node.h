#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
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
  // SFML components
  sf::RectangleShape shape;
  sf::Vector2f position;
  // Is node a wall?
  bool isWall;
  // Constructor
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
  // Draw node
  void draw(sf::RenderWindow& window)
  {
    window.draw(shape);
  }
  // Make node a wall
  void makeWall()
  {
    isWall = true;
    shape.setFillColor(sf::Color::Black);
  }
  // Make node a start node
  void makeStart()
  {
    shape.setFillColor(sf::Color::Green);
  }
  // Make node an end node
  void makeEnd()
  {
    shape.setFillColor(sf::Color::Red);
  }
  // Clear node
  void clear()
  {
    if (!isWall) {
      shape.setFillColor(sf::Color::White);
    }
  }
};
