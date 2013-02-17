#include <Packets/physUpdate.h>

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
