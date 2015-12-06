#ifndef MOB_H
#define MOB_H

#include "Main.h"
#include "Map.h"

class Mob
{
    public:
        Mob();

        void init(sf::Vector2f position, Map &map);

        bool refresh();

        void draw(sf::RenderWindow &window);

        void attack(int damage);

        void slow(int slowTime);

        sf::Vector2f getPosition();
        int getLife();
        int getSpeed();
        bool getCanSlow();

        virtual ~Mob();
    protected:
        sf::Vector2f m_position;
        sf::Texture m_texture, m_textureBot, m_textureTop;
        sf::Sprite m_sprite;

        Map *m_map;

        int m_life, m_default_speed, m_default_life, m_price;
        bool comeDown, getOn;
        float m_speed;

        sf::RectangleShape m_rect;
        sf::Clock m_slow_timer;
        int m_slowTime;

    private:

};

#endif // MOB_H
