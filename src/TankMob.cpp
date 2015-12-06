#include "TankMob.h"

TankMob::TankMob()
:Mob()
{
    m_life = 500;
    m_speed = 1;
    m_default_speed = 1;
    m_texture.loadFromFile("resource/mob/tank.png");
    m_textureBot.loadFromFile("resource/mob/tankBot.png");
    m_textureTop.loadFromFile("resource/mob/tankTop.png");
    m_sprite.setTexture(m_texture);
    m_price = 100;
}

TankMob::~TankMob()
{
    //dtor
}
