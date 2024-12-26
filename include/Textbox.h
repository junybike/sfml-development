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
    Textbox();
    Textbox(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    ~Textbox();

    void Setup(int l_visible, int l_charSize, int l_width, sf::Vector2f l_screenPos);
    void Add(std::string l_text);
    void Clear();

    void Render(sf::RenderWindow& l_window);

private:
    MessageContainer m_messages;
    int m_numVisible;

    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};

#endif //TEXTBOX_H
