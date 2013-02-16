#include "Components/Graphics.h"
#include <CTextureManager.h>

using namespace Component;

Graphics::Graphics(std::string texture, std::string textureRect, unsigned int textureNumber)
{
    m_texture = texture;
    m_sprite = new sf::Sprite();
    m_sprite->setTexture(CTextureManager::Get()->getTexture(texture));
    m_sprite->setTextureRect(CTextureManager::Get()->getRect(texture, textureRect, textureNumber));
}

Graphics::~Graphics()
{
    delete m_sprite;
}

void Graphics::setTexture(std::string texture, std::string textureRect, unsigned int textureNumber)
{
    m_texture = texture;
    m_sprite->setTexture(CTextureManager::Get()->getTexture(texture));
    m_sprite->setTextureRect(CTextureManager::Get()->getRect(texture, textureRect, textureNumber));
}
void Graphics::setTextureRect(std::string textureRect, unsigned int textureNumber)
{
    m_sprite->setTextureRect(CTextureManager::Get()->getRect(m_texture, textureRect, textureNumber));
}
void Graphics::setPosition(sf::Vector2f pos)
{
    m_sprite->setPosition(pos);
}
void Graphics::setOrigin(sf::Vector2f origin)
{
    m_sprite->setOrigin(origin);
}
void Graphics::setRotation(float rotation)
{
    m_sprite->setRotation(rotation);
}
void Graphics::setScale(sf::Vector2f scale)
{
    m_sprite->setScale(scale);
}
sf::Vector2f Graphics::getPosition()
{
    return m_sprite->getPosition();
}
sf::Vector2f Graphics::getOrigin()
{
    return m_sprite->getOrigin();
}
sf::Color Graphics::getColor()
{
    return m_sprite->getColor();
}
sf::Vector2f Graphics::getScale()
{
    return m_sprite->getScale();
}
float Graphics::getRotation()
{
    return m_sprite->getRotation();
}
