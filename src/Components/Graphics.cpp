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
