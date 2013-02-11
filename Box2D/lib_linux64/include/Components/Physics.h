#ifndef PHYSICS_H
#define PHYSICS_H

#include <Component.h>
#include <Box2D.h>

namespace Component
{
    class Physics
    {
        public:
            Physics(b2Body);
            virtual ~Physics();
        protected:
        private:
    };
}

#endif // PHYSICS_H
