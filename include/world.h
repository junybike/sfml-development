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
    World(sf::Vector2u l_windSize);
    ~World();

    int GetBlockSize();
    void RespawnApple();

    void Update(Snake& l_player);
    void Render(sf::RenderWindow& l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_apple;
    sf::RectangleShape m_bounds[4];
};

#endif //WORLD_H
