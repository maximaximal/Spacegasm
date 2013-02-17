#ifndef SYSTEM-PHYSICNETSERVER_H
#define SYSTEM-PHYSICNETSERVER_H

#include <Box2D/Box2D.h>

#include <EntityProcessingSystem.h>
#include <Entity.h>
#include <ComponentMapper.h>
#include <CPhysicsManager.h>
#include <Components/Physics.h>
namespace System
{
    class PhysicNetServer : public artemis::EntityProcessingSystem
    {
        public:
            PhysicNetServer(artemis::World *world, CPhysicsManager *physicsManager);
            virtual void initialize();
            virtual void processEntity(artemis::Entity &e);
        private:
            artemis::ComponentMapper<Component::Physics> m_physicsMapper;
            artemis::World *m_world;
            CPhysicsManager *m_physicsManager;
    };
}

#endif
