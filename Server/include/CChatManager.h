#ifndef CCHATMANAGER_H
#define CCHATMANAGER_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <SFML/Network.hpp>
#include <sigc++/sigc++.h>
#include <enet/enet.h>
#include <CPacketSender.h>
#include <CPlayerManager.h>

class CPacketHandler;
class CServer;

class CChatManager
{
    public:
        CChatManager(CPacketSender *sender, CPacketHandler *packetHandler, CPlayerManager *playerManager, CServer *server);
        virtual ~CChatManager();
        void handleChatPacket(sf::Packet packet, ENetPeer *peer);
    protected:
    private:
        sigc::connection m_eventConnection;
        CPacketSender *m_packetSender;
        CPacketHandler *m_packetHandler;
        CPlayerManager *m_playerManager;
        CServer *m_server;
};

#endif // CCHATMANAGER_H
