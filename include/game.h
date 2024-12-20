//
// Created by Jsn on 12/19/2024.
//

#ifndef GAME_H
#define GAME_H

#include "gameWindow.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    GameWindow* GetWindow();

private:
    void MoveMushroom();

    GameWindow m_window;

    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2f m_increment;
};

#endif //GAME_H
