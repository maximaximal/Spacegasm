#include <CServer.h>
#include <iostream>
#include <enet/enet.h>
#include <sstream>
#include <IPConverter.h>
#include <SFML/Network.hpp>
#include <CPacketHandler.h>

using namespace std;

void CServer::onUpdate()
{
    stringstream address;
    ENetEvent event;
    unsigned int ip;
    string msg;
    sf::Packet packet;

    unsigned short eventState = enet_host_service(m_server, &event, 1000);

    if(eventState > 0)
    {
        switch(event.type)
        {
            case ENET_EVENT_TYPE_CONNECT:
                cout << "[SERVER] Client Connecting... " << IPConverter::toString(event.peer->address.host) << endl;
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                packet.clear();
                packet.append(event.packet->data, event.packet->dataLength);
                packetHandler->handlePacket(packet, event.peer);
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                stringstream disconnectedInfo;
                disconnectedInfo << "[SERVER] Client " << playerManager->getPlayer(event.peer)->getName() << " disconnected! (" << event.data << ")" << endl;
                cout << disconnectedInfo.str();
                playerManager->removePlayer(event.peer);
                event.peer = NULL;
                sf::Packet  packet;
                packet << PTYPE_CONSOLE_OUTPUT << disconnectedInfo.str();
                sendPacket(packet, "", 0, true);
                break;
        }
    }
}
