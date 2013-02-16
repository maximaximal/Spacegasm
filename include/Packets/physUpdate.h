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

sf::Packet& operator <<(sf::Packet& p, const Packet::physUpdate& u)
{
    p << u.entityID;
    p << u.pos.x;
    p << u.pos.y;
    p << u.velocity.x;
    p << u.velocity.y;
    p << u.angVelocity;
    p << u.angle;
}
sf::Packet& operator >>(sf::Packet& p, Packet::physUpdate& u)
{
    p >> u.entityID;
    p >> u.pos.x;
    p >> u.pos.y;
    p >> u.velocity.x;
    p >> u.velocity.y;
    p >> u.angVelocity;
    p >> u.angle;
}
