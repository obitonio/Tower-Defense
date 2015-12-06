#include "BasicTower.h"

BasicTower::BasicTower()
:m_position(0, 0), m_range(250, 250),m_iBullet(0),m_bullet(16), m_level(0),
m_text("", m_font)
{
    m_font.loadFromFile("resource/comic.ttf");
    m_text.setColor(sf::Color::Yellow);
    m_text.setString("300g");
    m_text.setCharacterSize(18);

    m_texture.loadFromFile("resource/tclassic.png");
    m_textureUp.loadFromFile("resource/tclassic2.png");

    m_sprite.setTexture(m_texture);

    for (int i = 0; i < 16; i++)
    {
        m_bullet[i] = new Bullet();
    }
}

void BasicTower::refresh()
{
    if (m_position != sf::Vector2f(0, 0))
    {
        int i;

        for (i = 0; i < 64; i++)
        {

            if (m_mob[i].getPosition().x > (m_position.x - m_range.x/2) &&
                m_mob[i].getPosition().x < (m_position.x + m_range.x/2) &&
                m_mob[i].getPosition().y > (m_position.y - m_range.y/2) &&
                m_mob[i].getPosition().y < (m_position.y + m_range.y/2) &&
                m_clock.getElapsedTime().asSeconds() > 1 &&
                m_mob[i].getLife() > 0 &&
                m_mob[i].getPosition() != sf::Vector2f(0, 0))
            {
                this->attack(i);
                m_clock.restart();

                if (m_iBullet == 15)
                    m_iBullet = 0;
                else
                    m_iBullet++;
            }
        }

        for (i = 0; i < 16; i++)
        {
            m_bullet[i]->refresh();
        }
    // DELAY
    }

}

void BasicTower::attack(int i)
{
    m_bullet[m_iBullet]->init(m_mob, sf::Vector2f(m_position.x + 16, m_position.y + 16), i);
}

void BasicTower::draw(sf::RenderWindow &window)
{
    if (m_position != sf::Vector2f(0, 0))
    {
        int i;

        window.draw(m_sprite);

        for (i = 0; i < 16; i++)
        {
            m_bullet[i]->draw(window);
        }

        if (sf::Mouse::getPosition(window).x > m_position.x &&
            sf::Mouse::getPosition(window).x < m_position.x + BLOCKSIZE &&
            sf::Mouse::getPosition(window).y > m_position.y &&
            sf::Mouse::getPosition(window).y < m_position.y + BLOCKSIZE)
        {
            window.draw(m_text);
        }
    }
}

void BasicTower::setMob(Mob *mob)
{
    m_mob = mob;
}

void BasicTower::setPosition(sf::Vector2f position)
{
    m_position = position;
    m_sprite.setPosition(m_position);

    m_text.setPosition(m_position.x + 5, m_position.y + 12);
}

void BasicTower::upgrade()
{
    m_level++;
    for (int i = 0; i < 16; i++)
    {
        m_bullet[i]->upgrade();
    }
    m_sprite.setTexture(m_textureUp);
    m_text.setString("Up max");
    m_text.setCharacterSize(18);
}

sf::Vector2f BasicTower::getPosition()
{
    return m_position;
}

int BasicTower::getLevel()
{
    return m_level;
}

BasicTower::~BasicTower()
{
    for (int i = 0; i < 16; i++)
    {
        delete m_bullet[i];
    }
}
