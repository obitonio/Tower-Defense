#include "RunnerMob.h"

RunnerMob::RunnerMob()
:Mob()
{
    m_life = 50;
    m_default_life = 50;
    m_speed = 3;
    m_default_speed = 3;
    m_texture.loadFromFile("resource/mob/runner.png");
    m_textureBot.loadFromFile("resource/mob/runnerBot.png");
    m_textureTop.loadFromFile("resource/mob/runnerTop.png");
    m_sprite.setTexture(m_texture);
    m_price = 25;
}

RunnerMob::~RunnerMob()
{
    //dtor
}
