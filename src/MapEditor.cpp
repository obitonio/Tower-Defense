#include "MapEditor.h"

MapEditor::MapEditor()
:m_windowChoice(sf::VideoMode(146, 146), "Bloc"), m_blocID(0), m_map(), m_focus(false)
{
    m_windowChoice.setVisible(false);
    m_windowChoice.setPosition(sf::Vector2i(0, 0));

    m_texture.loadFromFile("resource/mapEditor.png");
    m_sprite.setTexture(m_texture);

    m_map.load();
}

bool MapEditor::refresh(sf::RenderWindow &window)
{

    if (m_focus == 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_clock.getElapsedTime().asSeconds() > 1)
        {
            m_focus = 1;
            m_clock.restart();
            m_MenuEditor.reset();
        }

        int i, x, y;
        m_windowChoice.setVisible(true);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            m_map.setValue(sf::Mouse::getPosition(window).x/48, sf::Mouse::getPosition(window).y/48, m_blocID);
        }

        x = 0;
        y = 0;
        for (i = 0; i <= 2; i++)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                sf::Mouse::getPosition(m_windowChoice).x > x && sf::Mouse::getPosition(m_windowChoice).x < (x + 48) &&
                sf::Mouse::getPosition(m_windowChoice).y > y && sf::Mouse::getPosition(m_windowChoice).y < (y + 48))
            {
                    switch (i)
                    {
                    case 0:
                        m_blocID = BLOCKGRASS;
                        break;
                    case 1:
                        m_blocID = BLOCKLAND;
                        break;
                    case 2:
                        m_blocID = BLOCKWATER;
                        break;
                    }
            }
            x += 48;
        }

        x = 0;
        y = 96;
        for (i = 0; i <= 2; i++)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                sf::Mouse::getPosition(m_windowChoice).x > x && sf::Mouse::getPosition(m_windowChoice).x < (x + 48) &&
                sf::Mouse::getPosition(m_windowChoice).y > y && sf::Mouse::getPosition(m_windowChoice).y < (y + 48))
            {
                    switch (i)
                    {
                    case 0:
                        m_blocID = BLOCKCASTLETOP;
                        break;
                    case 1:
                        m_blocID = BLOCKCASTLEBOT;
                        break;
                    case 2:
                        m_blocID = BLOCKCASTLEMIDDLE;
                        break;
                    }
            }
            x += 48;
        }

    }
    else if (m_focus == 1)
    {
        m_windowChoice.setVisible(false);

        switch(m_MenuEditor.refresh(window))
        {
            case 1: //Charger Map
                if(m_MenuEditor.getSlot() == 1)
                {
                    m_map.load("map/slot5.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
                else if(m_MenuEditor.getSlot() == 2)
                {
                    m_map.load("map/slot6.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
                else if(m_MenuEditor.getSlot() == 3)
                {
                    m_map.load("map/slot7.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
              break;

            case 2: //Sauvegarder Map

                if(m_MenuEditor.getSlot() == 1)
                {
                    m_map.save("map/slot5.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
                else if(m_MenuEditor.getSlot() == 2)
                {
                    m_map.save("map/slot6.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
                else if(m_MenuEditor.getSlot() == 3)
                {
                    m_map.save("map/slot7.txt");
                    m_focus = 0;
                    m_MenuEditor.reset();
                }
              break;

            case 3: //Retour Menu
                return true;
              break;
            case 4: //Retour Bureau
                m_windowChoice.close();
                window.close();
              break;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_clock.getElapsedTime().asSeconds() > 1)
        {
            m_focus = 0;
            m_clock.restart();
            m_MenuEditor.reset();
        }
    }
    return false;
}

void MapEditor::draw(sf::RenderWindow &window)
{
    m_map.draw(window);

    if (m_focus == 0)
    {
        m_windowChoice.clear();
        m_windowChoice.draw(m_sprite);
        m_windowChoice.display();
    }
    else if (m_focus == 1)
    {
        m_MenuEditor.draw(window);
    }

}

MapEditor::~MapEditor()
{
    //dtor
}
