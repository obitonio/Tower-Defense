#ifndef GAMEOPTION_H
#define GAMEOPTION_H

#include "Main.h"
#include "Button.h"

class GameOption
{
    public:
        GameOption();

        int refresh(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window);

        virtual ~GameOption();
    protected:
    private:
        Button m_bMTitle, m_bMChoice;
        Button m_bMap1, m_bMap2, m_bMap3, m_bMap4;
        Button m_bMapS1, m_bMapS2, m_bMapS3;
        bool m_customMap;
};

#endif // GAMEOPTION_H
