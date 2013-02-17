#include <Systems/PhysicNetServer.h>

namespace System
{
    PhysicNetServer::PhysicNetServer(artemis::World *world, CPhysicsManager *physicsManager)
    {
        m_world = world;
        m_physicsManager = physicsManager;
        addComponentType<Component::Physics>();
    }
    void PhysicNetServer::initialize()
    {
        m_physicsMapper.init(*m_world);
    }
    void PhysicNetServer::processEntity(artemis::Entity &e)
    {

    }
}
