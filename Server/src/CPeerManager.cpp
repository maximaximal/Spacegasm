#include "CPeerManager.h"

CPeerManager::CPeerManager(ENetHost *host)
{
    m_host = host;
    m_peerIndex = 1;
}

CPeerManager::~CPeerManager()
{
    //dtor
}

unsigned int CPeerManager::add(ENetPeer* peer)
{
    m_peers.insert(std::pair<unsigned int, ENetPeer*>(m_peerIndex, peer));
    m_peerIndex++;
}

ENetPeer* CPeerManager::get(unsigned int ID)
{
    std::map<unsigned int, ENetPeer*>::iterator it = m_peers.find(ID);
    return it->second;
}

void CPeerManager::remove(unsigned int ID)
{
    std::map<unsigned int, ENetPeer*>::iterator it = m_peers.find(ID);
    if(it != m_peers.end())
    {
        m_peers.erase(it);
    }
}
