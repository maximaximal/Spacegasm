#include <System.h>
#include <World.h>

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
            artemis::ComponentMapper<Component::Graphics> m_graphicsComponent;
            artemis::World *m_world;
            sf::RenderTarget *m_target;
    };
}
