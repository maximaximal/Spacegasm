#include <Box2D/Box2D.h>

#include <System.h>
#include <Entity.h>

#include <CPhysicsManager.h>

namespace System
{
    class PhysicNetServer : public artemis::EntityProcessingSystem
    {
        public:
            PhysicNetServer(artemis::World *world, CPhysicsManager *physicsManager);
            virtual void initialize();
            virtual void processEntity(artemis::Entity &e)
        private:
            artemis::ComponentMapper<Component::Physics> m_physicsComponent;
            artemis::World *m_world;
            CPhysicsManager *m_PhysicsManager;
    }
}
