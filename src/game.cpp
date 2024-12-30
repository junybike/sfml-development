//
// Created by Jsn on 12/23/2024.
//

#include "../include/game.h"

#include "SFML/Window/Keyboard.hpp"

Game::Game(): m_window("Snake", sf::Vector2u(800, 600)), m_snake(m_world.GetBlockSize(), &m_textbox), m_world(sf::Vector2u(800, 600))
{
    m_clock.restart();
    srand(time(NULL));

    m_textbox.Setup(5, 14, 350, sf::Vector2f(255, 0));
    m_elapsed = 0.0f;

    m_textbox.Add("Just a random number: " + std::to_string(time(nullptr)));
}

Game::~Game()
{

}

// Controls the snake with keyboard
void Game::HandleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down)
    {
        m_snake.SetDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up)
    {
        m_snake.SetDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left)
    {
        m_snake.SetDirection(Direction::Right);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right)
    {
        m_snake.SetDirection(Direction::Left);
    }
}

// Determine if the snake has lost. Calls update in the world's class
void Game::Update()
{
    float timestep = 1.0f / m_snake.GetSpeed();

    if (m_elapsed >= timestep)
    {
        m_snake.Tick();
        m_world.Update(m_snake);
        m_elapsed -= timestep;

        if (m_snake.HasLost())
        {
            m_textbox.Add("YOU DIED! Score: " + std::to_string((long long)m_snake.GetScore()));
            m_snake.Reset();
        }
    }
}

// Display the new updates applied. (Snake pos, new texts, world entities)
void Game::Render()
{
    m_window.BeginDraw();
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

GameWindow* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_clock.getElapsedTime();
}


void Game::RestartClock()
{
    m_elapsed += m_clock.restart().asSeconds();
}



