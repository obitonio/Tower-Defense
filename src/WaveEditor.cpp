#include "WaveEditor.h"

WaveEditor::WaveEditor()
:m_text("", m_font), m_position(0, 0), m_lock(false), m_x(0), m_y(0)
{
    m_text.setPosition(m_position);
    m_font.loadFromFile("resource/comic.ttf");
    m_text.setColor(sf::Color::White);

    for (int i = 0; i < NBWAVE; i++)
    {
        for (int j = 0; j < NBMOB; j++)
        {
            m_tableWave[i][j] = 0;
        }
    }
}

void WaveEditor::refresh(sf::RenderWindow &window, sf::Event &event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        sf::Mouse::getPosition(window).x > 0 &&
        sf::Mouse::getPosition(window).x < (NBMOB+1) * 48 &&
        sf::Mouse::getPosition(window).y > 0 &&
        sf::Mouse::getPosition(window).y < (NBWAVE+1) * 48)
    {
        m_lock = true;
        m_x = sf::Mouse::getPosition(window).x/48 - 1;
        m_y = sf::Mouse::getPosition(window).y/48;
        std::cout << "x: " << m_x << " y: " << m_y << std::endl;
    }

   // std::cout << event.type << std::endl;
    if (event.type == sf::Event::TextEntered)
    {
        std::cout << "Event entered";
        if (event.text.unicode >= 48 && event.text.unicode <= 57)
        {
            std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
            std::cout << "x: " << m_x << " y: " << m_y << std::endl;
            m_tableWave[m_y][m_x] = static_cast<char>(event.text.unicode);
        }
    }

}

void WaveEditor::draw(sf::RenderWindow &window)
{
    sf::Vector2f position = m_position;

    /*m_text.setString("Waves");
    m_text.setPosition(position);
    window.draw(m_text);

    position.y += BLOCKSIZE;*/

    for (int i = 0; i < NBWAVE; i++)
    {

        for (int j = 0; j < NBMOB; j++)
        {
            if (j == 0)
            {
                std::stringstream ss;
                ss << i;

                m_text.setString(ss.str());
                m_text.setPosition(position);
                window.draw(m_text);
                position.x += BLOCKSIZE;
            }

            std::stringstream ss;
            ss << m_tableWave[i][j];

            m_text.setString(ss.str());
            m_text.setPosition(position);
            window.draw(m_text);
            position.x += BLOCKSIZE;
        }

        position.x = 0;
        position.y += BLOCKSIZE;
    }
}

WaveEditor::~WaveEditor()
{
    //dtor
}
