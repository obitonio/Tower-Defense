#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "Main.h"
#include "Map.h"
#include "MenuEditor.h"

class MapEditor
{
    public:
        MapEditor();

        bool refresh(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window);

        virtual ~MapEditor();
    protected:
    private:
        Map m_map;
        bool m_focus;
        MenuEditor m_MenuEditor;
        sf::RenderWindow m_windowChoice;
        int m_blocID;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Clock m_clock;
};

#endif // MAPEDITOR_H
