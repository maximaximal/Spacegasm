#ifndef CSERVER_H
#define CSERVER_H

#define NET_PORT 17001

#include <enet/enet.h>
#include <CChatManager.h>
#include <CPacketSender.h>
#include <CPeerManager.h>
#include <CPlayerManager.h>
#include <CPacketHandler.h>
#include <SFML/Network.hpp>
#include <string>
#include <vector>
#include <World.h>
#include <SystemManager.h>
#include <EntityManager.h>
#include <CPhysicsManagerServer.h>
#include <Systems/PhysicNetServer.h>

class CServer : public CPacketSender
{
    public:
        CServer();
        virtual ~CServer();

        void onInit();
        void onUpdate();
        void onExit();

        virtual void sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable);
        virtual void sendPacket(sf::Packet& packet, std::vector<std::string> username, unsigned int channel, bool relieable);
    protected:
    private:
        bool m_running;
        CChatManager *chatManager;
        CPlayerManager *playerManager;
        CPeerManager *peerManager;
        CPacketHandler *packetHandler;
        ENetHost *m_server;
        ENetAddress *m_address;
        //Artemis
            artemis::World *m_world;
            artemis::EntityManager *m_entityManager;
            artemis::SystemManager *m_systemManager;
        //systems
            System::PhysicNetServer *m_physicNetServer;
        CPhysicsManagerServer *m_physicsManager;
};

#endif // CSERVER_H
