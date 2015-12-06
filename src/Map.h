#ifndef MAP_H
#define MAP_H

#include "Main.h"

#define TEXTURE 16
#define BLOCKX 48
#define BLOCKY 48
#define MAPX SCREENX/BLOCKX
#define MAPY SCREENY/BLOCKY

class Map
{
    public:
        Map();

        void draw(sf::RenderWindow &window);

        void save(std::string str = "resource/slot1.txt");

        void load(std::string str = "resource/slot1.txt");

        void loadDefault();

        void setValue(int x, int y, int value);

        sf::Vector2f getSpawnPosition();

        int getValue(int x, int y);

        static sf::Image getImage(std::string str, sf::RenderWindow &window);

        virtual ~Map();
    protected:
    private:
        sf::Vector2f m_position;
        sf::Texture m_texture[TEXTURE];
        sf::Sprite m_sprite;
        int m_map[MAPX][MAPY];
};

#endif // MAP_H
