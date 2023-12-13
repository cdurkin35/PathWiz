#pragma once
#include "Button.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include <cstdlib> // for rand and srand
#include <ctime> // for time
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <vector>

struct ComparePair {
  bool operator()(const std::pair<int, sf::Vector2i>& x, const std::pair<int, sf::Vector2i>& y) const
  {
    return x.first > y.first;
  }
};

class Graph
{
  public:
  std::vector<std::vector<Node> > nodes;
  Button dijkstraButton;
  Button aStarButton;
  Button startPointButton;
  Button endPointButton;
  Button clearPointsButton;
  Node* startNode;
  Node* endNode;

  Graph(const sf::Font& font)
    : dijkstraButton("Dijkstra", font, sf::Vector2f(10, 10), sf::Color::Yellow)
    , aStarButton("A*", font, sf::Vector2f(140, 10), sf::Color::Blue)
    , startPointButton("Start", font, sf::Vector2f(270, 10), sf::Color::Green)
    , endPointButton("End", font, sf::Vector2f(400, 10), sf::Color::Red)
    , clearPointsButton("Clear", font, sf::Vector2f(530, 10), sf::Color::Magenta)
    , startNode(nullptr)
    , endNode(nullptr)
  {
    nodes.resize(gridSizeX, std::vector<Node>(gridSizeY, Node(sf::Vector2f(0, 0))));
    initializeCoordinates();
    generateWalls();
  }

  void initializeCoordinates()
  {
    for (int x = 0; x < gridSizeX; ++x) {
      for (int y = 0; y < gridSizeY; ++y) {
        nodes[x][y].position = sf::Vector2f(x * cellSize, y * cellSize);
        nodes[x][y].shape.setPosition(nodes[x][y].position);
      }
    }
  }

  void generateWalls()
  {
    std::srand(std::time(0));

    for (int x = 0; x < gridSizeX; ++x) {
      for (int y = 0; y < gridSizeY; ++y) {
        if (std::rand() % 100 < 20) {
          nodes[x][y].makeWall();
        }
      }
    }
  }

  void handleButtonClicks(sf::RenderWindow& window, const sf::View& view)
  {
    if (dijkstraButton.isMouseOver(window, view) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      dijkstraButtonClick();
    }

    if (aStarButton.isMouseOver(window, view) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      aStarButtonClick();
    }

    if (startPointButton.isMouseOver(window, view) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      startPointButtonClick(window, view);
    }

    if (endPointButton.isMouseOver(window, view) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      endPointButtonClick(window, view);
    }

    if (clearPointsButton.isMouseOver(window, view) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      clearPointsButtonClick();
    }
  }

  void dijkstraButtonClick()
  {
    // Implement Dijkstra button functionality here
    std::cout << "Dijkstra button clicked!" << std::endl;
    dijkstraAlgorithm();
  }

  void aStarButtonClick()
  {
    // Implement A* button functionality here
    std::cout << "A* button clicked!" << std::endl;
    aStarAlgorithm();
  }

  void startPointButtonClick(sf::RenderWindow& window, const sf::View& view)
  {
    if (startNode != nullptr) {
      return;
    }

    std::cout << "Start Point button clicked! Click on a node to set it as the starting point." << std::endl;

    // Wait for the user to click on a node
    sf::Event clickEvent;
    bool mouseClicked = false;
    while (window.waitEvent(clickEvent)) {
      if (clickEvent.type == sf::Event::Closed) {
        window.close();
        break;
      } else if (clickEvent.type == sf::Event::MouseButtonPressed && clickEvent.mouseButton.button == sf::Mouse::Left) {
        // Check if the mouse button is pressed (not released)
        if (!mouseClicked) {
          mouseClicked = true;

          // Get the mouse position in window coordinates
          sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

          // Convert window coordinates to world coordinates
          sf::Vector2f worldMousePos = window.mapPixelToCoords(pixelPos, view);

          // Convert world coordinates to grid indices
          int xIndex = static_cast<int>(worldMousePos.x / cellSize);
          int yIndex = static_cast<int>(worldMousePos.y / cellSize);

          // Check if the indices are within valid range
          if (xIndex >= 0 && xIndex < gridSizeX && yIndex >= 0 && yIndex < gridSizeY) {
            // Set the startNode and make it green
            startNode = &nodes[xIndex][yIndex];
            startNode->makeStart();
            break; // Exit the loop after a valid node is selected
          }
        }
      } else if (clickEvent.type == sf::Event::MouseButtonReleased && clickEvent.mouseButton.button == sf::Mouse::Left) {
        // Reset the flag when the mouse button is released
        mouseClicked = false;
      }
    }
  }

  void endPointButtonClick(sf::RenderWindow& window, const sf::View& view)
  {
    if (endNode != nullptr) {
      return;
    }

    std::cout << "End Point button clicked! Click on a node to set it as the starting point." << std::endl;

    // Wait for the user to click on a node
    sf::Event clickEvent;
    bool mouseClicked = false;
    while (window.waitEvent(clickEvent)) {
      if (clickEvent.type == sf::Event::Closed) {
        window.close();
        break;
      } else if (clickEvent.type == sf::Event::MouseButtonPressed && clickEvent.mouseButton.button == sf::Mouse::Left) {
        // Check if the mouse button is pressed (not released)
        if (!mouseClicked) {
          mouseClicked = true;

          // Get the mouse position in window coordinates
          sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

          // Convert window coordinates to world coordinates
          sf::Vector2f worldMousePos = window.mapPixelToCoords(pixelPos, view);

          // Convert world coordinates to grid indices
          int xIndex = static_cast<int>(worldMousePos.x / cellSize);
          int yIndex = static_cast<int>(worldMousePos.y / cellSize);

          // Check if the indices are within valid range
          if (xIndex >= 0 && xIndex < gridSizeX && yIndex >= 0 && yIndex < gridSizeY) {
            // Set the endNode and make it red
            endNode = &nodes[xIndex][yIndex];
            endNode->makeEnd();
            break; // Exit the loop after a valid node is selected
          }
        }
      } else if (clickEvent.type == sf::Event::MouseButtonReleased && clickEvent.mouseButton.button == sf::Mouse::Left) {
        // Reset the flag when the mouse button is released
        mouseClicked = false;
      }
    }
  }

  void clearPointsButtonClick()
  {
    // Implement Clear Points button functionality here
    std::cout << "Clear Points button clicked!" << std::endl;
    // Iterate through all nodes and clear them
    for (int x = 0; x < gridSizeX; ++x) {
      for (int y = 0; y < gridSizeY; ++y) {
        nodes[x][y].clear();
      }
    }

    // Reset startNode and endNode
    startNode = nullptr;
    endNode = nullptr;
  }

  void drawGraph(sf::RenderWindow& window, const sf::View& view)
  {
    for (int x = 0; x < gridSizeX; ++x) {
      for (int y = 0; y < gridSizeY; ++y) {
        nodes[x][y].draw(window);
      }
    }

    dijkstraButton.draw(window, view);
    aStarButton.draw(window, view);
    startPointButton.draw(window, view);
    endPointButton.draw(window, view);
    clearPointsButton.draw(window, view);
  }

  // Function to perform Dijkstra's Algorithm
  void dijkstraAlgorithm()
  {
    // Check if start and end nodes are selected
    if (startNode == nullptr || endNode == nullptr) {
      std::cerr << "Please select both start and end nodes before running Dijkstra's Algorithm." << std::endl;
      return;
    }

    // Initialize distances to all nodes as infinity, except for the start node (distance = 0)
    std::vector<std::vector<int> > distances(gridSizeX, std::vector<int>(gridSizeY, std::numeric_limits<int>::max()));
    distances[startNode->position.x / cellSize][startNode->position.y / cellSize] = 0;

    // Priority queue to store nodes and their distances
    std::priority_queue<std::pair<int, sf::Vector2i>, std::vector<std::pair<int, sf::Vector2i> >, ComparePair> pq;
    pq.push({ 0, { int(startNode->position.x / cellSize), int(startNode->position.y / cellSize) } });

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      int x = current.second.x;
      int y = current.second.y;

      // Check if the node is a wall
      if (nodes[x][y].isWall) {
        continue; // Skip this node if it's a wall
      }

      // Exclude changing the color of start and end nodes
      if (current.second != sf::Vector2i(startNode->position.x / cellSize, startNode->position.y / cellSize) && current.second != sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
        // Set the color of the current node to blue
        nodes[x][y].shape.setFillColor(sf::Color::Blue);
      }

      // Check if the current node is the endNode
      if (current.second == sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
        break; // Stop the algorithm once the shortest path to the endNode is found
      }

      // Check neighbors (left, right, top, bottom)
      const std::vector<sf::Vector2i> neighbors = {
        { x - 1, y }, { x + 1, y }, { x, y - 1 }, { x, y + 1 }
      };

      for (const auto& neighbor : neighbors) {
        int nx = neighbor.x;
        int ny = neighbor.y;

        // Check if the neighbor is within the valid range
        if (nx >= 0 && nx < gridSizeX && ny >= 0 && ny < gridSizeY) {
          int newDistance = distances[x][y] + 1; // Assuming each edge has a weight of 1

          // Update distance if the new path is shorter
          if (newDistance < distances[nx][ny]) {
            distances[nx][ny] = newDistance;
            pq.push({ newDistance, { nx, ny } });
          }
        }
      }
    }

    // Highlight the path from start to end
    highlightShortestPath(distances);
  }

  // Heuristic for A* Algorithm
  int manhattanDistance(const sf::Vector2f& source, const sf::Vector2f& destination)
  {
    return abs(destination.x - source.x) + abs(destination.y - source.y);
  }

  // Function to perform A* Algorithm
  void aStarAlgorithm()
  {
    // Check if start and end nodes are selected
    if (startNode == nullptr || endNode == nullptr) {
      std::cerr << "Please select both start and end nodes before running A* Algorithm." << std::endl;
      return;
    }

    // Initialize distances and heuristic values to all nodes as infinity, except for the start node (distance = 0, heuristic = Manhattan distance)
    std::vector<std::vector<int> > distances(gridSizeX, std::vector<int>(gridSizeY, std::numeric_limits<int>::max()));
    std::vector<std::vector<int> > heuristics(gridSizeX, std::vector<int>(gridSizeY, 0));

    distances[startNode->position.x / cellSize][startNode->position.y / cellSize] = 0;

    // Priority queue to store nodes, their distances, and heuristics
    std::priority_queue<std::pair<int, sf::Vector2i>, std::vector<std::pair<int, sf::Vector2i> >, ComparePair> pq;
    pq.push({ 0 + manhattanDistance(startNode->position, endNode->position), { static_cast<int>(startNode->position.x / cellSize), static_cast<int>(startNode->position.y / cellSize) } });

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      int x = current.second.x;
      int y = current.second.y;

      // Check if the node is a wall
      if (nodes[x][y].isWall) {
        continue; // Skip this node if it's a wall
      }

      // Change the color of the current node to blue, excluding startNode and endNode
      if (current.second != sf::Vector2i(startNode->position.x / cellSize, startNode->position.y / cellSize) && current.second != sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
        nodes[x][y].shape.setFillColor(sf::Color::Blue);
      }

      // Check if the current node is the endNode
      if (current.second == sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
        break; // Stop the algorithm once the shortest path to the endNode is found
      }

      // Check neighbors (left, right, top, bottom)
      const std::vector<sf::Vector2i> neighbors = {
        { x - 1, y }, { x + 1, y }, { x, y - 1 }, { x, y + 1 }
      };

      for (const auto& neighbor : neighbors) {
        int nx = neighbor.x;
        int ny = neighbor.y;

        // Check if the neighbor is within the valid range and not a wall
        if (nx >= 0 && nx < gridSizeX && ny >= 0 && ny < gridSizeY && !nodes[nx][ny].isWall) {
          int newDistance = distances[x][y] + 1; // Assuming each edge has a weight of 1

          // Update distance if the new path is shorter
          if (newDistance < distances[nx][ny]) {
            distances[nx][ny] = newDistance;
            // Update heuristic value using Manhattan distance
            heuristics[nx][ny] = manhattanDistance(nodes[nx][ny].position, endNode->position);
            pq.push({ newDistance + heuristics[nx][ny], { nx, ny } });

            // Change the color of the enqueued node to blue, excluding startNode and endNode
            if (neighbor != sf::Vector2i(startNode->position.x / cellSize, startNode->position.y / cellSize) && neighbor != sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
              // Check if the node is not already part of the path
              if (distances[nx][ny] != std::numeric_limits<int>::max()) {
                nodes[nx][ny].shape.setFillColor(sf::Color::Blue);
              }
            }
          }
        }
      }
    }

    // Highlight the path from start to end
    highlightShortestPath(distances);
  }
  // Function to highlight the shortest path from start to end
  void highlightShortestPath(const std::vector<std::vector<int> >& distances)
  {
    int x = endNode->position.x / cellSize;
    int y = endNode->position.y / cellSize;

    // Backtrack from the end node to the start node to find the shortest path
    while (x != startNode->position.x / cellSize || y != startNode->position.y / cellSize) {
      int currentDistance = distances[x][y];

      // Find the neighbor with the minimum distance
      const std::vector<sf::Vector2i> neighbors = {
        { x - 1, y }, { x + 1, y }, { x, y - 1 }, { x, y + 1 }
      };

      sf::Vector2i nextNode = { -1, -1 };
      int minDistance = std::numeric_limits<int>::max();

      for (const auto& neighbor : neighbors) {
        int nx = neighbor.x;
        int ny = neighbor.y;

        // Check if the neighbor is within the valid range
        if (nx >= 0 && nx < gridSizeX && ny >= 0 && ny < gridSizeY) {
          if (!nodes[nx][ny].isWall && distances[nx][ny] == currentDistance - 1) {
            // Check if the node is not a wall and has the correct distance
            if (distances[nx][ny] < minDistance) {
              minDistance = distances[nx][ny];
              nextNode = { nx, ny };
            }
          }
        }
      }

      if (nextNode.x != -1 && nextNode.y != -1) {
        // Exclude changing the color of start and end nodes
        if (nextNode != sf::Vector2i(startNode->position.x / cellSize, startNode->position.y / cellSize) && nextNode != sf::Vector2i(endNode->position.x / cellSize, endNode->position.y / cellSize)) {
          // Highlight the path by changing the color
          nodes[nextNode.x][nextNode.y].shape.setFillColor(sf::Color::Yellow);
        }
        x = nextNode.x;
        y = nextNode.y;
      } else {
        // Unable to find a valid path
        break;
      }
    }
  }
};
