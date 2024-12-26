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
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    sf::Time GetElapsed();
    void RestartClock();

    GameWindow* GetWindow();

private:
    GameWindow m_window;

    World m_world;
    Snake m_snake;

    sf::Clock m_clock;
    float m_elapsed;

    Textbox m_textbox;
};

#endif //GAME_H
