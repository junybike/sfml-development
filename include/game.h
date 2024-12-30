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
    Game();        // Initializing the game entities
    ~Game();       // Terminates the game

    void HandleInput(); // Handles input from keyboard, mouse, controller, etc...
    void Update();      // Apply any changes of game entities. Example: game entities movements.
    void Render();      // Updates the game screen. Visualizing the changes made to the game entities.

    GameWindow* GetWindow();    // GameWindow getter function

    sf::Time GetElapsed();      // m_elapsed getter function
    void RestartClock();        // Set m_clock to 0.

private:
    void MoveMushroom();        // Moves the mushroom

    GameWindow m_window;        // The GameWindow

    sf::Texture m_mushroomTexture;  // The mushroom texture
    sf::Sprite m_mushroom;          // The mushroom sprite
    sf::Vector2f m_increment;       // The size of movement the mushroom will have each movement

    sf::Clock m_clock;  // Virtual clock in the game
    sf::Time m_elapsed; // Determines the time passed in the game
};

#endif //GAME_H
