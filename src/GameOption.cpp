#include "GameOption.h"

GameOption::GameOption()
:m_bMTitle("resource/go/t1.png", "resource/go/t1b.png", sf::Vector2f(96, 48)),
m_bMChoice("resource/go/t2.png", "resource/go/t2b.png", sf::Vector2f(96, 480)),
m_bMap1("resource/go/m1.png", "resource/go/m1b.png", sf::Vector2f(48, 144)),
m_bMap2("resource/go/m2.png", "resource/go/m2b.png", sf::Vector2f(48, 288)),
m_bMap3("resource/go/m3.png", "resource/go/m.png", sf::Vector2f(192, 144)),
m_bMap4("resource/go/m4.png", "resource/go/m.png", sf::Vector2f(192, 288)),
m_bMapS1("resource/go/ms1.png", "resource/go/m.png", sf::Vector2f(96, 144)),
m_bMapS2("resource/go/ms2.png", "resource/go/m.png", sf::Vector2f(96, 240)),
m_bMapS3("resource/go/ms3.png", "resource/go/m.png", sf::Vector2f(96, 336)),
m_customMap(false)
{
    //ctor
}

int GameOption::refresh(sf::RenderWindow &window)
{
    //m_bMTitle.mousePressed(window);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return -1;

    if (m_customMap)
    {
        if (m_bMapS1.mousePressed(window))
        {
            return 5;
        }
        else if (m_bMapS2.mousePressed(window))
        {
            return 6;
        }
        else if(m_bMapS3.mousePressed(window))
        {
            return 7;
        }

        if (m_bMChoice.mouseReleased(window))
            m_customMap = false;
    }
    else if (!m_customMap)
    {
        if (m_bMChoice.mouseReleased(window))
            m_customMap = true;

        if (m_bMap1.mousePressed(window))
        {
            return 1;
        }
        else if (m_bMap2.mousePressed(window))
        {
            return 2;
        }
        else if (m_bMap3.mousePressed(window))
        {
            return 3;
        }
        else if (m_bMap4.mousePressed(window))
        {
            return 4;
        }
    }
    return 0;

}

void GameOption::draw(sf::RenderWindow &window)
{
    m_bMTitle.draw(window);
    m_bMChoice.draw(window);
    if (m_customMap)
    {
        m_bMapS1.draw(window);
        m_bMapS2.draw(window);
        m_bMapS3.draw(window);
    }
    else
    {
        m_bMap1.draw(window);
        m_bMap2.draw(window);
        m_bMap3.draw(window);
        m_bMap4.draw(window);
    }

}

GameOption::~GameOption()
{
    //dtor
}
