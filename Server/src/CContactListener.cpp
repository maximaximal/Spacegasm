#include <CContactListener.h>

//Artemis
#include <Entity.h>

//SFML-Network
#include <SFML/Network.hpp>

//PhyUpdate Packet
#include <Packets/physUpdate.h>

CContactListener::CContactListener()
{
    //Nothing to do...
}

CContactListener::~CContactListener()
{
    //Nothing to do...
}


void CContactListener::BeginContact(b2Contact *contact)
{
    //Get the 2 fixtures of this collision
    b2Fixture *fixtureA = contact->GetFixtureA();
    b2Fixture *fixtureB = contact->GetFixtureB();

    //Get the 2 bodies from the 2 fixtures
    b2Body *bodyA = fixtureA->GetBody();
    b2Body *bodyB = fixtureB->GetBody();

    //Get the userdata from the bodies
    void *dataA = bodyA->GetUserData();
    void *dataB = bodyB->GetUserData();

    //Cast the void pointers of the userdata to entity-pointers.
    Entity *entityA = static_cast<Entity*>(dataA);
    Entity *entityB = static_cast<Entity*>(dataB);

    sf::Packet physUpdate;
    Packet::physUpdate phys;

    //Set physUpdate for BodyA
    phys.pos = bodyA->GetPosition();
    phys.velocity = bodyA->GetLinearVelocity();
    phys.angle = bodyA->GetAngle();
    phys.angVelocity = bodyA->GetAngularVelocity();
    phys.entityID = entityA->getId();
    //Send Update for BodyA
    physUpdate << phys;
    m_packetSender->sendPacket(physUpdate, "", 1, false);

    physUpdate.clear();

    //Set physUpdate for BodyB
    phys.pos = bodyB->GetPosition();
    phys.velocity = bodyB->GetLinearVelocity();
    phys.angle = bodyB->GetAngle();
    phys.angVelocity = bodyB->GetAngularVelocity();
    phys.entityID = entityB->getId();
    //Send Update for BodyB
    physUpdate << phys;
    m_packetSender->sendPacket(physUpdate, "", 1, false);
}
void CContactListener::EndContact(b2Contact *contact)
{

}
