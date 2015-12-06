#include "SlowTower.h"

SlowTower::SlowTower()
:BasicTower()
{
    m_texture.loadFromFile("resource/tslow.png");
    m_textureUp.loadFromFile("resource/tslow2.png");

    m_sprite.setTexture(m_texture);

    for (int i = 0; i < 16; i++)
    {
        delete m_bullet[i];
        m_bullet[i] = new SlowBullet();
    }
}

void SlowTower::refresh()
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
                m_mob[i].getCanSlow() &&
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

void SlowTower::attack(int i)
{
     m_bullet[m_iBullet]->init(m_mob, sf::Vector2f(m_position.x + 16, m_position.y + 16), i);
}

SlowTower::~SlowTower()
{

}
