#include "Components/Physics.h"

using namespace Component;

Physics::Physics(b2BodyDef *bodydef, b2World *world)
{
    m_world = world;
    m_body = world->CreateBody(bodydef);
}

Physics::~Physics()
{
    m_world->DestroyBody(m_body);
}

b2Body* Physics::getBody()
{
    return m_body;
}
