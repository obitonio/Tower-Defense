#include "EliteZombie.h"

EliteZombie::EliteZombie()
{
    m_texture.loadFromFile("resource/mob/elitemob.png");
    m_textureBot.loadFromFile("resource/mob/elitemobBot.png");
    m_textureTop.loadFromFile("resource/mob/elitemobTop.png");
    m_sprite.setTexture(m_texture);
    m_life = 200;
    m_default_life = 200;
    m_speed = 2;
    m_default_speed = 2;
    m_price = 75;
}

EliteZombie::~EliteZombie()
{
    //dtor
}
