#include "CServer.h"
#include <iostream>

using namespace std;

CServer::CServer()
{
    //ctor
}

CServer::~CServer()
{
    //dtor
}

void CServer::sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable)
{
    ENetPacket *enetPacket;
    if(relieable)
        enetPacket = enet_packet_create(packet.getData(), packet.getDataSize() + 1, ENET_PACKET_FLAG_RELIABLE);
    else
        enetPacket = enet_packet_create(packet.getData(), packet.getDataSize() + 1, ENET_PACKET_FLAG_UNRELIABLE_FRAGMENT);
    if(username != "")
    {
        enet_peer_send(playerManager->getPlayer(username)->getPeer(), channel, enetPacket);
    }
    else
    {
        enet_host_broadcast(m_server, channel, enetPacket);
    }
    enet_host_flush(m_server);
}
void CServer::sendPacket(sf::Packet& packet, std::vector<std::string> username, unsigned int channel, bool relieable)
{
    vector<string>::iterator it;
    for(it = username.begin(); it != username.end(); ++it)
    {
        this->sendPacket(packet, *it, channel, relieable);
    }
}
