#ifndef BUTTON_H
#define BUTTON_H

#include "Main.h"

class Button
{
    public:
        Button(std::string textureLink, std::string textureFocus, sf::Vector2f position);

        Button(std::string textureLink, sf::Vector2f position);

        Button(sf::Vector2f positionDefault, sf::Vector2f positionDelta);

        bool mousePressed(sf::RenderWindow &window);

        bool mouseReleased(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window);

        virtual ~Button();
    protected:
    private:
        sf::Vector2f m_position, m_positionDelta;
        sf::Texture m_texture, m_textureFocus;
        sf::Sprite m_sprite;
        bool m_pressed, m_wasPressed;
};

#endif // BUTTON_H
