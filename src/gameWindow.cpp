//
// Created by Jsn on 12/19/2024.
//

#include "../include/gameWindow.h"

GameWindow::GameWindow()
{
    Setup("Window", sf::Vector2u(640, 480));
}

GameWindow::GameWindow(const std::string& l_title, const sf::Vector2u& l_size)
{
    Setup(l_title, l_size);
}

GameWindow::~GameWindow()
{
    Destroy();
}

void GameWindow::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullScreen = false;
    m_isDone = false;
    Create();
}

void GameWindow::Create()
{
    auto style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_windowTitle, style);
}

void GameWindow::Destroy()
{
    m_window.close();
}

void GameWindow::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) m_isDone = true;
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) ToggleFullscreen();
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_isDone = true;
    }
}

void GameWindow::ToggleFullscreen()
{
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}

void GameWindow::BeginDraw()
{
    m_window.clear(sf::Color::Black);
}

void GameWindow::EndDraw()
{
    m_window.display();
}

bool GameWindow::IsDone()
{
    return m_isDone;
}

bool GameWindow::IsFullScreen()
{
    return m_isFullScreen;
}

sf::Vector2u GameWindow::GetWindowSize()
{
    return m_windowSize;
}

sf::RenderWindow* GameWindow::GetRenderWindow()
{
    return &m_window;
}

void GameWindow::Draw(sf::Drawable& l_drawable)
{
    m_window.draw(l_drawable);
}