#ifndef PACKET_PHYSUPDATE_H
#define PACKET_PHYSUPDATE_H

#include <SFML/Network.hpp>
#include <Box2D/Box2D.h>

namespace Packet
{
    class physUpdate
    {
        public:
            int entityID;
            b2Vec2 pos;
            b2Vec2 velocity;
            float angVelocity;
            float angle;
    };
}
sf::Packet& operator <<(sf::Packet& p, const Packet::physUpdate& u);
sf::Packet& operator >>(sf::Packet& p, Packet::physUpdate& u);

#endif
