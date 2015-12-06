#include "Wave.h"

Wave::Wave(Mob *mob, int &gold)
:m_mob(mob), m_i(0), m_wave(0), m_maxWave(4), m_gold(gold), m_draw(false), m_waveS("Wave 1"), m_prepareTime(5)
{
    m_font.loadFromFile("resource/comic.ttf");

    m_text.setFont(m_font);
    m_text.setCharacterSize(40);
    m_text.setColor(sf::Color::Red);
    m_text.setString(m_waveS);
    m_text.setPosition(SCREENX/2 - 48, SCREENY/3);

    m_textP.setFont(m_font);
    m_textP.setCharacterSize(15);
    m_textP.setColor(sf::Color::Red);
    m_textP.setString(m_waveS);
    m_textP.setPosition(SCREENX - 50, 0);

    for (int i = 0; i < NBWAVE; i++)
    {
        for (int j = 0; j < NBMOB; j++)
        {
            m_tableMob[i][j] = 0;
        }
    }


    // Wave 1
    m_tableMob[0][0] = 0; // Runner
    m_tableMob[0][1] = 5; // NoobZombie
    m_tableMob[0][2] = 0; // Zombie
    m_tableMob[0][3] = 0; // EliteZombie
    m_tableMob[0][4] = 0; // TankMob
    // Wave 2
    m_tableMob[1][0] = 3;
    m_tableMob[1][1] = 5;
    m_tableMob[1][2] = 0;
    m_tableMob[1][3] = 0;
    m_tableMob[1][5] = 0;
    // Wave 3
    m_tableMob[2][0] = 5;
    m_tableMob[2][1] = 10;
    m_tableMob[2][2] = 5;
    m_tableMob[2][3] = 0;
    m_tableMob[2][4] = 0;
    // Wave 4
    m_tableMob[3][0] = 8;
    m_tableMob[3][1] = 10;
    m_tableMob[3][2] = 10;
    m_tableMob[3][3] = 5;
    m_tableMob[3][4] = 0;
    // Wave 5
    m_tableMob[4][0] = 10;
    m_tableMob[4][1] = 20;
    m_tableMob[4][2] = 20;
    m_tableMob[4][3] = 15;
    m_tableMob[4][4] = 1;

    m_waveCD.restart();
    m_drawCD.restart();
}


void Wave::refresh(Map &map)
{
    //TODO Mob drop gold
    if (m_waveCD.getElapsedTime().asSeconds() > m_prepareTime && m_wave <= m_maxWave)
    {
        if (m_tableMob[m_wave][0] > 0 && m_mobCD.getElapsedTime().asSeconds() > 1 && m_i < 64)
        {
            m_mob[m_i] = RunnerMob();
            m_mob[m_i].init(map.getSpawnPosition(), map);
            m_tableMob[m_wave][0]--;
            m_i++;
            m_mobCD.restart();
        }
        else if (m_tableMob[m_wave][1] > 0 && m_mobCD.getElapsedTime().asSeconds() > 1 && m_i < 64)
        {
            m_mob[m_i] = NoobZombie();
            m_mob[m_i].init(map.getSpawnPosition(), map);
            m_mobCD.restart();
            m_tableMob[m_wave][1]--;
            m_i++;
        }
        else if (m_tableMob[m_wave][2] > 0 && m_mobCD.getElapsedTime().asSeconds() > 1 && m_i < 64)
        {
            m_mob[m_i] = Zombie();
            m_mob[m_i].init(map.getSpawnPosition(), map);
            m_mobCD.restart();
            m_tableMob[m_wave][2]--;
            m_i++;
        }
        else if (m_tableMob[m_wave][3] > 0 && m_mobCD.getElapsedTime().asSeconds() > 1 && m_i < 64)
        {
            m_mob[m_i] = EliteZombie();
            m_mob[m_i].init(map.getSpawnPosition(), map);
            m_mobCD.restart();
            m_tableMob[m_wave][3]--;
            m_i++;
        }
        else if (m_tableMob[m_wave][4] > 0 && m_mobCD.getElapsedTime().asSeconds() > 1 && m_i < 64)
        {
            m_mob[m_i] = TankMob();
            m_mob[m_i].init(map.getSpawnPosition(), map);
            m_mobCD.restart();
            m_tableMob[m_wave][4]--;
            m_i++;
        }
        else if (m_tableMob[m_wave][0] == 0 && m_tableMob[m_wave][1] == 0 && m_tableMob[m_wave][2] == 0 &&
                 m_tableMob[m_wave][3] == 0 && m_tableMob[m_wave][4] == 0)
        {
            bool finish = true;
            for (int i = 0; i < m_i; i++)
            {
                if (m_mob[i].getLife() > 0)
                    finish = false;
            }

            if (finish)
            {
                m_waveCD.restart();
                m_mobCD.restart();
                m_i = 0;
                m_wave++;
                m_draw = false;
                m_waveCD.restart();

                std::stringstream a;
                m_waveS = "Wave ";
                a << m_wave + 1; // +1 car commence à 0
                m_waveS += a.str();

                m_text.setString(m_waveS);
                m_textP.setString(m_waveS);

                m_gold += 125;

                if (m_wave > m_maxWave)
                {
                    m_text.setPosition(SCREENX/2 - 144, SCREENY/3);
                    m_text.setString("Game is ended !");
                    m_prepareTime = -1;
                }
            }
        }

    }

}

void Wave::draw(sf::RenderWindow &window)
{
    if (m_waveCD.getElapsedTime().asSeconds() < m_prepareTime)
    {
        window.draw(m_text);
    }
    else if (m_prepareTime == - 1)
    {
        window.draw(m_text);
    }
    window.draw(m_textP);

}

void Wave::init()
{
    m_waveCD.restart();
    m_drawCD.restart();
}

void Wave::load(std::string str)
{
    std::ifstream flux(str.c_str(), std::ios::in);
    std::string line;

    std::cout << "LOAD " << str << std::endl;
    if (flux)
    {
        for (int i = 0; i < NBWAVE; i++)
        {
            for (int j = 0; j < NBMOB; j++)
            {
                std::getline(flux, line);
                m_tableMob[i][j] = atoi(line.c_str());
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << str << std::endl;
    }
}

void Wave::save(std::string str)
{
    std::ofstream flux(str.c_str(), std::ios::out);

    if (flux)
    {
        for (int i = 0; i < NBWAVE; i++)
        {
            for (int j = 0; j < NBMOB; j++)
            {
                flux << m_tableMob[i][j] << std::endl;
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << str << std::endl;
    }
}

bool Wave::loadTable(int **tableMob, std::string str)
{

    /*
    int **tab = new int*[10];
    for(unsigned i = 0; i < 10; ++i) tab[i] = new int[10];
    */

    std::ifstream flux(str.c_str(), std::ios::in);
    std::string line;

    std::cout << "LOAD " << str << std::endl;
    if (flux)
    {
        for (int i = 0; i < NBWAVE; i++)
        {
            for (int j = 0; j < NBMOB; j++)
            {
                std::getline(flux, line);
                tableMob[i][j] = atoi(line.c_str());
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << str << std::endl;
    }
}

bool Wave::saveTable(int tableMob[NBWAVE][NBMOB], std::string str)
{
    std::ofstream flux(str.c_str(), std::ios::out);

    if (flux)
    {
        for (int i = 0; i < NBWAVE; i++)
        {
            for (int j = 0; j < NBMOB; j++)
            {
                flux << tableMob[i][j] << std::endl;
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "Impossible d'ouvrir " << str << std::endl;
    }
}

Wave::~Wave()
{
    //dtor
}
