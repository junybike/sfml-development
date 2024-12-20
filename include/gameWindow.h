//
// Created by Jsn on 12/19/2024.
//

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <string>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"

class GameWindow
{
public:
    GameWindow();
    GameWindow(const std::string& l_title, const sf::Vector2u& l_size);
    ~GameWindow();

    void BeginDraw();
    void EndDraw();

    void Update();

    bool IsDone();
    bool IsFullScreen();

    sf::Vector2u GetWindowSize();

    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;

    bool m_isDone;
    bool m_isFullScreen;
};

#endif //GAMEWINDOW_H
