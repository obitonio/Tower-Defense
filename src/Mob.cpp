#include "Mob.h"

Mob::Mob()
:m_position(0, 0), m_life(100), m_speed(2), m_default_speed(2), m_rect(), m_price(50),
comeDown(false), getOn(false), m_slowTime(0)
{

}

void Mob::init(sf::Vector2f position, Map &map)
{
    m_position = position;
    m_default_life = m_life;

    m_map = &map;

    m_sprite.setTexture(m_texture);
    m_rect.setFillColor(sf::Color::Green);
    m_rect.setSize(sf::Vector2f(m_texture.getSize().x, 2));
}

bool Mob::refresh()
{
    //std::cout << "x: " << m_position.x << " y: " <<m_position.y << std::endl;
    if (sf::Vector2f(0, 0) != m_position && m_life > 0)
    {
        if (m_slow_timer.getElapsedTime().asSeconds() > m_slowTime)
            m_speed = m_default_speed;


        int x = m_position.x/48, y = m_position.y/48;
        //std::cout << "x: " << m_position.x/48 << " y: " << m_position.y/48 << " map: " << m_map->getValue(x, y) << std::endl;

        if (comeDown)
        {
            if (m_map->getValue(x + 1, y) == BLOCKLAND || m_map->getValue(x + 1, y) == BLOCKCASTLEMIDDLE)
            {
                m_position.x += m_speed;
                comeDown = false;
                m_sprite.setTexture(m_texture);
            }
            else if (m_map->getValue(x , y + 1) == BLOCKLAND && !getOn || m_map->getValue(x, y + 1) == BLOCKCASTLEMIDDLE && !getOn)
            {
                m_position.y += m_speed;
                comeDown = true;
                m_sprite.setTexture(m_textureBot);
            }
        }
        else if (getOn)
        {
            if (m_map->getValue(x + 1, (m_position.y + 12)/48) == BLOCKLAND || m_map->getValue(x + 1, y) == BLOCKCASTLEMIDDLE)
            {
                m_position.x += m_speed;
                m_sprite.setTexture(m_texture);
                getOn = false;
            }
            else if (m_map->getValue(x , ((m_position.y + 12)/48) - 1) == BLOCKLAND && !comeDown || m_map->getValue(x, y - 1) == BLOCKCASTLEMIDDLE && !comeDown)
            {
                m_position.y -= m_speed;
                m_sprite.setTexture(m_textureTop);
                getOn = true;
            }
        }
        else if (m_map->getValue(x + 1, y) == BLOCKLAND || m_map->getValue(x + 1, y) == BLOCKCASTLEMIDDLE &&
            !comeDown && !getOn)
        {
            m_position.x += m_speed;
            comeDown = false;
            getOn = false;
            //std::cout << "Mid: "<< m_map->getValue(x + 1, y) << std::endl;
            // RIGHT
        }
        else if (m_map->getValue(x , y + 1) == BLOCKLAND && !getOn || m_map->getValue(x, y + 1) == BLOCKCASTLEMIDDLE && !getOn)
        {
            m_position.y += m_speed;
            comeDown = true;
        }
        else if (m_map->getValue(x , ((m_position.y + 24)/48) - 1) == BLOCKLAND && !comeDown || m_map->getValue(x, y - 1) == BLOCKCASTLEMIDDLE && !comeDown)
        {
            m_position.y -= m_speed;
            getOn = true;
        }

        if (m_map->getValue(x, y) == BLOCKCASTLEMIDDLE)
        {
            m_life = 0;
            return true;
        }
        else
        {
            m_rect.setPosition(sf::Vector2f(m_position.x, m_position.y - 5));
            m_rect.setSize(sf::Vector2f((m_life*m_texture.getSize().x)/(float) m_default_life, 2));
            return false;
        }
    }

    return false;
}

void Mob::draw(sf::RenderWindow &window)
{
    if (sf::Vector2f(0, 0) != m_position  && m_life > 0)
    {
        m_sprite.setPosition(m_position);
        window.draw(m_sprite);
        window.draw(m_rect);
    }
}

void Mob::attack(int damage)
{
    m_life -= damage;
    if (m_life <= 0)
    {
        m_life = 0;
    }
}

int Mob::getLife()
{
    return m_life;
}

sf::Vector2f Mob::getPosition()
{
    return m_position;
}

void Mob::slow(int slowTime)
{
    m_slowTime = slowTime;
    m_slow_timer.restart();

    if (m_default_speed == m_speed)
        m_speed = (m_speed/3)*2; // 2/3
}

bool Mob::getCanSlow()
{
    if (m_default_speed == m_speed)
        return true;
    else
        return false;
}

int Mob::getSpeed()
{
    return m_speed;
}

Mob::~Mob()
{
    //dtor
}
