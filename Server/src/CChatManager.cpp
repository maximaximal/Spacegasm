#include "CChatManager.h"

#include <CPacketHandler.h>
#include <string>
#include <iostream>
#include <sigc++/sigc++.h>
#include <CPacketSender.h>
#include <CServer.h>
using namespace std;

CChatManager::CChatManager(CPacketSender *sender, CPacketHandler *packetHandler, CPlayerManager *playerManager, CServer *server)
{
    m_packetHandler = packetHandler;
    m_packetHandler->getEvent(PTYPE_MSG).connect(sigc::mem_fun(this, &CChatManager::handleChatPacket));
    m_packetSender = sender;
    m_playerManager = playerManager;
    m_server = server;
}

CChatManager::~CChatManager()
{
    m_eventConnection.disconnect();
}

void CChatManager::handleChatPacket(sf::Packet packet, ENetPeer *peer)
{
    string msg, output;
    packet >> msg;
    if(msg.substr(0, 1) == "/")
    {
        if(msg == "/stop")
            m_server->stop();
    }
    else
    {
        output += m_playerManager->getPlayer(peer)->getName();
        output += " >> ";
        output += msg;
        output += "\n";
        cout << "[CHAT] " << output;
        sf::Packet consoleOutput;
        consoleOutput << PTYPE_CONSOLE_OUTPUT << output;
        m_packetSender->sendPacket(consoleOutput, "", 0, 1);
    }
}
