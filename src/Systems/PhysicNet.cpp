#include <Systems/PhysicNet.h>

namespace System
{
    PhysicNet::PhysicNet(CPacketHandler *handler, artemis::World *world, CPhysicsManager *physicsManager)
    {
        m_handler = handler;
        m_world = world;
        m_physicsManager = physicsManager;
        addComponentType<Component::Physics>();
    }
    void PhysicNet::initialize()
    {
        m_physicsMapper.init(*m_world);
    }
    void PhysicNet::processEntity(artemis::Entity &e)
    {
        if(m_updateBuffer.count(e.getId()) > 0)
        {
            b2Body *body = m_physicsMapper.get(e)->getBody();
            m_physicsManager->lock();
            body->SetTransform(m_updateBuffer[e.getId()].pos, m_updateBuffer[e.getId()].angle);
            body->SetAngularVelocity(m_updateBuffer[e.getId()].angVelocity);
            body->SetLinearVelocity(m_updateBuffer[e.getId()].velocity);
            m_physicsManager->unlock();
            m_updateBuffer.erase(m_updateBuffer.find(e.getId()));
        }
    }
    void PhysicNet::physUpdateHandler(sf::Packet packet, ENetPeer *peer)
    {
        Packet::physUpdate phys;
        packet >> phys;
        m_updateBuffer[phys.entityID] = phys;
    }
}
