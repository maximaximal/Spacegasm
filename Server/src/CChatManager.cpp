#include "CChatManager.h"

#include <CPacketHandler.h>
#include <string>
#include <iostream>
#include <sigc++/sigc++.h>
#include <CPacketSender.h>

using namespace std;

CChatManager::CChatManager(CPacketSender *sender, CPacketHandler *packetHandler, CPlayerManager *playerManager)
{
    m_packetHandler = packetHandler;
    m_packetHandler->getEvent(PTYPE_MSG).connect(sigc::mem_fun(this, &CChatManager::handleChatPacket));
    m_packetSender = sender;
    m_playerManager = playerManager;
}

CChatManager::~CChatManager()
{
    m_eventConnection.disconnect();
}

void CChatManager::handleChatPacket(sf::Packet packet, ENetPeer *peer)
{
    string msg, output;
    packet >> msg;
    output += m_playerManager->getPlayer(peer)->getName();
    output += " >> ";
    output += msg;
    output += "\n";
    cout << "[CHAT] " << output;
    sf::Packet consoleOutput;
    consoleOutput << PTYPE_CONSOLE_OUTPUT << output;
    m_packetSender->sendPacket(consoleOutput, "", 0, 1);
}
