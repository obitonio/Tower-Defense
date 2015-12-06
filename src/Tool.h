#ifndef TOOL_H
#define TOOL_H
#include "Main.h"

class Tool
{
    public:
        Tool();

        static bool button (int x, int y,  int lengt, int width, sf::RenderWindow &window);

        virtual ~Tool();
    protected:
    private:
};

#endif // TOOL_H
