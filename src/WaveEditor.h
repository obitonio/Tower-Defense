#ifndef WAVEEDITOR_H
#define WAVEEDITOR_H

#include "Main.h"

class WaveEditor
{
    public:
        WaveEditor();

        void refresh(sf::RenderWindow &window, sf::Event &event);

        void draw(sf::RenderWindow &window);

        virtual ~WaveEditor();
    protected:
    private:
        int m_tableWave[NBWAVE][NBMOB];
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_position;
        bool m_lock;
        int m_x, m_y;
};

#endif // WAVEEDITOR_H
