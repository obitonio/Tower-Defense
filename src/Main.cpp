#include "Main.h"
#include "Game.h"
#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENX, SCREENY), "Tower defense Alpha");

    Menu menu;
    MapEditor mapEditor;
    WaveEditor waveEditor;
    Game game(window);

    int step = 0;
    sf::Clock clock;
    sf::Time nextTime = clock.getElapsedTime();
    sf::Time delta = sf::seconds(1/40.f); // 60 FPS

    //Map::getImage("map/slot1.txt", window); //TODO Repair that fucking cheat !!!
    //TODO =================================================
    //TODO Plus de mob
    //TODO More upgrade
    //TODO Upgrade pannel
    //TODO Meilleur texture
    //TODO =================================================

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                std::cout <<"z";
            }
        }




        sf::Time currTime = clock.getElapsedTime();
        if(currTime >= nextTime)
        {
                    // assign the time for the next update
            nextTime += delta;
            window.clear();

            switch (step)
            {
            case 0:
                step = menu.update(window);
                menu.draw(window);
                break;
            case 1:
                step = game.refresh();
                game.draw();
                break;
            case 2:
                if (mapEditor.refresh(window))
                    step = 0;

                mapEditor.draw(window);
                break;
            case 3:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    step = 0;

                waveEditor.refresh(window, event);
                waveEditor.draw(window);
                break;
            case 4:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    step = 0;
                break;
            }
            window.display();
        }
        else
        {
                // calculate the time to sleep
            sf::Time sleepTime = nextTime - currTime;
            // sanity check
            if(sleepTime.asMilliseconds() > 0)
            {
                    // sleep until the next update
                sf::sleep(sleepTime);
            }
        }

    }

    return 0;
}
