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
bool Physics::isDirty()
{
    m_dirtyMutex.lock();
    bool dirty = m_dirty;
    m_dirtyMutex.unlock();
    return dirty;
}
void Physics::setDirty(bool dirty)
{
    m_dirtyMutex.lock();
    m_dirty = dirty;
    m_dirtyMutex.unlock();
}
