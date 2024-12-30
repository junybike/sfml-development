//
// Created by Jsn on 12/23/2024.
//

#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "world.h"
#include "gameWindow.h"
#include "Textbox.h"

class Game
{

public:
    Game();     // Initializing the game entities
    ~Game();    // Terminates the game

    void HandleInput(); // Handles input from keyboard, mouse, controller, etc...
    void Update();      // Apply any changes of game entities. Example: game entities movements.
    void Render();      // Updates the game screen. Visualizing the changes made to the game entities.

    sf::Time GetElapsed();  // m_elapsed getter function
    void RestartClock();    // Set m_clock to 0.

    GameWindow* GetWindow();    // GameWindow getter function

private:
    GameWindow m_window;    // The GameWindow

    World m_world;      // The main world of the game
    Snake m_snake;      // The snake entity

    sf::Clock m_clock;  // Virtual clock in the game
    float m_elapsed;    // Determines the time passed in the game

    Textbox m_textbox;  // The textbox to display text in the window
};

#endif //GAME_H
