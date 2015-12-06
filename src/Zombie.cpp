#include "Zombie.h"

Zombie::Zombie()
:Mob()
{
    m_texture.loadFromFile("resource/mob/mob.png");
    m_textureBot.loadFromFile("resource/mob/mobBot.png");
    m_textureTop.loadFromFile("resource/mob/mobTop.png");
    m_sprite.setTexture(m_texture);
    m_life = 100;
    m_default_life = 100;
    m_price = 50;
}

Zombie::~Zombie()
{
    //dtor
}
