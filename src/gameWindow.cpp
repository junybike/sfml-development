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

    m_isFocused = true;
    m_eventManager.AddCallback("Toggle Fullscreen", &GameWindow::ToggleFullScreen, this);
    m_eventManager.AddCallback("Close Window", &GameWindow::Close, this);

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
        if (event.type == sf::Event::LostFocus)
        {
            m_isFocused = false;
            m_eventManager.SetFocus(false);
        }
        else if (event.type == sf::Event::GainedFocus)
        {
            m_isFocused = true;
            m_eventManager.SetFocus(true);
        }
        m_eventManager.HandleEvents(event);
    }
    m_eventManager.Update();
}


void GameWindow::ToggleFullScreen(EventDetails *l_details)
{
    m_isFullScreen = !m_isFullScreen;
    m_window.close();
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

void GameWindow::Close(EventDetails* l_details)
{
    m_isDone = true;
}

bool GameWindow::IsFocused()
{
    return m_isFocused;
}

EventManager* GameWindow::GetEventManager()
{
    return &m_eventManager;
}


