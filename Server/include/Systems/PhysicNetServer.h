#ifndef SYSTEM-PHYSICNETSERVER_H  //
#define SYSTEM-PHYSICNETSERVER_H  //

#include <Box2D/Box2D.h>

#include <EntityProcessingSystem.h>
#include <Entity.h>
#include <ComponentMapper.h>
#include <CPhysicsManager.h>
#include <Components/Physics.h>
#include <CPacketHandler.h>

namespace System
{
    class PhysicNetServer : public artemis::EntityProcessingSystem
    {
        public:
            PhysicNetServer(artemis::World *world, CPhysicsManager *physicsManager, CPacketHandler *packetHandler);
            virtual void initialize();
            virtual void processEntity(artemis::Entity &e);
        private:
            artemis::ComponentMapper<Component::Physics> m_physicsMapper;
            artemis::World *m_world;
            CPacketHandler *m_packetHandler;
            CPhysicsManager *m_physicsManager;
    };
}

#endif
