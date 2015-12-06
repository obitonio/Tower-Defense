#include "MenuTower.h"

MenuTower::MenuTower(std::vector<BasicTower*> &basicTower, int &gold, Mob *mob)
:m_basicTower(basicTower), m_gold(gold), m_mob(mob)
{

    m_texture.loadFromFile("resource/menuTower.png");
    m_textureTowerClassic.loadFromFile("resource/tclassic.png");
    m_textureTowerSlow.loadFromFile("resource/tslow.png");
    m_textureCompteurGold.loadFromFile("resource/compteurGold.png");
    m_font.loadFromFile("resource/comic.ttf");

    m_sprite.setTexture(m_texture);
    m_spriteCompteurGold.setTexture(m_textureCompteurGold);

    m_sprite.setPosition((SCREENX/2) - 71, SCREENY - 36);
    m_spriteCompteurGold.setPosition((SCREENX/2) - 60, m_sprite.getPosition().y - 90);//(SCREENX/2) - 60, m_sprite.getPosition().y - 48

    m_i = 0;
    m_gold = 100;                           //Initialisation des variables
    m_health = 10;

    m_goldString << m_gold;                 //Conversion des ints  en strings
    m_healthString << m_health;

    m_textGold.setString(m_goldString.str()); //Initialisation des text ici des golds
    m_textGold.setFont(m_font);
    m_textGold.setPosition(m_spriteCompteurGold.getPosition().x +15, m_spriteCompteurGold.getPosition().y+ 52);
    m_textGold.setCharacterSize(20);
    m_textGold.setColor(sf::Color::Yellow);

    m_textHealth = m_textGold;
    m_textHealth.setPosition(m_spriteCompteurGold.getPosition().x + 45, m_spriteCompteurGold.getPosition().y);
    m_textHealth.setString(m_healthString.str());
    m_textHealth.setColor(sf::Color::Black);
    m_textHealth.setCharacterSize(30);
}

void MenuTower::refresh(sf::RenderWindow &window, Map &map)
{
    if(Tool::button(m_sprite.getPosition().x, m_sprite.getPosition().y, 36, 36, window) == true && m_i < 16)   //Bouton 1 du menu  ClassicTower
    {
        m_type = 1;     //Type de la tower  1 = classicTower
        m_lock = true;
        m_spriteTower.setTexture(m_textureTowerClassic);
    }
    else if(Tool::button((m_sprite.getPosition().x+ 36), (m_sprite.getPosition().y), 36, 36, window) == true && m_i < 16) //Bouton 2 du menu Slowtower
    {
        m_type = 2;     //Type de la tower  2 = slowTower
        m_lock = true;
        m_spriteTower.setTexture(m_textureTowerSlow);   //Défini la Texture de la tower sélectionné
    }
    this->spriteLock(window, map);
}
void MenuTower::spriteLock(sf::RenderWindow &window, Map &map)
{
    if(m_lock)
    {


        m_spriteTower.setPosition(sf::Mouse::getPosition(window).x , sf::Mouse::getPosition(window).y);


            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&       //Si case innocupé
               map.getValue((sf::Mouse::getPosition(window).x /48), (sf::Mouse::getPosition(window).y/48)) == BLOCKGRASS)
            {
                if (m_type == 1 && (m_gold - 100) >= 0 && m_i < MAXTOWER)
                {
                    m_basicTower[m_i]->setPosition(sf::Vector2f((sf::Mouse::getPosition(window).x/48 * 48), (sf::Mouse::getPosition(window).y/48) * 48));    //Définit la position fixe de la tower
                    map.setValue((sf::Mouse::getPosition(window).x /48), (sf::Mouse::getPosition(window).y /48), BLOCKTOWER);   //Case de la map passe de vide -> tower
                    m_gold -= 100;
                }
                else if (m_type == 2 && (m_gold - 50) >= 0 && m_i < MAXTOWER)
                {
                    delete m_basicTower[m_i];
                    m_basicTower[m_i] = new SlowTower();
                    m_basicTower[m_i]->setMob(m_mob);
                    m_basicTower[m_i]->setPosition(sf::Vector2f((sf::Mouse::getPosition(window).x/48 * 48), (sf::Mouse::getPosition(window).y/48) * 48));
                    map.setValue((sf::Mouse::getPosition(window).x /48), (sf::Mouse::getPosition(window).y /48), BLOCKTOWERSLOW);   //Case de la map passe de vide -> tower
                    m_gold -= 50;
                }
                //std::cout << "x: " << sf::Mouse::getPosition(window).x /48 << " y: " << sf::Mouse::getPosition(window).y /48 << std::endl;


                m_i++;
                m_lock = false;
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) &&    //Si clic droir déselectionne la Tower
                     (sf::Mouse::getPosition(window).x <= m_sprite.getPosition().x || sf::Mouse::getPosition(window).x >= m_sprite.getPosition().x + 141) &&
                     (sf::Mouse::getPosition(window).y <= m_sprite.getPosition().y || sf::Mouse::getPosition(window).y >= m_sprite.getPosition().y + 36))
            {
                m_lock = false;
            }
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) &&       //Si case innocupé
            map.getValue((sf::Mouse::getPosition(window).x /48), (sf::Mouse::getPosition(window).y/48)) == BLOCKTOWER && !m_lock ||
            sf::Mouse::isButtonPressed(sf::Mouse::Right) &&
            map.getValue((sf::Mouse::getPosition(window).x /48), (sf::Mouse::getPosition(window).y/48)) == BLOCKTOWERSLOW && !m_lock)
    {
        for (int i = 0; i < MAXTOWER; i++)
        {
            if (m_basicTower[i]->getPosition().x/48 == sf::Mouse::getPosition(window).x /48 &&
                m_basicTower[i]->getPosition().y/48 == sf::Mouse::getPosition(window).y /48 &&
                m_basicTower[i]->getLevel() == 0 &&
                m_gold - TCLASSIC2PRICE >= 0)
            {
                m_gold -= TCLASSIC2PRICE;
                m_basicTower[i]->upgrade();
                map.setValue(sf::Mouse::getPosition(window).x /48, sf::Mouse::getPosition(window).y /48, BLOCKTOWERLVL2);
               // std::cout << "Value " << map.getValue(sf::Mouse::getPosition(window).x /48, sf::Mouse::getPosition(window).y /48) << std::endl;
                continue;
            }
        }
    }
}
sf::Vector2f MenuTower::getPosition()
{
    return m_spriteTower.getPosition();
}
void MenuTower::draw(sf::RenderWindow &window)
{
    std::stringstream g, h;
    g << m_gold;
    h << m_health;
    if(m_health <= 9)
    {
        m_textHealth.setPosition(m_spriteCompteurGold.getPosition().x + 50, m_spriteCompteurGold.getPosition().y);
    }

    m_textGold.setString(g.str());
    m_textHealth.setString(h.str());

    window.draw(m_sprite);
    window.draw(m_spriteCompteurGold);
    if(m_lock)
    {
        window.draw(m_spriteTower);
    }
    window.draw(m_textGold);
    window.draw(m_textHealth);

}

void MenuTower::setHealth(int health)
{
    m_health = health;
}

void MenuTower::decrementeHealth()
{
    m_health--;
}

MenuTower::~MenuTower()
{
    //dtor
}
