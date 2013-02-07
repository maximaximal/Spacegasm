#include "CPlayerManager.h"
#include <iostream>
#include <sstream>

using namespace std;

CPlayerManager::CPlayerManager(CPacketHandler *packetHandler)
{
    m_packetHandler = packetHandler;
    m_packetHandler->getEvent(PTYPE_FULLCONNECT).connect(sigc::mem_fun(this, &CPlayerManager::playerConnectHandler));
}

CPlayerManager::~CPlayerManager()
{
    //dtor
}

void CPlayerManager::playerConnectHandler(sf::Packet packet, ENetPeer *peer)
{
    std::string username;
    packet >> username;
    this->addPlayer(username, peer);
    stringstream msg;
    msg << "[SERVER] Client " << username << " is now connected!" << endl;
    sf::Packet pack;
    pack << PTYPE_CONSOLE_OUTPUT << msg.str();
    m_packetHandler->sendPacket(pack, "", 0, true);
    sf::Packet fullconnect;
    fullconnect << PTYPE_FULLCONNECT << "HALLLLOOOOOOOO" << 0;
    m_packetHandler->sendPacket(fullconnect, username, 0, true);
    cout << msg.str();
}

CPlayerData* CPlayerManager::getPlayer(std::string username)
{
    std::map<std::string, std::shared_ptr<CPlayerData> >::iterator it = m_players.find(username);
    if(it != m_players.end())
    {
        return it->second.get();
    }
    else
    {
        return NULL;
    }
}
CPlayerData* CPlayerManager::getPlayer(ENetPeer *peer)
{
    return getPlayer(m_peers.find(peer)->second);
}
void CPlayerManager::addPlayer(std::string username, ENetPeer *peer)
{
    std::map<std::string, std::shared_ptr<CPlayerData> >::iterator it = m_players.find(username);
    if(it != m_players.end())
    {
        cout << "!! Player >>" << username << "<< is already in the PlayerManager!" << endl;
    }
    else
    {
        shared_ptr<CPlayerData> playerData(new CPlayerData(username));
        playerData->setPeer(peer);
        m_players.insert(std::pair<std::string, std::shared_ptr<CPlayerData> >(username, playerData));
        playerData.reset();
        m_peers.insert(std::pair<ENetPeer*, std::string>(peer, username));
    }
}
void CPlayerManager::removePlayer(std::string username)
{
    std::map<std::string, std::shared_ptr<CPlayerData> >::iterator it = m_players.find(username);
    if(it != m_players.end())
    {
        m_peers.erase(m_peers.find(it->second->getPeer()));
        m_players.erase(it);
    }
}
void CPlayerManager::removePlayer(ENetPeer *peer)
{
    removePlayer(m_peers.find(peer)->second);
}
