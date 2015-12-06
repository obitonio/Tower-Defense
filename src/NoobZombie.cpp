#include "NoobZombie.h"

NoobZombie::NoobZombie()
{
    m_texture.loadFromFile("resource/mob/noobmob.png");
    m_textureBot.loadFromFile("resource/mob/noobmobBot.png");
    m_textureTop.loadFromFile("resource/mob/noobmobTop.png");
    m_sprite.setTexture(m_texture);
    m_life = 75;
    m_default_life = 75;
    m_speed = 2;
    m_default_speed = 2;
    m_price = 50;
}

NoobZombie::~NoobZombie()
{
    //dtor
}
