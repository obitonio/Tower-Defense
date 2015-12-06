#ifndef MENUEDITOR_H
#define MENUEDITOR_H

#include "Main.h"
#include "Button.h"

class MenuEditor
{
    public:
        MenuEditor(/*std::string textureLink, std::string textureFocus, sf::Vector2f position*/);
        int refresh(sf::RenderWindow &window);
        void draw(sf::RenderWindow &window);
        int getSlot();
        void reset();

        virtual ~MenuEditor();
    protected:
    private:
        sf::Texture m_textureB1, m_textureB2, m_textureB3, m_textureB4, m_textureFocusB1, m_textureFocusB2, m_textureFocusB3, m_textureFocusB4;
        Button m_B1, m_B2, m_B3, m_B4, m_Slot1, m_Slot2, m_Slot3;
        int m_choix, m_slot;;
};

#endif // MENUEDITOR_H

