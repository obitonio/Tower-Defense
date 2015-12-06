#ifndef MENU_H
#define MENU_H
#include "Main.h"
#include "Button.h"

class Menu
{
    public:
        Menu();

        int update(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window);

        virtual ~Menu();
    protected:
    private:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        Button m_B1, m_B2, m_B3, m_B4, m_B5;
};

#endif // MENU_H
