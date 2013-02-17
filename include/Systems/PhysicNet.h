#ifndef CPHYSICNET_H
#define CPHYSICNET_H

#include <map>
#include <Packets/physUpdate.h>

#include <Box2D/Box2D.h>
#include <EntityProcessingSystem.h>
#include <Entity.h>
#include <ComponentMapper.h>
#include <CPacketHandler.h>
#include <CPhysicsManager.h>
#include <Components/Physics.h>
namespace System
{
    class PhysicNet : public artemis::EntityProcessingSystem
    {
        public:
            PhysicNet(CPacketHandler *handler, artemis::World *world, CPhysicsManager *physicsManager);
            virtual void initialize();
            virtual void processEntity(artemis::Entity &e);
            void physUpdateHandler(sf::Packet packet, ENetPeer *peer);
        private:
            CPacketHandler *m_handler;
            CPhysicsManager *m_physicsManager;
            artemis::World *m_world;
            artemis::ComponentMapper<Component::Physics> m_physicsMapper;
            std::map<unsigned int, Packet::physUpdate> m_updateBuffer;
    };
}

#endif
