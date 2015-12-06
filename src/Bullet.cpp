#include "Bullet.h"

Bullet::Bullet()
: m_position(0, 0), m_speed(3), m_i(-1), m_level(0)
{
        m_texture.loadFromFile("resource/bullet1.png");
        m_sprite.setTexture(m_texture);

        m_damage = 25;
}

Bullet::Bullet(Mob *target, sf::Vector2f initPos)
: m_position(initPos), m_speed(3), m_i(-1)
{
        m_texture.loadFromFile("resource/bullet1.png");
        m_sprite.setTexture(m_texture);

        m_damage = 25;

        m_target = target;
}

void Bullet::init(Mob *target, sf::Vector2f initPos, int i)
{
    m_target = target;
    m_position = initPos;
    m_i = i;
}

void Bullet::refresh()
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


        if (m_position == m_target[m_i].getPosition()||
        m_position.x < m_target[m_i].getPosition().x && (m_target[m_i].getPosition().x - m_position.x) < m_speed && m_position.y < m_target[m_i].getPosition().y && (m_target[m_i].getPosition().y - m_position.y) < m_speed || //+i en y et +i en x
        m_position.x < m_target[m_i].getPosition().x && (m_target[m_i].getPosition().x - m_position.x) < m_speed && m_position.y > m_target[m_i].getPosition().y && (m_position.y - m_target[m_i].getPosition().y) < m_speed ||// -i en y et +i en x
        m_position.x > m_target[m_i].getPosition().x && (m_position.x - m_target[m_i].getPosition().x) < m_speed && m_position.y < m_target[m_i].getPosition().y && (m_target[m_i].getPosition().y - m_position.y) < m_speed ||//+i en y et -i en x
        m_position.x > m_target[m_i].getPosition().x && (m_position.x - m_target[m_i].getPosition().x) < m_speed && m_position.y > m_target[m_i].getPosition().y && (m_position.y - m_target[m_i].getPosition().y) < m_speed ||
        m_target[m_i].getLife() <= 0)
        {
                m_target[m_i].attack(m_damage);
                this->init(0, sf::Vector2f(0, 0), -1);
        }
    }
}

void Bullet::draw(sf::RenderWindow &window)
{
    if (m_position != sf::Vector2f(0, 0))
    {
        m_sprite.setPosition(m_position);
        window.draw(m_sprite);
    }

}

void Bullet::upgrade()
{
    m_level++;
    m_damage = m_damage*2;
}

Bullet::~Bullet()
{
    //dtor
}
