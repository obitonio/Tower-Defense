#ifndef BASICTOWER_H
#define BASICTOWER_H

#include "Main.h"
#include "Mob.h"
#include "Bullet.h"

class BasicTower
{
    public:
        BasicTower();

        virtual void refresh();

        void draw(sf::RenderWindow &window);

        void setMob(Mob *m_mob);

        void setPosition(sf::Vector2f position);

        void upgrade();

        virtual void attack(int i);


        sf::Vector2f getPosition();

        int getLevel();

        virtual ~BasicTower();
    protected:
        sf::Vector2f m_position;
        sf::Texture m_texture, m_textureUp;
        sf::Sprite m_sprite;

        Mob *m_mob;
        int m_iBullet, m_level;

        sf::Vector2f m_range;

        sf::Clock m_clock;

        sf::Text m_text;
        sf::Font m_font;

        std::vector<Bullet*> m_bullet;
        //Bullet m_bullet[16];
    private:





};

#endif // BASICTOWER_H
