#ifndef SLOWBULLET_H
#define SLOWBULLET_H

#include "Bullet.h"


class SlowBullet : public Bullet
{
    public:
        SlowBullet();

        void refresh();

        virtual ~SlowBullet();
    protected:
    private:
};

#endif // SLOWBULLET_H
