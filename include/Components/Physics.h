#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>
#include <Component.h>

namespace Component
{
    class Physics : public artemis::Component
    {
        public:
            Physics(b2BodyDef *bodydef, b2World *world);
            virtual ~Physics();

            b2Body* getBody();
        protected:
        private:
            b2World *m_world;
            b2Body *m_body;
    };
}


#endif // PHYSICS_H
