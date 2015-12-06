#ifndef GAME_H
#define GAME_H

#include "Main.h"
#include "Class.h"

class Game
{
    public:

        Game(sf::RenderWindow &window);

        int refresh();

        void draw();

        virtual ~Game();
    protected:
    private:
        sf::RenderWindow &m_window;
        Map m_map;
        Wave m_wave;
        MenuTower m_menutower;
        GameOption m_gameOption;

        std::vector<BasicTower*> m_towers;
        Mob m_mob[64];
        int m_gold, m_state;
};

#endif // GAME_H
