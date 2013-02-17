#ifndef SYSTEM_RENDER_H
#define SYSTEM_RENDER_H

#include <EntityProcessingSystem.h>
#include <World.h>
#include <ComponentMapper.h>
#include <Components/Graphics.h>

namespace System
{
    class Render : public artemis::EntityProcessingSystem
    {
        public:
            Render(artemis::World *world, sf::RenderTarget *target);
            virtual void initialize();
            virtual void processEntity(artemis::Entity &e);
        private:
            artemis::ComponentMapper<Component::Graphics> m_graphicsMapper;
            artemis::World *m_world;
            sf::RenderTarget *m_target;
    };
}

#endif
