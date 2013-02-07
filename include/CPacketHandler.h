#ifndef CPACKETHANDLER_H
#define CPACKETHANDLER_H

#include <SFML/Network.hpp>
#include <map>
#include <sigc++/sigc++.h>
#include <enet/enet.h>
#include <CPacketSender.h>

enum {
    PTYPE_MSG,
    PTYPE_CONSOLE_OUTPUT,
    PTYPE_FULLCONNECT
};

class CPacketHandler
{
    public:
        CPacketHandler();
        virtual ~CPacketHandler();
        void setSender(CPacketSender *sender);
        void sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable);
        void handlePacket(sf::Packet packet, ENetPeer *peer);
        sigc::signal<void, sf::Packet , ENetPeer*>& getEvent(unsigned int type);
    protected:
    private:
        CPacketSender *m_sender;
        std::map<unsigned int, sigc::signal<void, sf::Packet , ENetPeer*> > m_signals;
};

#endif // CPACKETHANDLER_H
