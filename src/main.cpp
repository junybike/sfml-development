#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "../include/game.h"

int main()
{
    Game game;

    while (!game.GetWindow()->IsDone())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
}


