#include <CContactListener.h>

//Artemis
#include <Entity.h>
#include <Components/Physics.h>

//SFML-Network
#include <SFML/Network.hpp>

//PhyUpdate Packet
#include <Packets/physUpdate.h>

CContactListener::CContactListener()
{

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
    artemis::Entity *entityA = static_cast<artemis::Entity*>(dataA);
    artemis::Entity *entityB = static_cast<artemis::Entity*>(dataB);

    static_cast<Component::Physics*>(entityA->getComponent<Component::Physics>())->setDirty(true);
    static_cast<Component::Physics*>(entityB->getComponent<Component::Physics>())->setDirty(true); 
}
void CContactListener::EndContact(b2Contact *contact)
{

}
