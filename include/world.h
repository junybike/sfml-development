//
// Created by Jsn on 12/23/2024.
//

#ifndef WORLD_H
#define WORLD_H

#include "snake.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class World
{
public:
    World(sf::Vector2u l_windSize);     // World constructor
    ~World();                           // World destructor

    int GetBlockSize();     // m_blockSize getter function
    void RespawnApple();    // generates an apple in the world at a random position

    void Update(Snake& l_player);               // Respawns apple if snake has eaten it and determines if snake has lost.
    void Render(sf::RenderWindow& l_window);    // Apply the new changes made from the game entity

private:
    sf::Vector2u m_windowSize;  // the size of the window
    sf::Vector2i m_item;        // apple entity
    int m_blockSize;            // size of blocks

    sf::CircleShape m_apple;        // apple texture
    sf::RectangleShape m_bounds[4]; // Contains each blocks of the snake's body
};

#endif //WORLD_H
