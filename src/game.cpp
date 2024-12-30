//
// Created by Jsn on 12/19/2024.
//

#include "../include/game.h"

Game::Game(): m_window("Mushroom", sf::Vector2u(800,600))
{
    RestartClock();
    srand(time(NULL));

    // Set up the mushroom size, position, texture

    sf::Vector2u size = m_mushroomTexture.getSize();
    m_mushroom.setOrigin(size.x / 2, size.y / 2);

    m_mushroomTexture.loadFromFile("Mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_increment = sf::Vector2f(100.0f, 100.0f);
}

Game::~Game()
{

}

void Game::Update()
{
    m_window.Update();
    MoveMushroom();
}

void Game::MoveMushroom()
{
    // Mushroom movement function

    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textSize = m_mushroomTexture.getSize();

    if ((m_mushroom.getPosition().x > l_windSize.x - l_textSize.x && m_increment.x > 0) ||
        m_mushroom.getPosition().x < 0 && m_increment.x < 0)
    {
        m_increment.x = -m_increment.x;
    }
    if ((m_mushroom.getPosition().y > l_windSize.y - l_textSize.y && m_increment.y > 0) ||
        m_mushroom.getPosition().y < 0 && m_increment.y < 0)
    {
        m_increment.y = -m_increment.y;
    }

    float fElapsed = m_elapsed.asSeconds();
    m_mushroom.setPosition(m_mushroom.getPosition().x + (m_increment.x * fElapsed),
        m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render()
{
    m_window.BeginDraw();
    m_window.Draw(m_mushroom);
    m_window.EndDraw();
}

GameWindow* Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed()
{
    return m_elapsed;
}

void Game::RestartClock()
{
    m_elapsed = m_clock.restart();
}
