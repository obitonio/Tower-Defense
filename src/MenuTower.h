#ifndef MENUTOWER_H
#define MENUTOWER_H

#include "Main.h"
#include "BasicTower.h"
#include "SlowTower.h"
#include "Tool.h"
#include "Map.h"

class MenuTower
{
    public:
        MenuTower(std::vector<BasicTower*> &basicTower, int &gold, Mob *mob);

        void refresh(sf::RenderWindow &window, Map &map);
        void spriteLock(sf::RenderWindow &window, Map &map);
        sf::Vector2f getPosition();
        void draw(sf::RenderWindow &window);
        void setHealth(int health);
        void decrementeHealth();
        virtual ~MenuTower();

    protected:
    private:
        bool m_lock;
        int m_i, m_type, &m_gold, m_health;
        sf::Texture m_texture, m_textureTowerClassic, m_textureTowerSlow, m_textureCompteurGold;
        sf::Sprite m_sprite, m_spriteTower, m_spriteCompteurGold;
        sf::Text m_textGold, m_textHealth;
        sf::Font m_font;
        std::vector<BasicTower*> &m_basicTower;
        std::stringstream m_goldString, m_healthString;
        Mob *m_mob;
};

#endif // MENUTOWER_H
