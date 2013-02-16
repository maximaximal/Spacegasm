#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <mutex>

#include <Component.h>
#include <SFML/Graphics.hpp>

namespace Component
{
    class Graphics : public artemis::Component
    {
        public:
            Graphics(std::string texture, std::string textureRect = "", unsigned int textureNumber = 0);
            virtual ~Graphics();

            void draw(sf::RenderTarget &target, sf::RenderStates states);

            void setTexture(std::string texture, std::string textureRect = "", unsigned int textureNumber = 0);
            void setTextureRect(std::string textureRect, unsigned int textureNumber = 0);
            void setPosition(sf::Vector2f pos);
            void setPosition(float x, float y) {setPosition(sf::Vector2f(x, y));}
            void setRotation(float angle);
            void setOrigin(sf::Vector2f origin);
            void setOrigin(float x, float y) {setOrigin(sf::Vector2f(x, y));}
            void setColor(sf::Color color);
            void setScale(sf::Vector2f scale);

            sf::Vector2f getPosition();
            sf::Vector2f getOrigin();
            sf::Color getColor();
            sf::Vector2f getScale();
            float getRotation();
        protected:
        private:
            sf::Sprite *m_sprite;
            std::mutex m_spriteMutex;
            std::string m_texture;
    };
}


#endif // GRAPHICS_H
