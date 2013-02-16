#include <Systems/Render.h>

namespace System 
{
    Render::Render(artemis::World *world, sf::RenderTarget *target)
    {
        m_world = world;
        m_renderTarget = target;
        addComponentType<Component:Graphics>();
    }
    Render::initialize()
    {
        m_graphicsMapper.init(*m_world);
    }
    Render::processEntity(artemis::Entity &e)
    {
        m_graphicsMapper.get(e)->draw(m_target*);
    }
}
