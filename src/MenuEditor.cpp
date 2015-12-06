#include "MenuEditor.h"

MenuEditor::MenuEditor(/*std::string textureLink, std::string textureFocus, sf::Vector2f position*/)
:m_B1("resource/button1.png", sf::Vector2f(288, 96)),
m_B2("resource/button2.png", sf::Vector2f(288, 192)),
m_B3("resource/button3.png", sf::Vector2f(288, 288)),
m_B4("resource/button4.png", sf::Vector2f(288, 384)),
m_Slot1("resource/slot.png", sf::Vector2f(336, 144)),
m_Slot2("resource/slot.png", sf::Vector2f(336, 240)),
m_Slot3("resource/slot.png", sf::Vector2f(336, 336)),
m_choix(0),
m_slot(0)
{

}

int MenuEditor::refresh(sf::RenderWindow &window)
{
    if (m_choix == 0)
    {
        if(m_B1.mouseReleased(window))
        {
            m_choix = 1;
        }

        if(m_B2.mouseReleased(window))
        {
            m_choix = 2;
        }

        if(m_B3.mouseReleased(window))
        {
            m_choix = 3;
        }

        if(m_B4.mouseReleased(window))
        {
            m_choix = 4;
        }
    }
    else if (m_choix == 1 || m_choix == 2)
    {
        if(m_Slot1.mouseReleased(window))
        {
            m_slot = 1;
        }

        if(m_Slot2.mouseReleased(window))
        {
            m_slot = 2;
        }

        if(m_Slot3.mouseReleased(window))
        {
            m_slot = 3;
        }
    }

    return m_choix;
}

int MenuEditor::getSlot()
{
    return m_slot;
}

void MenuEditor::reset()
{
    m_choix = 0;
    m_slot = 0;
}

void MenuEditor::draw(sf::RenderWindow &window)
{
    if (m_choix == 0)
    {
        m_B1.draw(window);
        m_B2.draw(window);
        m_B3.draw(window);
        m_B4.draw(window);
    }
    else if (m_choix == 1 || m_choix == 2)
    {
        m_Slot1.draw(window);
        m_Slot2.draw(window);
        m_Slot3.draw(window);
    }
}

MenuEditor::~MenuEditor()
{
    //dtor
}
