#ifndef CPHYSICSMANAGER_H
#define CPHYSICSMANAGER_H

#include <Box2D/Box2D.h>
#include <mutex>

class CPhysicsManager
{
    public:
        CPhysicsManager()
        {
            m_world = new b2World(b2Vec2(0, 0));
        }
        virtual ~CPhysicsManager()
        {
            delete m_world;
        }
        void lock()
        {
            m_worldMutex.lock();
        }
        void unlock()
        {
            m_worldMutex.unlock();
        }
        b2World* getWorld()
        {
            return m_world;
        }
    protected:
        b2World *m_world;
        std::mutex m_worldMutex;
};

#endif
