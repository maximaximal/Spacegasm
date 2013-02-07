#ifndef CPACKETSENDER_H
#define CPACKETSENDER_H

#include <SFML/Network.hpp>
#include <string>

class CPacketSender
{
    public:
        CPacketSender() {}
        virtual ~CPacketSender() {}
        virtual void sendPacket(sf::Packet& packet, std::string username, unsigned int channel, bool relieable) = 0;
    protected:
    private:
};

#endif // CPACKETSENDER_H
