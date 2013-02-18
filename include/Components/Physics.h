#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>
#include <Component.h>
#include <mutex>

namespace Component
{
    class Physics : public artemis::Component
    {
        public:
            Physics(b2BodyDef *bodydef, b2World *world);
            virtual ~Physics();
            bool isDirty();
            void setDirty(bool dirty);
            b2Body* getBody();
        protected:
        private:
            bool m_dirty;
            std::mutex m_dirtyMutex;
            b2World *m_world;
            b2Body *m_body;
    };
}


#endif // PHYSICS_H
