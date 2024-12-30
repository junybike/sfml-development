//
// Created by Jsn on 12/25/2024.
//

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>
#include <string>

using MessageContainer = std::vector<std::string>;

class Textbox
{
public:
    Textbox();                                                                          // Textbox default constructor
    Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);      // Textbox parameterized constructor
    ~Textbox();                                                                         // Textbox destructor

    void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);   // Textbox setup
    void Add(std::string l_text);                                                       // Adds a text to the textbox
    void Clear();                                                                       // Clears the texts in textbox

    void Render(sf::RenderWindow& l_window);                                            // Update the textbox (applying new texts etc.)

private:
    MessageContainer m_messages;    // a vector of messages
    int m_numVisible;               // number of visible lines in textbox

    sf::RectangleShape m_backdrop;  // The textbox background
    sf::Font m_font;                // The font of text
    sf::Text m_content;             // The content of a text
};

#endif //TEXTBOX_H
