#include "SlowBullet.h"

SlowBullet::SlowBullet()
:Bullet()
{
    m_damage = 0;
    m_texture.loadFromFile("resource/bullet2.png");
    m_sprite.setTexture(m_texture);
}

void SlowBullet::refresh()
{
    if (m_position != sf::Vector2f(0, 0) && m_i != -1 )
    {



        if (m_target[m_i].getPosition().x > m_position.x)
            m_position.x += m_speed;
        else if (m_target[m_i].getPosition().x < m_position.x)
            m_position.x -= m_speed;

        if (m_target[m_i].getPosition().y > m_position.y)
            m_position.y += m_speed;
        else if(m_target[m_i].getPosition().y < m_position.y)
            m_position.y -= m_speed;

        if (m_target)
        {
            for (int i = 0; i <= m_speed; i++)
            {
                if (m_target && m_position == m_target[m_i].getPosition() ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x + i, m_target[m_i].getPosition().y)||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x - i, m_target[m_i].getPosition().y) ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x, m_target[m_i].getPosition().y + i) ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x, m_target[m_i].getPosition().y - i)  ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x + i, m_target[m_i].getPosition().y - i) ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x - i, m_target[m_i].getPosition().y + i) ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x + i, m_target[m_i].getPosition().y + i) ||
                m_target && m_position == sf::Vector2f(m_target[m_i].getPosition().x - i, m_target[m_i].getPosition().y - i))
                {
                    if (m_level == 0)
                        m_target[m_i].slow(3);
                    else if (m_level == 1)
                        m_target[m_i].slow(5);

                    this->init(0, sf::Vector2f(0, 0), -1);
                    break;
                }
                else if (m_target && m_target[m_i].getLife() <= 0)
                {
                    this->init(0, sf::Vector2f(0, 0), -1);
                }
            }
        }
        else
        {
            this->init(0, sf::Vector2f(0, 0), -1);
        }
    }
}

SlowBullet::~SlowBullet()
{
    //dtor
}
