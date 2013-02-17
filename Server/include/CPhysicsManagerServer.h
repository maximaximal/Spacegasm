#include <Box2D.h>

class CPhysicsManagerServer 
{
    public:
        CPhysicsManagerServer();
        ~CPhysicsManagerServer();

        b2World* getWorld();

        void lock();
        void unlock();
}
