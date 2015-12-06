#ifndef WAVE_H
#define WAVE_H

#include "Main.h"
#include "Mob.h"
#include "TankMob.h"
#include "NoobZombie.h"
#include "Zombie.h"
#include "EliteZombie.h"
#include "RunnerMob.h"
#include "Map.h"

class Wave
{
    public:
        Wave(Mob *m_mob, int &gold);

        void refresh(Map &map);

        void draw(sf::RenderWindow &window);

        void init();

        void load(std::string str);

        void save(std::string str);

        static bool loadTable(int **tableMob, std::string str);

        static bool saveTable(int tableMob[NBWAVE][NBMOB], std::string str);

        virtual ~Wave();
    protected:
    private:
        Mob *m_mob;
        int m_i, m_wave, m_maxWave, &m_gold, m_prepareTime;
        int m_tableMob[NBWAVE][NBMOB]; // 0: Runner 1: Zombie 2: Tank, MaxWave: 64
        bool m_draw;
        sf::Clock m_mobCD, m_waveCD, m_drawCD;// Seconds
        sf::Text m_text, m_textP;
        sf::Font m_font;
        std::string m_waveS;
};

#endif // WAVE_H
