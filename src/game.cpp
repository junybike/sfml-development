//
// Created by Jsn on 12/19/2024.
//

#include "../include/game.h"

#include <iostream>
#include <ostream>

void Game::MoveMushroom(EventDetails* l_details)
{
    sf::Vector2i mousePos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
    m_mushroom.setPosition(mousePos.x, mousePos.y);
    std::cout << "Move mushroom to: " << mousePos.x << ", " << mousePos.y << std::endl;
}

Game::Game(): m_window("Mushroom", sf::Vector2u(800,600))
{
    RestartClock();
    srand(time(NULL));

    sf::Vector2u size = m_mushroomTexture.getSize();
    m_mushroom.setOrigin(size.x / 2, size.y / 2);

    m_mushroomTexture.loadFromFile("mushroom.png");
    m_mushroom.setTexture(m_mushroomTexture);
    m_mushroom.setPosition(0.0, 0.0);

    m_window.GetEventManager()->AddCallback("Move", &Game::MoveMushroom, this);
}

Game::~Game()
{

}

void Game::Update()
{
    m_window.Update();
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

void Game::RestartClock()
{
    m_clock.restart();
}
