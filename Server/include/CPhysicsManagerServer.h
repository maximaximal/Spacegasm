#include <Box2D/Box2D.h>
#include <thread>
#include <mutex>
#include <CPhysicsManager.h>

class CPhysicsManagerServer : public CPhysicsManager
{
    public:
        CPhysicsManagerServer();
        virtual ~CPhysicsManagerServer();

        void init();

        b2World* getWorld();

        void lock();
        void unlock();
    private:
        b2World *m_world;
        std::mutex m_worldMutex;
        std::thread m_stepThread;
};
