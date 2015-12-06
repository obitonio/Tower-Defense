#include "Button.h"

Button::Button(std::string textureLink, std::string textureFocus, sf::Vector2f position)
:m_position(position), m_pressed(false), m_wasPressed(false)
{
    m_texture.loadFromFile(textureLink);
    m_textureFocus.loadFromFile(textureFocus);

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);

    m_positionDelta.x = m_texture.getSize().x;
    m_positionDelta.y = m_texture.getSize().y;
}

Button::Button(std::string textureLink, sf::Vector2f position)
:m_position(position), m_pressed(false), m_wasPressed(false)
{
    m_texture.loadFromFile(textureLink);
    m_textureFocus.loadFromFile(textureLink);

    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);

    m_positionDelta.x = m_texture.getSize().x;
    m_positionDelta.y = m_texture.getSize().y;
}

Button::Button(sf::Vector2f positionDefault, sf::Vector2f positionDelta)
:m_position(positionDefault), m_positionDelta(positionDelta)
{

}

bool Button::mousePressed(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       sf::Mouse::getPosition(window).x > m_position.x   &&
       sf::Mouse::getPosition(window).x < m_position.x + m_positionDelta.x     &&
       sf::Mouse::getPosition(window).y > m_position.y              &&
       sf::Mouse::getPosition(window).y < m_position.y + m_positionDelta.y)
    {
        m_sprite.setTexture(m_textureFocus);
        return true;
    }
    else
    {
        m_sprite.setTexture(m_texture);
    }
    return false;
}

bool Button::mouseReleased(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       sf::Mouse::getPosition(window).x > m_position.x   &&
       sf::Mouse::getPosition(window).x < m_position.x + m_positionDelta.x     &&
       sf::Mouse::getPosition(window).y > m_position.y              &&
       sf::Mouse::getPosition(window).y < m_position.y + m_positionDelta.y)
    {
        m_sprite.setTexture(m_textureFocus);
        m_pressed = true;
        m_wasPressed = true;
    }
    else
    {
        m_sprite.setTexture(m_texture);
        m_pressed = false;
    }

    if (m_wasPressed && !m_pressed)
    {
        m_wasPressed = false;
        return true;
    }

    return false;
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

Button::~Button()
{
    //dtor
}
