#include "CPacketHandler.h"
#include <string>
#include <iostream>
using namespace std;

CPacketHandler::CPacketHandler()
{
    m_sender = NULL;
}

CPacketHandler::~CPacketHandler()
{
    //Nothing
}
void CPacketHandler::setSender(CPacketSender *sender)
{
    m_sender = sender;
}
void CPacketHandler::sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable)
{
    if(m_sender != NULL)
        m_sender->sendPacket(packet, username, channel, relieable);
}
void CPacketHandler::handlePacket(sf::Packet packet, ENetPeer *peer)
{
    unsigned int type;
    packet >> type;
    std::map<unsigned int, sigc::signal<void, sf::Packet , ENetPeer*> >::iterator it = m_signals.find(type);
    if(it != m_signals.end())
    {
        it->second(packet, peer);
    }
}
sigc::signal<void, sf::Packet , ENetPeer*>& CPacketHandler::getEvent(unsigned int type)
{
    std::map<unsigned int, sigc::signal<void, sf::Packet , ENetPeer*> >::iterator it = m_signals.find(type);
    if(it == m_signals.end())
    {
        sigc::signal<void, sf::Packet , ENetPeer*> signal;
        m_signals.insert(std::pair<unsigned int, sigc::signal<void, sf::Packet , ENetPeer*> >(type, signal));
        return m_signals.find(type)->second;
    }
    if(it != m_signals.end())
    {
        return it->second;
    }
}
