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
    GameWindow();                                                           // GameWindow default constructor
    GameWindow(const std::string& l_title, const sf::Vector2u& l_size);     // GameWindow parameterized constructor
    ~GameWindow();                                                          // GameWindow destructor

    void BeginDraw();   // Clears the screen before applying the changes made in game entities
    void EndDraw();     // Displays the new display with all changes applied

    void Update();      // Detects if the game is done: end the game. Or F5 key is pressed: enables fullscreen.

    bool IsDone();          // m_isDone getter function
    bool IsFullScreen();    // m_isFullScreen getter function

    sf::Vector2u GetWindowSize();   // m_windowSize getter function

    void ToggleFullscreen();                // Enables fullscreen
    void Draw(sf::Drawable& l_drawable);    // Apply the changes in game entities

private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);     // Initialize GameWindow attributes
    void Destroy();                                                         // Closes the window
    void Create();                                                          // Creates the window tab on screen

    sf::RenderWindow m_window;  // The window
    sf::Vector2u m_windowSize;  // The size of window
    std::string m_windowTitle;  // The title of window

    bool m_isDone;              // Determine if the window is closed
    bool m_isFullScreen;        // Determine if the window is in the fullscreen
};

#endif //GAMEWINDOW_H
