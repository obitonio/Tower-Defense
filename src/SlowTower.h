#ifndef SLOWTOWER_H
#define SLOWTOWER_H

#include "BasicTower.h"
#include "SlowBullet.h"


class SlowTower : public BasicTower
{
    public:
        SlowTower();

        virtual void refresh();

        virtual void attack(int i);

        virtual ~SlowTower();
    protected:
    private:

};

#endif // SLOWTOWER_H
