#include "Menu.h"


Menu::Menu()
:m_B1(sf::Vector2f(240, 144), sf::Vector2f(172, 67)),
m_B2(sf::Vector2f(240, 240), sf::Vector2f(333, 80)),
m_B3(sf::Vector2f(240, 336), sf::Vector2f(388, 53)),
m_B4(sf::Vector2f(240, 432), sf::Vector2f(215, 64)),
m_B5(sf::Vector2f(576, 480), sf::Vector2f(229, 69))
{
    m_texture.loadFromFile("resource/menuBackground2.png");
    m_sprite.setTexture(m_texture);
}

int Menu::update(sf::RenderWindow &window)
{
    if(m_B1.mouseReleased(window))
    {
        return 1;   //Bouton jouer
    }
    else if(m_B2.mouseReleased(window))
    {
        return 2;   //Bouton Creer Map
    }
    else if(m_B3.mouseReleased(window))
    {
        return 3;   //Bouton Creer Waves
    }
    else if(m_B4.mouseReleased(window))
    {
        return 4;   //Bouton Credits
    }
    else if(m_B5.mouseReleased(window))
       {
           window.close();
       }
    else
        return 0;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

Menu::~Menu()
{
    //dtor
}
