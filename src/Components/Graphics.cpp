#include "Components/Graphics.h"
#include <CTextureManager.h>

using namespace Component;

Graphics::Graphics(std::string texture, std::string textureRect = "", unsigned int textureNumber = 0)
{
    m_texture = texture;
    m_sprite = new sf::Sprite();
    if(CTextureManager::Get()->getTexture(texture) != NULL)
    {
        m_sprite->setTexture(CTextureManager::Get()->getTexture(texture));
        m_sprite->setTextureRect(CTextureManager::getRect(texture, textureRect, textureNumber));
    }
    else
    {
        CTextureManager::addSprite(texture, m_sprite, textureRect, textureNumber);
    }
}

Graphics::~Graphics()
{
    delete m_sprite;
}

void Graphics::setTexture(std::string texture, std::string textureRect = "", unsigned int textureNumber = 0)
{
    m_texture = texture;
    if(CTextureManager::Get()->getTexture(texture) != NULL)
    {
        m_sprite->setTexture(CTextureManager::Get()->getTexture(texture));
        m_sprite->setTextureRect(CTextureManager::getRect(texture, textureRect, textureNumber));
    }
    else
    {
        CTextureManager::addSprite(texture, m_sprite, textureRect, textureNumber);
    }
}
void Graphics::setTextureRect(std::string textureRect, unsigned int textureNumber = 0)
{
    m_sprite->setTextureRect(CTextureManager::getRect(texture, textureRect, textureNumber));
}
