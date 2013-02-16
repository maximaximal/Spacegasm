#ifndef CPLAYERMANAGER_H
#define CPLAYERMANAGER_H

#include <string>
#include <map>
#include <memory>
#include <vector>

#include <CPlayerData.h>
#include <SFML/Network.hpp>
#include <sigc++/sigc++.h>
#include <CPacketHandler.h>

class CPlayerManager
{
    public:
        CPlayerManager(CPacketHandler *packetHandler);
        virtual ~CPlayerManager();
        CPlayerData* getPlayer(std::string username);
        CPlayerData* getPlayer(ENetPeer *peer);
        void addPlayer(std::string username, ENetPeer *peer);
        void removePlayer(std::string username);
        void removePlayer(ENetPeer *peer);
        void playerConnectHandler(sf::Packet packet, ENetPeer *peer);
        
        std::vector<std::string> onScreen(sf::FloatRect rect);
    protected:
    private:
        std::map<std::string, std::shared_ptr<CPlayerData> > m_players;
        std::map<ENetPeer*, std::string> m_peers;
        CPacketHandler *m_packetHandler;
        sigc::connection m_playerConnect;
};

#endif // CPLAYERMANAGER_H
