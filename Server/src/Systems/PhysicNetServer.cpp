#include <Systems/PhysicNetServer.h>
#include <Packets/physUpdate.h>
namespace System
{
    PhysicNetServer::PhysicNetServer(artemis::World *world, CPhysicsManager *physicsManager, CPacketHandler *packetHandler)
    {
        m_world = world;
        m_packetHandler = packetHandler;
        m_physicsManager = physicsManager;
        addComponentType<Component::Physics>();
    }
    void PhysicNetServer::initialize()
    {
        m_physicsMapper.init(*m_world);
    }
    void PhysicNetServer::processEntity(artemis::Entity &e)
    {
        if(m_physicsMapper.get(e)->isDirty())
        {
            sf::Packet update;
            Packet::physUpdate phys;
            phys.velocity       = m_physicsMapper.get(e)->getBody()->GetLinearVelocity();
            phys.angle          = m_physicsMapper.get(e)->getBody()->GetAngle();
            phys.angVelocity    = m_physicsMapper.get(e)->getBody()->GetAngularVelocity();
            phys.pos            = m_physicsMapper.get(e)->getBody()->GetPosition();
            phys.entityID       = e.getId();
            update << PTYPE_ENTITY_PHYSICS_UPDATE << phys;
            m_packetHandler->sendPacket(update, "", 1, false);
            m_physicsMapper.get(e)->setDirty(false);
        }
    }
}
