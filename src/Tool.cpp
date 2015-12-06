#include "Tool.h"

Tool::Tool()
{
    //ctor
}
bool Tool::button(int x, int y, int length, int width, sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right) &&
       sf::Mouse::getPosition(window).x > x              &&
       sf::Mouse::getPosition(window).x < x + length     &&
       sf::Mouse::getPosition(window).y > y              &&
       sf::Mouse::getPosition(window).y < y + width)
    {
        return true;
    }
    return false;
}
Tool::~Tool()
{
    //dtor
}
