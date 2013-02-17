#include <Systems/Render.h>

namespace System
{
    Render::Render(artemis::World *world, sf::RenderTarget *target)
    {
        m_world = world;
        m_target = target;
        addComponentType<Component::Graphics>();
    }
    void Render::initialize()
    {
        m_graphicsMapper.init(*m_world);
    }
    void Render::processEntity(artemis::Entity &e)
    {
        m_graphicsMapper.get(e)->draw(*m_target, sf::RenderStates::Default);
    }
}
