//
// Created by Jsn on 12/23/2024.
//

#ifndef SNAKE_H
#define SNAKE_H

#include "Textbox.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

struct SnakeSegment
{
    SnakeSegment(int x, int y) : position(x, y){};
    sf::Vector2i position;
};

enum class Direction{ None, Up, Down, Left, Right };

using SnakeContainer = std::vector<SnakeSegment>;

class Snake
{
public:
    Snake(int l_block_size, Textbox* l_log);
    ~Snake();

    void SetDirection(Direction l_dir);           // Set direction of snake
    Direction GetDirection();                   // Get direction of snake
    int GetSpeed();                             // Get speed of snake
    sf::Vector2i GetPosition();                 // Get location of snake

    int GetLives();                             // Get lives of snake
    int GetScore();                             // Get score of snake
    void IncreaseScore();                       // Increment the score of snake

    bool HasLost();                             // Check if the user has lost
    void Lose();                                // Lose handler
    void ToggleLost();                          // Lose event

    void Extend();                              // Grow the snake
    void Reset();                               // Reset position

    void Move();                                // Snake movement
    void Tick();                                // Update method
    void Cut(int l_segments);                     // Cuts the snake
    void Render(sf::RenderWindow& l_window);      // Rendering images

    Direction GetPhysicalDirection();

private:
    void CheckCollision();                      // Check snake collision against walls
    SnakeContainer m_snakebody;                   // Segment vector
    Direction m_dir;                              // Current direction of snake
    int m_size;                                   // Size of the graphic
    int m_speed;                                  // Speed of snake
    int m_lives;                                  // Lives of snake
    int m_score;                                  // Score of snake
    bool m_lost;                                  // Lose state
    sf::RectangleShape m_body;                    // Shape used in rendering

    Textbox* m_log;
};

#endif //SNAKE_H
