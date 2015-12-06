#include "Map.h"

Map::Map()
:m_position(0,0)
{
    this->loadDefault();

    // INIT TEXTURE
    m_texture[BLOCKGRASS].loadFromFile("resource/grass.png");
    m_texture[BLOCKLAND].loadFromFile("resource/land.png");
    m_texture[BLOCKWATER].loadFromFile("resource/water.png");
   // m_texture[3].loadFromFile("resource/b3.png"); // Noir
   // m_texture[4].loadFromFile("resource/b4.png"); // Vert
   // m_texture[5].loadFromFile("resource/b5.png"); // Marron
   // m_texture[6].loadFromFile("resource/tclassic.png"); // Tower classic
    m_texture[BLOCKCASTLETOP].loadFromFile("resource/ctop.png");
    m_texture[BLOCKCASTLEMIDDLE].loadFromFile("resource/cmid.png");
    m_texture[BLOCKCASTLEBOT].loadFromFile("resource/cbot.png");

    m_texture[BLOCKTOWER].loadFromFile("resource/tclassic.png");
    m_texture[BLOCKTOWERLVL2].loadFromFile("resource/tclassic2.png");
    m_texture[BLOCKTOWERSLOW].loadFromFile("resource/tslow.png");

}

void Map::draw(sf::RenderWindow &window)
{

    int i, j;
    sf::Vector2f position = m_position;

    for (i = 0; i < MAPX; i++)
    {
        for (j = 0; j < MAPY; j++)
        {
            m_sprite.setPosition(position);
            m_sprite.setTexture(m_texture[m_map[i][j]]);
            window.draw(m_sprite);

                //m_texture2.update(m_image[m_map[i][j]], position.x, position.y);

            position.y += BLOCKY;
        }
        position.y = 0;
        position.x += BLOCKX;
    }

}

void Map::save(std::string str)
{
    int x, y;
    std::ofstream flux(str.c_str(), std::ios::out);

    if (flux)
    {
        for (x = 0; x < MAPX; x++)
        {
            for (y = 0; y < MAPY; y++)
            {
                flux << m_map[x][y];
            }
        }
        flux.close();
    }
    else
    {
        std::cout << "MAP: Impossible de charger le flux a l'adresse suivante: " << str << std::endl;
    }
}

void Map::load(std::string str)
{
    int x, y;
    std::ifstream flux(str.c_str(), std::ios::in);
    char c = '0';

    if (flux)
    {
        for (x = 0; x < MAPX; x++)
        {
            for (y = 0; y < MAPY; y++)
            {
                flux.get(c);
                m_map[x][y] = c - '0';
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "MAP: Impossible de charger le flux a l'adresse suivante: " << str << std::endl;
    }
}

 void Map::setValue(int x, int y, int value)
 {
    m_map[x][y] = value;
 }

int Map::getValue(int x, int y)
{
    return m_map[x][y];
}

void Map::loadDefault()
{
    // INIT MAP
    int i, j;

    for (i = 0; i < MAPX; i++)
    {
        for (j = 0; j < MAPY; j++)
        {
          m_map[i][j] = BLOCKGRASS;
        }
    } // BACKGROUND

    for (i = 1; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            m_map[i][j] = BLOCKLAND;
        }
    }

    for (i = 1; i < 11; i++)
    {
        for (j = 5; j < 6; j++)
        {
            m_map[i][j] = BLOCKLAND;
        }
    }

    for (i = 10; i < 11; i++)
    {
        for (j = 5; j < 10; j++)
        {
            m_map[i][j] = BLOCKLAND;
        }
    }

    for (i = 10; i < 16; i++)
    {
        for (j = 10; j < 11; j++)
        {
            m_map[i][j] = BLOCKLAND;
        }
    }

    m_map[15][9] = BLOCKCASTLETOP;
    m_map[15][10] = BLOCKCASTLEMIDDLE;
    m_map[15][11] = BLOCKCASTLEBOT;
}

sf::Vector2f Map::getSpawnPosition()
{
    int i;

    for (i = 0; i <= SCREENX/48; i++ )
    {
        if (m_map[i][0] == BLOCKLAND)
        {
            return sf::Vector2f(i*48 + 12, 0);
        }
        else if (m_map[0][i] == BLOCKLAND)
        {
            return sf::Vector2f(12, i*48);
        }
    }
    return sf::Vector2f(0, 0);
}

sf::Image Map::getImage(std::string str, sf::RenderWindow &window)
{
    // STEP 1 LOAD THE MAP
    int map[MAPX][MAPY];
    int x, y;
    std::ifstream flux(str.c_str(), std::ios::in);
    char c = '0';

    if (flux)
    {
        for (x = 0; x < MAPX; x++)
        {
            for (y = 0; y < MAPY; y++)
            {
                flux.get(c);
                map[x][y] = c - '0';
            }
        }

        flux.close();
    }
    else
    {
        std::cout << "MAP: Impossible de charger le flux a l'adresse suivante: " << str << std::endl;
    }

    // STEP 2 CONVERT INTO IMAGE

    // INIT TEXTURE
    int i, j;
    sf::Vector2f position(0, 0);
    sf::Texture texture;
    sf::Image image[TEXTURE], image2;

    image[BLOCKGRASS].loadFromFile("resource/grass.png");
    image[BLOCKLAND].loadFromFile("resource/land.png");
    image[BLOCKWATER].loadFromFile("resource/water.png");
    image[BLOCKCASTLETOP].loadFromFile("resource/ctop.png");
    image[BLOCKCASTLEMIDDLE].loadFromFile("resource/cmid.png");
    image[BLOCKCASTLEBOT].loadFromFile("resource/cbot.png");
    image[BLOCKTOWER].loadFromFile("resource/tclassic.png");
    image[BLOCKTOWERSLOW].loadFromFile("resource/tslow.png");

    for (i = 0; i < MAPX; i++)
    {
        for (j = 0; j < MAPY; j++)
        {

            texture.update(image[map[i][j]], position.x, position.y);

            position.y += BLOCKY;
        }
        position.y = 0;
        position.x += BLOCKX;
    }

    image2 = texture.copyToImage();
    image2.saveToFile("test.png");

    return image2;
}

Map::~Map()
{
    //dtor
}
