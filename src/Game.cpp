#include "Game.h"

Game::Game(sf::RenderWindow &window)
: m_window(window), m_towers(MAXTOWER), m_gold(DEFAULTGOLD), m_wave(m_mob, m_gold), m_map(),
  m_menutower(m_towers, m_gold, m_mob), m_gameOption(), m_state(0)
{
    int i, x;

    for (i = 0; i < MAXTOWER; i++)
    {
        m_towers[i] = new BasicTower();
        m_towers[i]->setMob(m_mob);
    }

    for (i = 0; i < 64; i++)
    {

        m_mob[i].init(sf::Vector2f(0, 0), m_map);
    }
}

int Game::refresh()
{
    if (m_state != 0)
    {
        int i;

        for(i = 0; i < MAXTOWER; i++)
        {
            m_towers[i]->refresh();
        }
        for(i = 0; i < 64; i++)
        {
            if (m_mob[i].refresh())
            {
                m_menutower.decrementeHealth();
            }
        }

        m_wave.refresh(m_map);

        m_menutower.refresh(m_window, m_map);
    }
    else if (m_state == 0)
    {
        m_state = m_gameOption.refresh(m_window);

        if (m_state == - 1)
        {
            return 0;
        }
        else if (m_state > 0)
        {
            switch (m_state)
            {
            case 1:
                m_map.load("map/slot1.txt");
                break;
            case 2:
                m_map.load("map/slot2.txt");
                break;
            case 3:
                m_map.load("map/slot3.txt");
                break;
            case 4:
                m_map.load("map/slot4.txt");
                break;
            case 5:
                m_map.load("map/slot5.txt");
                break;
            case 6:
                m_map.load("map/slot6.txt");
                break;
            case 7:
                m_map.load("map/slot7.txt");
                break;
            }

            m_wave.init();
        }



    }

    return 1;
}

void Game::draw()
{
    m_map.draw(m_window);
    if (m_state != 0)
    {
        int i;

        for(i = 0; i < 16; i++)
        {
            if (m_towers[i])
                m_towers[i]->draw(m_window);
        }
        for(i = 0; i < 64; i++)
        {
            m_mob[i].draw(m_window);
        }
        m_menutower.draw(m_window);
        m_wave.draw(m_window);
    }
    else if (m_state == 0)
    {
        m_gameOption.draw(m_window);
    }
}

Game::~Game()
{
    for (int i = 0; i < 16; i++)
    {
        if (m_towers[i])
            delete m_towers[i];
    }
}
