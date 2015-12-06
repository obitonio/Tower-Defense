#ifndef BULLET_H
#define BULLET_H

#include "Main.h"
#include "Mob.h"

class Bullet
{
    public:
        Bullet();
        Bullet(Mob *target, sf::Vector2f initPos);

        void init(Mob *target, sf::Vector2f initPos, int i);

        void upgrade();

        virtual void refresh();

        void draw(sf::RenderWindow &window);

        virtual ~Bullet();
    protected:
        sf::Vector2f m_position;
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        int m_damage, m_i, m_speed, m_level;

        Mob *m_target;

    private:



};

#endif // BULLET_H
